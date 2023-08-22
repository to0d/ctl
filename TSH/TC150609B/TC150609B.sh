#!/bin/sh
#####################################################


echo "-------------------------------------------"
echo "Command Useage: expr"
echo ""

Index=0

while [ $Index -lt 3 ];
do
    echo Index=$Index
    Index=`expr $Index + 1`
done

echo "-------------------------------------------"

echo "output: done."