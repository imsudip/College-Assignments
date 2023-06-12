#!/bin/bash
#rm *~

echo "give folder path"
read f_path

if [ ! -d "$f_path" ]; then
	echo "wrong path"
	exit 1
fi

cd "$f_path" || exit 1


for file in $(ls *~);
do 
    echo "Deleted file: $file"
    rm $file
done    
