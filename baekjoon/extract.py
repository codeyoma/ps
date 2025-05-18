
import sys
import os
import re

if len(sys.argv) != 2:
    print("Usage: python extract.py <filenumber>")
    sys.exit(1)

# 추출 대상 파일 경로
file_number = sys.argv[1]
file_path = os.path.join(file_number, f"{file_number}.cpp")
output_path = os.path.join(file_number, f"{file_number}.md")

# 구간 시작과 끝을 식별하는 고유 문자열
start_marker = r" \*------------------------------------------------------------------------------\n \*/\n"
end_marker = r"/\*\*\n \*------------------------------------------------------------------------------\n \*  /..*"

# 파일 전체 읽기
with open(file_path, 'r', encoding='utf-8') as f:
    content = f.read()

# 시작 위치 찾기
start_match = re.search(start_marker, content)
end_match = re.search(end_marker, content)

code_between = ""

if start_match and end_match:
    start_index = start_match.end()
    end_index = end_match.start()
    code_between = content[start_index:end_index]
else:
    print("Markers not found.")

with open(output_path, 'r', encoding='utf-8') as f:
    md_lines = []
    for line in f:
        md_lines.append(line)
        if line.strip().lower() == "# my code":
            break  # 여기서 멈춤

md_lines.append(f"\n```cpp title=\"boj/{file_number}.cpp\"\n")
md_lines.append(code_between + "\n")
md_lines.append("```\n")

with open(output_path, 'w', encoding='utf-8') as f:
	f.writelines(md_lines)

