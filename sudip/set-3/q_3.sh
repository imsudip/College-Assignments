main() {
	echo "give folder path"
	read f_path

	if [ ! -d "$f_path" ]; then
		echo "wrong path"
		exit 1
	fi

	cd "$f_path" || exit 1
	totalSize=0
	
	for file in *
	do
		if [ -f "$file" ]
		then
			# ls -l "$file"
			size=`ls -l "$file" | awk '{print $5}'`
			echo "$file --> $size"
			totalSize=$(($totalSize + $size))
		fi
	done
	echo "Total number of bytes used by files is: $totalSize"
}

main
