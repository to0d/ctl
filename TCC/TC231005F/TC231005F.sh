#/bin/sh

cp test.o test_g.o
strip test.o
readelf -S test.o > readelf_1.txt
readelf -S test_g.o > readelf_g.txt

echo "output: done!"