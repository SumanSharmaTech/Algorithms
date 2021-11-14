#!/bin/bash

echo -e "Enter number:"
read num

function prime_num
{
for((i=2; i<=num/2; i++))
do
  if [ $((num%i)) -eq 0 ]
  then
    echo -e "$num is not a prime number."
    exit
  fi
done
echo -e "$num is a prime number."

}
r=`prime_num $number`
echo -e "$r"
