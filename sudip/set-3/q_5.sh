echo "give folder path"
read f_path

if [ ! -d "$f_path" ]; then
	echo "wrong path"
	exit 1
fi

cd "$f_path" || exit 1

for file in *.sh
do
	mv -- "$file" "${file%.sh}.exe"
	echo "renamed $file --> $file.exe"
done
