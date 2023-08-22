; 
; compile: clang llt_wsl_exam_2_global_variable.ll -o x.llt_wsl_exam_2_global_variable
; 
;          nm x.llt_wsl_exam_2_global_variable
;
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

@global_variable_1 = global i32 0
@global_constant_2 = constant i32 0 

define i32 @main() {
    ret i32 0
}
