#! /bin/bash

file_wordcnt() {
    for file in file*.txt; do
        result=$(cat $file | wc -w)
        echo "$file 파일의 단어는 $result 개 입니다."
    done
}

file_wordcnt