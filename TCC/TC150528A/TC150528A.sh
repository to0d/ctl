#/bin/sh

echo "---------- LEX Content ----------"
cat TC000028.l
echo ""

echo "---------- TEST Content ----------"
cat test.src
echo ""

echo "---------- Parse ----------"
cat test.src | ./x.main.ctl.x
echo ""

echo "output: done!"