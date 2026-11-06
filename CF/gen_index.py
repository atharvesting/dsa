#!/usr/bin/env python3
"""Refresh CF/INDEX.md from each solution's @METADATA block."""

import re
from pathlib import Path

CF = Path(__file__).resolve().parent
FIELDS = ("Date", "Problem", "Link", "Source", "Pattern", "Type")
SECTIONS = ("cp-31", "contest", "solve", "reattempt")
NAMES = {
    "cp-31": "CP-31",
    "contest": "Contest",
    "solve": "Solve",
    "reattempt": "Reattempt",
}
ORDER = {"cp-31": 0, "contest": 1, "solve": 2, "reattempt": 3}


def read_meta(path: Path) -> dict[str, str]:
    text = path.read_text(errors="replace")
    meta = {}
    for field in FIELDS:
        match = re.search(rf"(?m)^{field}:[ \t]*(.*)$", text)
        meta[field] = match.group(1).strip() if match else ""
    return meta


def natural_key(value: str):
    return tuple(int(part) if part.isdigit() else part.lower()
                 for part in re.split(r"(\d+)", value))


def path_key(path: Path):
    return tuple((ORDER.get(part, 10), natural_key(part)) for part in path.parts)


def sort_key(path: Path):
    match = re.match(r"([A-Za-z]*)(\d+)([A-Za-z]?)", path.name)
    if not match:
        return ("", 10**9, "", path.name)
    return (match.group(1), int(match.group(2)), match.group(3), path.name)


def section_title(relative: Path) -> str:
    return " / ".join(NAMES.get(part, part) for part in relative.parts)


def main() -> None:
    lines = [
        "# CF Problem Index",
        "",
        "Generated from each file's `@METADATA` block. `—` means the field is missing.",
        "",
    ]

    for section in SECTIONS:
        base = CF / section
        if not base.is_dir():
            continue

        groups: dict[Path, list[Path]] = {}
        for path in base.rglob("*.hpp"):
            groups.setdefault(path.parent.relative_to(CF), []).append(path)

        for relative in sorted(groups, key=path_key):
            files = sorted(groups[relative], key=sort_key)
            lines.append(f"## {section_title(relative)} ({len(files)})")
            lines.append("")
            lines.append("| Problem | Type | Pattern | Date | File |")
            lines.append("|---|---|---|---|---|")
            for path in files:
                meta = read_meta(path)
                problem = meta["Problem"] or path.stem
                if meta["Link"]:
                    problem = f"[{problem}]({meta['Link']})"
                row = [
                    problem,
                    meta["Type"] or "—",
                    meta["Pattern"] or "—",
                    meta["Date"] or "—",
                    f"[{path.name}]({relative.as_posix()}/{path.name})",
                ]
                lines.append("| " + " | ".join(row) + " |")
            lines.append("")

    (CF / "INDEX.md").write_text("\n".join(lines))
    print("[index] updated CF/INDEX.md")


if __name__ == "__main__":
    main()
