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
  %.promoted3 = load i32, i32* %1, align 4
  %.promoted5 = load i32, i32* %2, align 4
  %.promoted = load i32, i32* %4, align 4
  br label %5

5:                                                ; preds = %18, %0
  %.lcssa27 = phi i32 [ %.lcssa2, %18 ], [ %.promoted, %0 ]
  %.lcssa6 = phi i32 [ %.lcssa, %18 ], [ %.promoted5, %0 ]
  %6 = phi i32 [ %19, %18 ], [ %.promoted3, %0 ]
  %7 = icmp slt i32 %6, 2
  br i1 %7, label %8, label %20

8:                                                ; preds = %5
  br label %9

9:                                                ; preds = %15, %8
  %10 = phi i32 [ %14, %15 ], [ %.lcssa27, %8 ]
  %11 = phi i32 [ %16, %15 ], [ 0, %8 ]
  %12 = icmp slt i32 %11, 3
  br i1 %12, label %13, label %17

13:                                               ; preds = %9
  %14 = add nsw i32 %10, 1
  br label %15

15:                                               ; preds = %13
  %16 = add nsw i32 %11, 1
  br label %9, !llvm.loop !6

17:                                               ; preds = %9
  %.lcssa2 = phi i32 [ %10, %9 ]
  %.lcssa = phi i32 [ %11, %9 ]
  call void (...) @f1()
  br label %18

18:                                               ; preds = %17
  %19 = add nsw i32 %6, 1
  br label %5, !llvm.loop !8

20:                                               ; preds = %5
  %.lcssa27.lcssa = phi i32 [ %.lcssa27, %5 ]
  %.lcssa6.lcssa = phi i32 [ %.lcssa6, %5 ]
  %.lcssa4 = phi i32 [ %6, %5 ]
  store i32 %.lcssa4, i32* %1, align 4
  store i32 %.lcssa6.lcssa, i32* %2, align 4
  store i32 %.lcssa27.lcssa, i32* %4, align 4
  call void (...) @f2()
  %21 = load i32, i32* %4, align 4
  ret i32 %21
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
