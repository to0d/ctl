;bool is_sorted(int* a, int n){
;  for(int i = 0;i < n-1; i++){
;    if(a[i] > a[i+1])
;      return false;
;  }
;  return true;
;}

define dso_local noundef zeroext i1 @_Z9is_sortedPii(i32* noundef %0, i32 noundef %1) {
  %3 = alloca i1, align 1
  %4 = alloca i32*, align 8
  %5 = alloca i32, align 4
  %6 = alloca i32, align 4
  store i32* %0, i32** %4, align 8
  store i32 %1, i32* %5, align 4
  store i32 0, i32* %6, align 4
  br label %7

7:                                                ; preds = %27, %2
  %8 = load i32, i32* %6, align 4
  %9 = load i32, i32* %5, align 4
  %10 = sub nsw i32 %9, 1
  %11 = icmp slt i32 %8, %10
  br i1 %11, label %12, label %30

12:                                               ; preds = %7
  %13 = load i32*, i32** %4, align 8
  %14 = load i32, i32* %6, align 4
  %15 = sext i32 %14 to i64
  %16 = getelementptr inbounds i32, i32* %13, i64 %15
  %17 = load i32, i32* %16, align 4
  %18 = load i32*, i32** %4, align 8
  %19 = load i32, i32* %6, align 4
  %20 = add nsw i32 %19, 1
  %21 = sext i32 %20 to i64
  %22 = getelementptr inbounds i32, i32* %18, i64 %21
  %23 = load i32, i32* %22, align 4
  %24 = icmp sgt i32 %17, %23
  br i1 %24, label %25, label %26

25:                                               ; preds = %12
  store i1 false, i1* %3, align 1
  br label %31

26:                                               ; preds = %12
  br label %27

27:                                               ; preds = %26
  %28 = load i32, i32* %6, align 4
  %29 = add nsw i32 %28, 1
  store i32 %29, i32* %6, align 4
  br label %7

30:                                               ; preds = %7
  store i1 true, i1* %3, align 1
  br label %31

31:                                               ; preds = %30, %25
  %32 = load i1, i1* %3, align 1
  ret i1 %32
}


