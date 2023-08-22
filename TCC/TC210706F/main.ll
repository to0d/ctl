; 
; clang llt_wsl_exam_6_pointer.ll -o x.llt_wsl_exam_6_pointer
; ./x.llt_wsl_exam_6_pointer
; echo $?   //should be 123
;
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

; int x, y;
; size_t address_of_x = (size_t)&x;
; size_t address_of_y = address_of_x - sizeof(int);
; int also_y = *(int *)address_of_y;

define i32 @main() {

    %x = alloca i32                                 ; %x is of type i32*, which is the address of variable x
    %y = alloca i32                                 ; %y is of type i32*, which is the address of variable y
    %address_of_x = ptrtoint i32* %x to i64
    %address_of_y = sub i64 %address_of_x, 4
    %also_y = inttoptr i64 %address_of_y to i32*    ; %also_y is of type i32*, which is the address of variable y
    store i32 123, i32* %y                          ; y=123, so the also_y should be 123
    %1 = load i32, i32* %also_y                     ; load *also_y

    ret i32 %1
}
