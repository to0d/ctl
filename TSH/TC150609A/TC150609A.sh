#!/bin/sh
#####################################################

SRC1=regex-test-01.txt
Index=0

echo "-----------------TEST REGEX-------------------------"
echo "-----Source File #1:"$SRC1"------"
echo "Source File":
cat $SRC1
echo ""


echo "-------------------------------------------"
Index=`expr $Index + 1`
echo $Index":^                       ===> Line Head" 
echo "Regex : grep '^a'"
echo "Expect: atest" 
echo -e "Actual: \c" 
cat $SRC1 | grep '^a'
echo ""

echo "-------------------------------------------"
Index=`expr $Index + 1`
echo $Index":$                       ===> Line Tail" 
echo "Regex : grep 'xx$'"
echo "Expect: testxx" 
echo -e "Actual: \c" 
cat $SRC1 | grep 'xx$'
echo ""

echo "-------------------------------------------"
Index=`expr $Index + 1`
echo $Index":.                       ===> Any single character" 
echo "Regex : grep 'test.$'"
echo "Expect: testx" 
echo -e "Actual: \c" 
cat $SRC1 | grep 'test.$'
echo ""

echo "-------------------------------------------"
Index=`expr $Index + 1`
echo $Index":*                       ===> >=0 time" 
echo "Regex : grep 'testxxx*'"
echo "Expect: testxx" 
echo -e "Actual: \c" 
cat $SRC1 | grep 'testxxx*'
echo ""


echo "-------------------------------------------"
Index=`expr $Index + 1`
echo $Index":*                       ===> >=1 time, not support grep, support awk" 
echo "Regex : grep '^test' | awk '/xx+/'"
echo "Expect: testxx" 
echo -e "Actual: \c" 
cat $SRC1 | grep '^test' | awk '/xx+/'
echo ""

echo "-------------------------------------------"
Index=`expr $Index + 1`
echo $Index":\                       ===> Escape String \\$ \\. \\^" 
echo "a. Regex : grep '^\$'"
echo "   Expect: \$test" 
echo -e "   Actual: \c" 
cat $SRC1 | grep '^\$'
echo ""

echo "b. Regex : grep '^\.'"
echo "   Expect: .test" 
echo -e "   Actual: \c" 
cat $SRC1 | grep '^\.'
echo ""

echo "c. Regex : grep '^\^'"
echo "   Expect: ^test" 
echo -e "   Actual: \c" 
cat $SRC1 | grep '^\^'
echo ""

echo "-------------------------------------------"
Index=`expr $Index + 1`
echo $Index":[]                       ===> single character/character sequence" 
echo "a. Regex : grep '^xx[0-9]'"
echo "   Expect: xx123yyy" 
echo -e "   Actual: \c" 
cat $SRC1 | grep '^xx[0-9]'
echo ""

echo "-------------------------------------------"
Index=`expr $Index + 1`
echo $Index":Pattern \{n\}              ===> n times" 
echo  " :Pattern \{n,\}                 ===> >=n times"
echo  " :Pattern \{n,m\}                ===> n~m times"
echo "a. Regex : grep '^xx[0-9]\{2,\}'"
echo "   Expect: xx123yyy" 
echo -e "   Actual: \c" 
cat $SRC1 | grep '^xx[0-9]\{2,\}'
echo ""

echo "-------------------------------------------"
Index=`expr $Index + 1`
echo $Index":(?p1|p2)              ===> grep expend mode or" 
echo  " :Pattern \{n,\}            ===> >=n times"
echo  " :Pattern \{n,m\}           ===> n~m times" 
echo "a. Regex : grep -E 'te(?s|x)tx$'"
echo "   Expect: testx textx" 
echo -e "   Actual: \c" 
cat $SRC1 | grep -E 'te(?s|x)tx$' | xargs 
echo ""

echo "-----------------Special Regex -------------------------"
Index=0

echo "-------------------------------------------"
Index=`expr $Index + 1`
echo $Index":               ===> Get Ip" 
echo "a. Regex : ifconfig | grep 'inet addr' | grep -v '127.0.0.1' | awk '{ print $2}' | cut -c5-"
echo -e "   Actual: \c" 
ifconfig | grep 'inet addr' | grep -v '127.0.0.1' | awk '{ print $2}' | cut -c5-

echo "b. Regex : ifconfig | grep 'inet addr' | grep -v '127.0.0.1' | awk -F: '{print $2}' | awk '{print $1}'"
echo -e "   Actual: \c" 
ifconfig | grep 'inet addr' | grep -v '127.0.0.1' | awk -F: '{print $2}' | awk '{print $1}'

echo "c. Regex : ifconfig | grep 'inet addr' | grep -v '127.0.0.1' | cut -d: -f2  | awk '{print $1}'"
echo -e "   Actual: \c" 
ifconfig | grep 'inet addr' | grep -v '127.0.0.1' | cut -d: -f2  | awk '{print $1}'

echo ""


echo "-----------------TEST Issues-------------------------"
echo ""
Index=0

echo "-------------------------------------------"
Index=`expr $Index + 1`
echo $Index":?                       ===> 0 or 1 time"
echo "Regex : grep 'testxxx*'"
echo "Expect: testxx" 
echo -e "Actual: \c" 
cat $SRC1 | grep 'testx?'
echo ""

echo "output: done."