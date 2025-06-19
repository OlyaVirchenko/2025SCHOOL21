#!/bin/bash

cd ..

echo Напиши путь до файла
read filepath
if [ -f "$filepath" ]; then
    allrecords=$(wc -l < "$filepath")

    uniq_file=$(cut -d'-' -f1 $filepath | uniq -c | wc -l)

    allchanges=$(($allrecords - uniq_file))

    echo "$allrecords $uniq_file $allchanges"
else 
    echo "Файла не существует"
fi
