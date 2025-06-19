#!/bin/bash

cd ..

echo Какой путь до файла?
read path_to_file

if [ -f "$path_to_file" ]; then
    echo Какая строка для замены?
    read string_for_change
    echo На что заменить строку?
    read new_string

    sed -i '' "s/${string_for_change}/${new_string}/g" $path_to_file

    size=$(stat -f %z $path_to_file)
    date=$(date -r $path_to_file "+%Y-%m-%d %H:%M")
    shasum=$(shasum -a 256 $path_to_file | cut -d' ' -f1)

    logstring="$path_to_file - $size - $date - $shasum - sha256"

    echo $logstring >> src/files.log

else
    echo "Такого файла не существует"
fi
