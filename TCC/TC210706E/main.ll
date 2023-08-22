; 
; clang llt_wsl_exam_5_convert.ll -o x.llt_wsl_exam_5_convert
; ./x.llt_wsl_exam_5_convert
; echo $?
;
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

define i32 @main() {
    %trunc_integer = trunc i32 257 to i8    ; trunc 32 bit 100000001 to 8 bit, get 1
    %zext_integer = zext i8 -1 to i32       ; extend 8 bit 0xFF to 32 bit 0x000000FF, get 255
    %sext_integer = sext i8 -1 to i32       ; extend 8 bit 0xFF to 32 bit 0xFFFFFFFF, get -1
    ret i32 %sext_integer
}
