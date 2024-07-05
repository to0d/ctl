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
  br label %5

5:                                                ; preds = %10, %0
  %6 = load i32, i32* %1, align 4
  %7 = icmp slt i32 %6, 2
  br i1 %7, label %8, label %13

8:                                                ; preds = %5
  store i32 0, i32* %2, align 4
  br label %codeRepl

codeRepl:                                         ; preds = %8
  call void @foo.extracted(i32* %2, i32* %4)
  br label %9

9:                                                ; preds = %codeRepl
  call void (...) @f1()
  br label %10

10:                                               ; preds = %9
  %11 = load i32, i32* %1, align 4
  %12 = add nsw i32 %11, 1
  store i32 %12, i32* %1, align 4
  br label %5, !llvm.loop !6

13:                                               ; preds = %5
  call void (...) @f2()
  %14 = load i32, i32* %4, align 4
  ret i32 %14
}

declare void @f1(...) #1

declare void @f2(...) #1

; Function Attrs: noinline nounwind uwtable
define internal void @foo.extracted(i32* %0, i32* %1) #0 {
newFuncRoot:
  br label %2

2:                                                ; preds = %newFuncRoot, %8
  %3 = load i32, i32* %0, align 4
  %4 = icmp slt i32 %3, 3
  br i1 %4, label %5, label %.exitStub

5:                                                ; preds = %2
  %6 = load i32, i32* %1, align 4
  %7 = add nsw i32 %6, 1
  store i32 %7, i32* %1, align 4
  br label %8

8:                                                ; preds = %5
  %9 = load i32, i32* %0, align 4
  %10 = add nsw i32 %9, 1
  store i32 %10, i32* %0, align 4
  br label %2, !llvm.loop !8

.exitStub:                                        ; preds = %2
  ret void
}

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
