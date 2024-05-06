# if else

# if [ $# -gt 2 ]; then

#         echo "More than 2 arguments were passed."
    
#     else

#             echo "Fewer than 2 argument have passed."
# fi


# echo "Enter the first number"
# read num1
# echo "Enter the second number"
# read num2
# echo "Enter the third number"
# read num3

# if [ $num1 -gt $num2 ] && [ $num1 -gt $num3 ]; then
    
#     echo "The num 1 is greater $num1"

# elif [ $num2 -gt $num1 ] && [ $num2 -gt $num3 ]; then

#     echo "The num 2 is greater $num"

# else 

#     echo "The num 3 is greater $num3"

# fi


#switch case

# echo "Enter any number"
# read num

# case $num in

# 1) echo "Enter a number" 
#     read num1
#     echo "the number you entered is $num1";;
# 2) echo "jan2";;
# 3) echo "jan3";;
# 4) echo "jan4";;
# 5) echo "jan5";;
# 6) echo "jan6";;

# *) echo "invalid input"

# esac

#for loop

echo "Enter the number of terms: "
read n

a=0
b=1

echo "Fibonacci series: "

for ((i=0; i<n; i++))
do
    echo -n "$a "
    fn=$((a+b))
    a=$b
    b=$fn
done

echo ""