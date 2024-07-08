define dso_local void @foo(i32 noundef %0) {
  %2 = alloca i32, align 4
  store i32 %0, i32* %2, align 4
  %3 = load i32, i32* %2, align 4
  %4 = call i32 @fun1(i32 noundef %3)
  %5 = icmp sgt i32 %4, 0
  br i1 %5, label %6, label %7

6:                                                ; preds = %1
  ret void

7:                                                ; preds = %1
  %8 = load i32, i32* %2, align 4
  %9 = call i32 @fun1(i32 noundef %8)
  %10 = icmp sgt i32 %9, 1
  br i1 %10, label %11, label %12

11:                                               ; preds = %7
  ret void

12:                                               ; preds = %7
  ret void

13:                                               ; preds = %12, %11, %6
  ret void
}


declare i32 @fun1(i32 noundef)