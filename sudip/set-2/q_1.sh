main() {
	echo "give folder path"
	read f_path

	if [ ! -d "$f_path" ]; then
		echo "wrong path"
		exit 1
	fi

	cd "$f_path" || exit 1
	line=`ls -F`
	#echo $line

	for i in `echo $line`
	do
		echo -n $i
		length=`echo $i | wc -c`
		length=`expr $length - 1`
		#echo $length
		c=`echo $i | cut -c $length`
		if [ $c == "/" ]
			then
				echo -n " -> "
				echo "Directory"
			else
				echo -n " -> "
				echo "File"
		fi
	done
}

main > out_q_1.txt
cat out_q_1.txt
