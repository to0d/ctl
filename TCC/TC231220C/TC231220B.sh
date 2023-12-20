#/bin/sh

echo "******** test_c.ll ********"
cat test_c.ll | grep -i TBAA

echo "******** test_cpp.ll ********"
cat test_cpp.ll | grep -i TBAA