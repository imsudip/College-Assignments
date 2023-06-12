#!/bin/bash
echo -n -e "Enter the Basic Salary $base\n"
read base
da=`bc <<< "$base * 0.04"`
hra=`bc <<< "$base * 0.1" `
total=`bc <<< "$base + $da + $hra"`

echo -e "Total Salary: $total \t DA: $da \t HRA: $hra"