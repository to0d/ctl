; 
; compile: clang llt_wsl_exam_4_number.ll -o x.llt_wsl_exam_4_number
; 
;
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

define i8 @main() {
    %1 = udiv i8 -6, 2
    %2 = sdiv i8 -6, 2
    ret i8 %1
}
