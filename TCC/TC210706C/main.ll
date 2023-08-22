; 
; compile: clang llt_wsl_exam_3_register.ll -o x.llt_wsl_exam_3_register
; 
;
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

define i32 @main() {
    %local_variable = add i32 1, 2
    ret i32 %local_variable
}
