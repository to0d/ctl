#/bin/sh

echo "---------- LEX Content ----------"
cat example.flex
echo ""

echo "---------- TEST Content ----------"
cat test.src
echo ""

echo "---------- Parse ----------"
cat test.src | ./x.main.ctl.x
echo ""

echo "output: done!"