#/bin/sh

objdump -d hello.a | grep idivl | awk -F : '{print $1}' | xargs addr2line -e hello.a

echo "output: done!"