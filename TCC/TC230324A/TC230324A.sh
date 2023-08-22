#/bin/sh

echo "readelf: "
readelf --debug-dump=info main.x | grep -A 2 'Compilation Unit @'
echo ""

echo "llvm-dwarfdump: "
llvm-dwarfdump -r 1 main.x  | grep Compile

echo "output: done"