
main() {
	sum=0
	i=1
	while read -r line
	do
		currSum=0
		a=`echo $line | cut -d ' ' -f 1`
		b=`echo $line | cut -d ' ' -f 2`
		c=`echo $line | cut -d ' ' -f 3`
		currSum=$(($a + $b + $c))
		echo "Sum in line:$i is: $currSum"
		sum=$(($sum + $currSum))
		i=`expr $i + 1`
	done
	echo "Total sum is: $sum"
}
echo "enter file name"
read inputname
if [[ -f "set-3/$inputname" ]]; then
	cat set-3/$inputname
	main < set-3/$inputname > out_q_1.txt
	cat out_q_1.txt
else
	echo "does not exist"
fi

