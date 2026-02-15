#!/usr/bin/env python3
import sys
import shutil
from datetime import datetime
from pathlib import Path


PLATFORMS = {
    'cf':   ('codeforces.cpp', 'Codeforces'),
    'atc':  ('atcoder.cpp',    'AtCoder'),
    'ac':   ('atcoder.cpp',    'AtCoder'),
    'cses': ('cses.cpp',       'CSES'),
    'lc':   ('leetcode.cpp',   'LeetCode'),
    'misc': ('misc.cpp',       'Misc'),
    'icpc': ('icpc.cpp',       'ICPC'),
    'euler':('euler.cpp',      'Project-Euler'),
    'usaco':('usaco.cpp',      'USACO'),
}

# Resolve everything relative to the script so calls from any working dir behave the same.
BASE_DIR = Path(__file__).resolve().parent
ROOT_DIR = BASE_DIR.parent


def split_problem_id(pid: str):
    i = 0
    while i < len(pid) and pid[i].isdigit():
        i += 1
    num = pid[:i]
    tail = pid[i:]
    return (num if num else None, tail if tail else None)


def usage():
    print('Usage: python3 archive.py <platform> <problem_id> [topics...]', file=sys.stderr)
    print('Platforms: cf, atc, cses, lc, misc, icpc, euler, usaco', file=sys.stderr)
    sys.exit(1)


def main():
    if len(sys.argv) < 3:
        usage()

    platform = sys.argv[1].lower()
    problem_id = sys.argv[2]
    topics = sys.argv[3:]

    if platform not in PLATFORMS:
        print(f'Unknown platform: {platform}', file=sys.stderr)
        usage()

    src_name, plat_name = PLATFORMS[platform]
    src_file = BASE_DIR / src_name

    archive_candidates = [
        ROOT_DIR / 'archives',
        ROOT_DIR / 'Archives',
        BASE_DIR / 'archives',
        BASE_DIR / 'Archives',
    ]
    for candidate in archive_candidates:
        if candidate.is_dir():
            archive_root = candidate
            break
    else:
        archive_root = archive_candidates[0]

    archive_root.mkdir(parents=True, exist_ok=True)
    plat_folder = plat_name.lower()
    if not src_file.is_file():
        print(f'Source file not found: {src_file}', file=sys.stderr)
        sys.exit(1)

    # Determine destination for the main archive copy (platform-specific rules)
    num, tail = split_problem_id(problem_id)
    if platform == 'cf':
        # Codeforces: split leading number vs trailing letter(s)
        if num:
            dest_dir = archive_root / plat_folder / num
            dest_name = f'{tail or problem_id}.cpp'
        else:
            dest_dir = archive_root / plat_folder
            dest_name = f'{problem_id}.cpp'
    elif platform in ('atc', 'ac'):
        # AtCoder: split trailing letter(s) from base (e.g., abc300C -> abc300/C.cpp)
        s = problem_id
        i = len(s) - 1
        while i >= 0 and s[i].isalpha():
            i -= 1
        if i < len(s) - 1:
            base = s[:i+1]
            # Trim a trailing separator if present (e.g., abc300_C)
            while base and not base[-1].isalnum():
                base = base[:-1]
            letter = s[i+1:]
            dest_dir = archive_root / plat_folder / (base.lower() if base else base)
            dest_name = f'{letter}.cpp'
        else:
            dest_dir = archive_root / plat_folder
            dest_name = f'{problem_id}.cpp'
    elif platform in ('cses', 'lc', 'misc', 'icpc', 'euler', 'usaco'):
        # Direct-copy platforms: keep problem ID as filename
        dest_dir = archive_root / plat_folder
        dest_name = f'{problem_id}.cpp'
    else:
        # Fallback (shouldn't happen due to earlier check)
        dest_dir = archive_root / plat_folder
        dest_name = f'{problem_id}.cpp'

    dest_path = dest_dir / dest_name
    dest_path.parent.mkdir(parents=True, exist_ok=True)
    shutil.copyfile(src_file, dest_path)

    # Topic copies (flat structure using problem_id)
    for t in topics:
        topic_dir = archive_root / 'topics' / Path(t.lower())
        topic_target = topic_dir / f'{platform}_{problem_id}.cpp'
        topic_target.parent.mkdir(parents=True, exist_ok=True)
        shutil.copyfile(src_file, topic_target)

    # Logging
    log_path = archive_root / 'log.csv'
    first_time = not log_path.exists()
    ts = datetime.now().isoformat(timespec='seconds')
    topics_str = ' '.join(topics)
    try:
        with open(log_path, 'a' if not first_time else 'w', encoding='utf-8') as f:
            if first_time:
                f.write('timestamp,platform,problem,topics\n')
            f.write(f'{ts},{platform},{problem_id},{topics_str}\n')
    except OSError as e:
        print(f'Failed to write log: {e}', file=sys.stderr)


if __name__ == '__main__':
    main()
