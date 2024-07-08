define dso_local i32 @foo(i32 noundef %0) {
  %2 = alloca i32, align 4
  %3 = alloca i32, align 4
  store i32 %0, i32* %3, align 4
  %4 = load i32, i32* %3, align 4
  switch i32 %4, label %14 [
    i32 0, label %5
    i32 1, label %8
    i32 3, label %11
  ]

5:                                                ; preds = %1
  %6 = load i32, i32* %3, align 4
  %7 = mul nsw i32 %6, 2
  store i32 %7, i32* %2, align 4
  br label %15

8:                                                ; preds = %1
  %9 = load i32, i32* %3, align 4
  %10 = mul nsw i32 %9, 6
  store i32 %10, i32* %2, align 4
  br label %15

11:                                               ; preds = %1
  %12 = load i32, i32* %3, align 4
  %13 = mul nsw i32 %12, 9
  store i32 %13, i32* %2, align 4
  br label %15

14:                                               ; preds = %1
  store i32 0, i32* %2, align 4
  br label %15

15:                                               ; preds = %14, %11, %8, %5
  %16 = load i32, i32* %2, align 4
  ret i32 %16
}


