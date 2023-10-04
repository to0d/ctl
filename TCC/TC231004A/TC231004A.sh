#/bin/sh

readelf -h fun.o > readelf_h_fun_o.txt
readelf -d fun.o > readelf_d_fun_o.txt
readelf -l fun.o > readelf_l_fun_o.txt
readelf -S fun.o > readelf_s_fun_o_.txt
readelf -s fun.o > readelf_s_fun_o.txt
readelf -n fun.o > readelf_n_fun_o.txt
readelf -r fun.o > readelf_r_fun_o.txt

readelf -h hello.a > readelf_h_hello_a.txt
readelf -d hello.a > readelf_d_hello_a.txt
readelf -l hello.a > readelf_l_hello_a.txt
readelf -S hello.a > readelf_s_hello_a_.txt
readelf -s hello.a > readelf_s_hello_a.txt
readelf -n hello.a > readelf_n_hello_a.txt
readelf -r hello.a > readelf_r_hello_a.txt

readelf --debug-dump=info fun.o   > readelf_debug_dump_fun_o.txt
readelf --debug-dump=info hello.a > readelf_debug_dump_hello_a.txt

objdump -d fun.o > objdump_d_fun_o.txt
objdump -D fun.o > objdump_d_fun_o_.txt
objdump -h fun.o > objdump_h_fun_o.txt
objdump -x fun.o > objdump_x_fun_o.txt
objdump -i fun.o > objdump_i_fun_o.txt
objdump -r fun.o > objdump_r_fun_o.txt
objdump -R fun.o > objdump_R_fun_o.txt
objdump -S fun.o > objdump_s_fun_o_.txt
objdump -s fun.o > objdump_s_fun_o.txt
objdump -t fun.o > objdump_t_fun_o.txt

objdump -d hello.a > objdump_d_hello_a.txt
objdump -D hello.a > objdump_d_hello_a_.txt
objdump -h hello.a > objdump_h_hello_a.txt
objdump -x hello.a > objdump_x_hello_a.txt
objdump -i hello.a > objdump_i_hello_a.txt
objdump -r hello.a > objdump_r_hello_a.txt
objdump -R hello.a > objdump_R_hello_a.txt
objdump -S hello.a > objdump_s_hello_a_.txt
objdump -s hello.a > objdump_s_hello_a.txt
objdump -t hello.a > objdump_t_hello_a.txt

nm -s fun.o     > nm_s_fun_o.txt
nm -s hello.a   > nm_s_hello_a.txt

dwarfdump -a fun.o   > dwarfdump_a_fun_o.txt
dwarfdump -a hello.a > dwarfdump_a_hello_a.txt


echo "output: done!"