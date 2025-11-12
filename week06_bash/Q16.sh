#! /bin/bash

file_wordcnt() {
   
    read -p "Enter a file name: " file
    if [ -e "$file" ]; then
        echo "$file 파일의 단어는 $(wc -w < "$file") 개 입니다."
    else
        echo "$file 파일이 존재하지 않습니다."
        return 1
    fi
}

file_wordcnt
