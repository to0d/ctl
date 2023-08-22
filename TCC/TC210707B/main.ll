target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

define i32 @main() {
    %x = add i32 1, 2           ; x = 3
    %result = icmp sgt i32 %x, 0
    %y = select i1 %result, i32 1, i32 2
    ret i32 %y
}
