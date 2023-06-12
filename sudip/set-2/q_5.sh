
main(){
	echo "give folder path"
	read path
	if [ ! -d "$path" ]; then
		echo "wrong path"
		exit 1
	fi

	for dir in "$path"/*;
		do
			if [ -d "$dir" ]; 
			then
				echo "Directory name: $dir"
				b=$(du -bs $dir | tail -n1 | awk '{print $1}')
				kbs=$(($b / 1024))
				mb=$(($b / 1048576))
				echo "Size in bytes: $b"
				echo "Size in KB: $kbs"
				echo "Size in MB: $mb"
				echo "--------------"
			fi
		done
}
main
