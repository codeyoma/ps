#!/bin/bash

set -e

url_number=$1
url="https://www.acmicpc.net/problem/$url_number"

insert_boj_level() {
    local problem_id=$url_number
    local md_path="$problem_id/$problem_id.md"
    local api_url="https://solved.ac/api/v3/problem/show?problemId=$problem_id"

    local response=$(curl -s --request GET \
        --url "$api_url" \
        --header 'Accept: application/json' \
        --header 'x-solvedac-language: ko')

    local level=$(echo "$response" | jq -r '.level')

    sed -i '' "2i\\
boj-level: $level
" "$md_path"
}

copy_template_md() {
    cp template.md "$url_number/$url_number.md"
}

insert_boj_url() {
    sed -i '' "5i\\
- [$url]($url)
" $url_number/$url_number.md
}

if [ ! -e "$url_number/$url_number.md" ]; then
    copy_template_md
    insert_boj_url
    insert_boj_level

fi

python3 extract.py $url_number
