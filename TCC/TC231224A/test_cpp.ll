; ModuleID = 'test.c'
source_filename = "test.c"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

; Function Attrs: alwaysinline mustprogress uwtable
define dso_local void @_Z4funci(i32 noundef %0) #0 {
  %2 = alloca i32, align 4
  %3 = alloca i32, align 4
  store i32 %0, i32* %2, align 4
  %4 = load i32, i32* %2, align 4
  %5 = add nsw i32 %4, 1
  store i32 %5, i32* %3, align 4
  %6 = load i32, i32* %3, align 4
  call void @_Z4foo1i(i32 noundef %6)
  call void @_Z4foo2i(i32 noundef 2)
  ret void
}

declare void @_Z4foo1i(i32 noundef) #1

declare void @_Z4foo2i(i32 noundef) #1

; Function Attrs: mustprogress noinline optnone uwtable
define dso_local void @_Z3runv() #2 {
  %1 = alloca i32, align 4
  %2 = alloca i32, align 4
  store i32 0, i32* %1, align 4
  %3 = load i32, i32* %1, align 4
  %4 = add nsw i32 %3, 1
  store i32 %4, i32* %2, align 4
  %5 = load i32, i32* %2, align 4
  call void @_Z4foo1i(i32 noundef %5)
  call void @_Z4foo2i(i32 noundef 2)
  call void @_Z5func2i(i32 noundef 1)
  ret void
}

declare void @_Z5func2i(i32 noundef) #1

attributes #0 = { alwaysinline mustprogress uwtable "frame-pointer"="all" "min-legal-vector-width"="0" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #1 = { "frame-pointer"="all" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #2 = { mustprogress noinline optnone uwtable "frame-pointer"="all" "min-legal-vector-width"="0" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }

!llvm.module.flags = !{!0, !1, !2, !3, !4}
!llvm.ident = !{!5}

!0 = !{i32 1, !"wchar_size", i32 4}
!1 = !{i32 7, !"PIC Level", i32 2}
!2 = !{i32 7, !"PIE Level", i32 2}
!3 = !{i32 7, !"uwtable", i32 1}
!4 = !{i32 7, !"frame-pointer", i32 2}
!5 = !{!"Ubuntu clang version 14.0.6"}
