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

load_dotenv()  # Loading API key variable from .env file for security
api_key = os.getenv("GEMINI_API_KEY")
client = genai.Client(api_key=api_key)

prompt="""

"""

response = client.models.generate_content(
    model="gemini-2.5-flash",
    contents=prompt
)

print(response.text)

# for model in client.models.list():
#     print(model.name)