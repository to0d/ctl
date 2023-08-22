; 
;
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

; struct MyStruct {
;     int x;
;     char y;
; };

%MyStruct = type {
    i32,
    i32
}
@my_struct      = global %MyStruct { i32 1, i32 2 }
@global_array   = global [4 x i32] [ i32 0, i32 1, i32 2, i32 3 ]

define i32 @main() {
    %1 = load %MyStruct, %MyStruct* @my_struct
    %a = alloca [4 x i32]
    ret i32 0
}