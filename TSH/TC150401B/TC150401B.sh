#!/bin/sh
#####################################################

XX=$(ls /)
echo "Result: "$XX
echo "It is a list:"
for f in $XX
{ 
   echo "  "$f
}

echo "output: done."