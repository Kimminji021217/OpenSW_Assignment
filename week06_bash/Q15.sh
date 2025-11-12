#! /bin/bash

file_wordcnt() {
    read -p "Enter a file name: " file
    echo "$file 파일의 단어는 $(wc -w < "$file") 개 입니다."
}

file_wordcnt
