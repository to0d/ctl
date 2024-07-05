; ModuleID = 'input.ll'
source_filename = "hello.c"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

; Function Attrs: noinline nounwind uwtable
define dso_local i32 @foo() #0 {
  %1 = alloca i32, align 4
  %2 = alloca i32, align 4
  %3 = alloca i32, align 4
  store i32 0, i32* %3, align 4
  br label %4

4:                                                ; preds = %16, %0
  %storemerge = phi i32 [ 0, %0 ], [ %18, %16 ]
  store i32 %storemerge, i32* %1, align 4
  %5 = icmp slt i32 %storemerge, 2
  br i1 %5, label %6, label %19

6:                                                ; preds = %4
  br label %7

7:                                                ; preds = %12, %6
  %storemerge1 = phi i32 [ 0, %6 ], [ %14, %12 ]
  store i32 %storemerge1, i32* %2, align 4
  %8 = icmp slt i32 %storemerge1, 3
  br i1 %8, label %9, label %15

9:                                                ; preds = %7
  %10 = load i32, i32* %3, align 4
  %11 = add nsw i32 %10, 1
  store i32 %11, i32* %3, align 4
  br label %12

12:                                               ; preds = %9
  %13 = load i32, i32* %2, align 4
  %14 = add nsw i32 %13, 1
  br label %7, !llvm.loop !6

15:                                               ; preds = %7
  call void (...) @f1() #2
  br label %16

16:                                               ; preds = %15
  %17 = load i32, i32* %1, align 4
  %18 = add nsw i32 %17, 1
  br label %4, !llvm.loop !8

19:                                               ; preds = %4
  call void (...) @f2() #2
  %20 = load i32, i32* %3, align 4
  ret i32 %20
}

declare void @f1(...) #1

declare void @f2(...) #1

attributes #0 = { noinline nounwind uwtable "frame-pointer"="all" "min-legal-vector-width"="0" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #1 = { "frame-pointer"="all" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #2 = { nounwind }

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
