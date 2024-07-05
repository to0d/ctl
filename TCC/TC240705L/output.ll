; ModuleID = 'input.ll'
source_filename = "hello.c"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

; Function Attrs: noinline nounwind uwtable
define dso_local i32 @foo() #0 {
  %1 = alloca i32, align 4
  %2 = alloca i32, align 4
  %3 = alloca i32, align 4
  %4 = alloca i32, align 4
  store i32 0, i32* %4, align 4
  store i32 0, i32* %1, align 4
  %5 = load i32, i32* %1, align 4
  %6 = icmp slt i32 %5, 2
  br i1 %6, label %.lr.ph2, label %24

.lr.ph2:                                          ; preds = %0
  br label %7

7:                                                ; preds = %.lr.ph2, %19
  store i32 0, i32* %2, align 4
  %8 = load i32, i32* %2, align 4
  %9 = icmp slt i32 %8, 3
  br i1 %9, label %.lr.ph, label %18

.lr.ph:                                           ; preds = %7
  br label %10

10:                                               ; preds = %.lr.ph, %13
  %11 = load i32, i32* %4, align 4
  %12 = add nsw i32 %11, 1
  store i32 %12, i32* %4, align 4
  br label %13

13:                                               ; preds = %10
  %14 = load i32, i32* %2, align 4
  %15 = add nsw i32 %14, 1
  store i32 %15, i32* %2, align 4
  %16 = load i32, i32* %2, align 4
  %17 = icmp slt i32 %16, 3
  br i1 %17, label %10, label %._crit_edge, !llvm.loop !6

._crit_edge:                                      ; preds = %13
  br label %18

18:                                               ; preds = %._crit_edge, %7
  call void (...) @f1()
  br label %19

19:                                               ; preds = %18
  %20 = load i32, i32* %1, align 4
  %21 = add nsw i32 %20, 1
  store i32 %21, i32* %1, align 4
  %22 = load i32, i32* %1, align 4
  %23 = icmp slt i32 %22, 2
  br i1 %23, label %7, label %._crit_edge3, !llvm.loop !8

._crit_edge3:                                     ; preds = %19
  br label %24

24:                                               ; preds = %._crit_edge3, %0
  call void (...) @f2()
  %25 = load i32, i32* %4, align 4
  ret i32 %25
}

declare void @f1(...) #1

declare void @f2(...) #1

attributes #0 = { noinline nounwind uwtable "frame-pointer"="all" "min-legal-vector-width"="0" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #1 = { "frame-pointer"="all" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }

!llvm.module.flags = !{!0, !1, !2, !3, !4}
!llvm.ident = !{!5}

!0 = !{i32 1, !"wchar_size", i32 4}
!1 = !{i32 7, !"PIC Level", i32 2}
!2 = !{i32 7, !"PIE Level", i32 2}
!3 = !{i32 7, !"uwtable", i32 1}
!4 = !{i32 7, !"frame-pointer", i32 2}
!5 = !{!"Ubuntu clang version 14.0.0-1ubuntu1.1"}
!6 = distinct !{!6, !7}
!7 = !{!"llvm.loop.mustprogress"}
!8 = distinct !{!8, !7}
