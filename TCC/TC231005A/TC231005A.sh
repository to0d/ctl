#/bin/sh

objdump -d hello.a > hello.txt
objdump -d hello_pg.a > hello_pg.txt

./hello_pg.a
gprof hello_pg.a > report.txt

echo "output: done!"