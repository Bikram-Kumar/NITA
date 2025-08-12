# Shell script to read a number and ﬁnd whether the number is odd or even
p1 () {
    echo -n "Enter num: "
    read num
    
    if [ $(($num % 2)) -eq 1 ] 
    then
        echo "Odd"
    else
        echo "Even"
    fi
}


# shell program in UNIX to ﬁnd the factorial of a number
p2 () {
    echo -n "Enter num: "
    read num
    fac=1
    for ((i = 2; i <= num; i++))
    do
        fac=$((i * fac))
    done
    echo "$num! = $fac"
}


# shell program to ﬁnd Fibonacci series of a number
p3 () {
    read -p "Enter number of terms: " n
    a=0
    b=1
    echo "Fibonacci series:"
    for ((i=0; i < n; i++)) 
    do
        c=$((a+b))
        echo -n "$a "
        a=$b
        b=$c
    done
    echo
}


# shell program for Fibonacci number of multiple values
p4() {
    read -p "Enter space-separated values: " -a arr
    for n in ${arr[@]}
    do 
        a=0
        b=1
        echo "Fibonacci series $n terms:"
        for ((i=0; i < n; i++)) 
        do
            c=$((a+b))
            echo -n "$a "
            a=$b
            b=$c
        done
        echo
    done
    
}



# shell program for Switch Case in Linux
p5() {
    echo -e "Menu:\n1. Show Date\n2. Show Calendar\n3. Exit"
    read -p "Enter option: " op
    case $op in
    1) date;;
    2) cal;;
    3) exit;;
    *) echo "Invalid option!";;
    esac
}


# shell program for Loops in Shell Scripts
p6() {
    read -p "Enter a number: " n
    echo "Multiplication Table of $n:"
    for ((i=1; i <= 10; i++))
    do
        echo "$n * $i = $((n * i))"
    done
    
}

main() {
    p1
    p2
    p3
    p4
    p5
    p6
}

main