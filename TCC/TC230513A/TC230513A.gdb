## gdb main.x -batch -x TC230513A.gdb
b 8 if target == 5
commands
silent
i args
continue
end
r