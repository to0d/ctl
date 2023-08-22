target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

define i32 @main() {
    %x = add i32 1, 2           ; x = 3
    %r = alloca i32
    store i32 2, i32* %r        ; r = 2

    %1 = load i32, i32* %r 
    
    switch i32 %x, label %C [
        i32 0, label %A
        i32 1, label %B
    ]
A:
    %2 = add i32 %1, 1          ; r = r + 1
    store i32 %2, i32* %r
    br label %end
B:
    %3 = sub i32 %1, 1          ; r = r - 1
    store i32 %3, i32* %r
    br label %end
C:
    %4 = mul i32 %1, 2          ; r = r * 2
    store i32 %4, i32* %r
    br label %end
end:
    %5 = load i32, i32* %r
    ret i32 %5
}
