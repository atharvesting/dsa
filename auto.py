"""
This repository contains source code and documentation for the DSA problems I am working on a daily basis.
In each file, I document my steps, hurdles, observations and learnings for a problem.

Procedure:
1. Get activated on a new push to the repo.
2. Go through all of the header files in the repo.
3. If publish is true and filename is not in published.md, the file contents are sent to a python automation script that processes it and generates
a clean and personalised post for the PW DSA Diary.
4. When the markdown post is generated, another action is triggered that - 
    1. sends this post to a particular folder in the PW repo, which is committed and pushed.
    2. adds filename to published.md.

"""

from google import genai
from google.genai import types
import os
from dotenv import load_dotenv
import pathlib
import re

load_dotenv()  # Loading API key variable from .env file for security

api_key = os.getenv("GEMINI_API_KEY")
if not api_key:
    raise ValueError("API key not found!")

client = genai.Client(api_key=api_key)

system_instruction = """
Identity: You are the student author of a "DSA Diary".
Task: Convert raw, messy, and unformatted C++ source file comments into a polished, professional, text-based blog post.

### Core Rules
1. **No Emojis:** Do not use emojis anywhere in the output.
2. **No Bullet Points:** Write in cohesive paragraphs (prose). Do not use bulleted lists for the "Journey" or "Learnings" sections. Connect ideas with transition words.
3. **Voice:** Use "I", "me", "my". Maintain the author's personal voice but fix grammar, punctuation, and flow.
4. **Formatting:** Use the Markdown Template below strictly.

### Output Template
# {Problem Name}

**Date:** {YYYY-MM-DD}  
**Source:** [{Source Name}]({Link})  
**Difficulty:** {Difficulty}  
**Pattern:** {Pattern}

---

## The Journey
{Content from @JOURNEY: Rewrite raw notes into a smooth narrative paragraph.}

## The Failed Attempt
{If @ITERATION_FAILED exists, insert the code snippet here in a ```cpp``` block}

**Why it failed:**
{Content from 'Why it failed': Rewrite into a descriptive paragraph explaining the logic gap.}

## The Solution
### Final Code
{Insert the actual working C++ code from the bottom of the file in a ```cpp``` block}

**Why it works**
{Content from Why point under @ITERATION_SUCCESS}

**Logic and Complexity:**
{Content from @ITERATION_SUCCESS: Explain the method and complexity (Time/Space) in full sentences.}

## Learnings
{Content from @LEARNINGS: Synthesize the separate points into a single reflective paragraph.}
"""


config = types.GenerateContentConfig(
    system_instruction=system_instruction,
    temperature=0.85
)


def process_file(file_contents: str):
    response = client.models.generate_content(
        model="gemini-2.5-flash",
        contents="Find the file contents below: \n" + file_contents,
        config=config
    )
    return response.text

def iterate_repo():
    root = pathlib.Path(".")
    current_script = pathlib.Path(__file__).name
    for file_path in root.rglob("*.h"):
        if file_path.is_file():
            try:
                with open(file_path.name, "r", encoding="utf-8") as f:
                    file_content = f.read()
                    if not re.search(r'publish:\s*true', file_content, re.IGNORECASE):
                        continue
                
                blog_post = process_file(file_content)
                
                if blog_post:
        
                    with open(f"post_{file_path.stem}.md", "w", encoding="utf-8") as o:
                        o.write(blog_post)
                        
            except Exception as e:
                print(f"Failed to process {file_path.name}: {e}")
                
if __name__ == "__main__":
    iterate_repo()
                

'''system_instruction = """
Identity: Technical Writer.
Tone & Style: Friendly but professional. Take inspiration from my personal writing style from the file contents.
Rules:
- Always output in markdown with appropriate headings and syntax.
- Keep content under 500 words excluding metadata and all code.
- Never use emojis.
- Clear, blog-like structure.

You will be provided the content of a single file which contains:
- Final code for solving a DSA problem.
- Documentation including metadata, journey, failures, successes complexity analyses, and learnings.

File Structure:
METADATA, jOURNEY, ITERATION_FAILED, ITERATION_SUCCESS, LEARNINGS, SOURCE CODE.

You need to structure it properly as a blog that will be part of my personal DSA Diary, public to all.
All necessary content will be provided in the documentation section of the file content. 
No additional information must be sourced or added. Stay true to the source and ensure that my personality shines through, not an LLM's.
"""'''