; ModuleID = 'test_cpp.cpp'
source_filename = "test_cpp.cpp"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

@global_a = dso_local global i32 1, align 4

; Function Attrs: mustprogress noinline optnone uwtable
define dso_local void @_Z4testv() #0 {
  %1 = alloca i32, align 4
  %2 = alloca float, align 4
  %3 = alloca double, align 8
  store i32 0, i32* %1, align 4
  store float 0.000000e+00, float* %2, align 4
  store double 0.000000e+00, double* %3, align 8
  call void @_Z5func1i(i32 noundef 1)
  %4 = load i32, i32* %1, align 4
  call void @_Z5func1i(i32 noundef %4)
  %5 = load i32, i32* @global_a, align 4
  call void @_Z5func1i(i32 noundef %5)
  %6 = load double, double* %3, align 8
  call void @_Z5func2d(double noundef %6)
  ret void
}

declare void @_Z5func1i(i32 noundef) #1

declare void @_Z5func2d(double noundef) #1

attributes #0 = { mustprogress noinline optnone uwtable "frame-pointer"="all" "min-legal-vector-width"="0" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #1 = { "frame-pointer"="all" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }

!llvm.module.flags = !{!0, !1, !2, !3, !4}
!llvm.ident = !{!5}

!0 = !{i32 1, !"wchar_size", i32 4}
!1 = !{i32 7, !"PIC Level", i32 2}
!2 = !{i32 7, !"PIE Level", i32 2}
!3 = !{i32 7, !"uwtable", i32 1}
!4 = !{i32 7, !"frame-pointer", i32 2}
!5 = !{!"Ubuntu clang version 14.0.6"}
