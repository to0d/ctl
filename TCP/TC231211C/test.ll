; ModuleID = 'test.cpp'
source_filename = "test.cpp"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

%class.TestClass = type { i32 }

$_ZN9TestClass9set_valueEi = comdat any

@.str = private unnamed_addr constant [9 x i8] c"value=%d\00", align 1

; Function Attrs: mustprogress noinline optnone uwtable
define dso_local void @_Z4fun1v() #0 {
  %1 = alloca %class.TestClass, align 4
  %2 = getelementptr inbounds %class.TestClass, %class.TestClass* %1, i32 0, i32 0
  %3 = load i32, i32* %2, align 4
  %4 = call i32 (i8*, ...) @printf(i8* noundef getelementptr inbounds ([9 x i8], [9 x i8]* @.str, i64 0, i64 0), i32 noundef %3)
  call void @_ZN9TestClass9set_valueEi(%class.TestClass* noundef nonnull align 4 dereferenceable(4) %1, i32 noundef 1)
  ret void
}

declare i32 @printf(i8* noundef, ...) #1

; Function Attrs: mustprogress noinline nounwind optnone uwtable
define linkonce_odr dso_local void @_ZN9TestClass9set_valueEi(%class.TestClass* noundef nonnull align 4 dereferenceable(4) %0, i32 noundef %1) #2 comdat align 2 {
  %3 = alloca %class.TestClass*, align 8
  %4 = alloca i32, align 4
  store %class.TestClass* %0, %class.TestClass** %3, align 8
  store i32 %1, i32* %4, align 4
  %5 = load %class.TestClass*, %class.TestClass** %3, align 8
  %6 = load i32, i32* %4, align 4
  %7 = getelementptr inbounds %class.TestClass, %class.TestClass* %5, i32 0, i32 0
  store i32 %6, i32* %7, align 4
  ret void
}

attributes #0 = { mustprogress noinline optnone uwtable "frame-pointer"="all" "min-legal-vector-width"="0" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #1 = { "frame-pointer"="all" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #2 = { mustprogress noinline nounwind optnone uwtable "frame-pointer"="all" "min-legal-vector-width"="0" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }

!llvm.module.flags = !{!0, !1, !2, !3, !4}
!llvm.ident = !{!5}

!0 = !{i32 1, !"wchar_size", i32 4}
!1 = !{i32 7, !"PIC Level", i32 2}
!2 = !{i32 7, !"PIE Level", i32 2}
!3 = !{i32 7, !"uwtable", i32 1}
!4 = !{i32 7, !"frame-pointer", i32 2}
!5 = !{!"Ubuntu clang version 14.0.0-1ubuntu1.1"}
