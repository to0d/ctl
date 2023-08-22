#!/bin/sh
#####################################################

test_fun()
{
    echo $0 | awk '{ printf("%-8s:=%-12s;","$0",$1) }' 
    echo "Shell script name"

    echo $1 | awk '{ printf("%-8s:=%-12s;","$1",$1) }'
    echo "#1 para"

    echo $? | awk '{ printf("%-8s:=%-12s;","$?",$1) }'
    echo "last statment status"

    echo $# | awk '{ printf("%-8s:=%-12s;","$#",$1) }'
    echo "para count"
    
    echo -e "\$*      :=\c"
    echo -e "$*    ;\c"
    echo "para list"
   
    
    shift
    echo "" | awk '{ printf("%-8s:=%-12s;","shift(N)",$1) }'
    echo "shift(N),para move forward N($2->$1,$3->2,.)"
    
    echo -e "\$@      :=\c"
    echo -e "$@    ;\c"
    echo "para list"  
   
}

echo "test_fun p1 p2 p3"
echo "-------------------------------------"
test_fun p1 p2 p3

echo "output: done."