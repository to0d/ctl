;int f1(int x){
;  return x + 1;
;}
;
;int f2(int x){
;  return x - 1;
;}
;
;int foo(int x){
;  return f1(x)*f2(x)*2;
;}

define dso_local i32 @f1(i32 noundef %0) {
  %2 = alloca i32, align 4
  store i32 %0, i32* %2, align 4
  %3 = load i32, i32* %2, align 4
  %4 = add nsw i32 %3, 1
  ret i32 %4
}

define dso_local i32 @f2(i32 noundef %0) {
  %2 = alloca i32, align 4
  store i32 %0, i32* %2, align 4
  %3 = load i32, i32* %2, align 4
  %4 = sub nsw i32 %3, 1
  ret i32 %4
}

define dso_local i32 @foo(i32 noundef %0) {
  %2 = alloca i32, align 4
  store i32 %0, i32* %2, align 4
  %3 = load i32, i32* %2, align 4
  %4 = call i32 @f1(i32 noundef %3)
  %5 = load i32, i32* %2, align 4
  %6 = call i32 @f2(i32 noundef %5)
  %7 = mul nsw i32 %4, %6
  %8 = mul nsw i32 %7, 2
  ret i32 %8
}

