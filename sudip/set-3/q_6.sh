echo "give folder path"
read f_path

if [ ! -d "$f_path" ]; then
	echo "wrong path"
	exit 1
fi

cd "$f_path" || exit 1

ls *.sh

cnt=`ls *.sh | wc -l`
echo "number of shell scripts: $cnt"
