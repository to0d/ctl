; 
; clang llt_wsl_exam_8_for.ll -o x.llt_wsl_exam_8_for
; ./x.llt_wsl_exam_8_for
;
; echo $?   //should be 10
;
;   int j = 0;
;   for (int i =1; i <=4; ++i)
;   {  j += i;
;   }
;
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"


define i32 @main() {

    %i = alloca i32                                 ; int i = 0
    store i32 0, i32* %i
    %j = alloca i32                                 ; int j = 0
    store i32 0, i32* %j
    br label %start

start:
    %i_value = load i32, i32* %i
    %comparison_result = icmp slt i32 %i_value, 4   ; test if i < 4
    br i1 %comparison_result, label %A, label %B

A:
    ; do something A
    %1 = add i32 %i_value, 1                        ; i++
    store i32 %1, i32* %i
    
    %j_value = load i32, i32* %j                    ; j += i
    %2 = add i32 %j_value, %1    
    store i32 %2, i32* %j    

    br label %start
    
B:
    %z_value = load i32, i32* %j
    ret i32 %z_value 
}
