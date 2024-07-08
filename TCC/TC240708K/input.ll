;int foo(int x){
;  return 4 + ( x + 5);
;}

define dso_local i32 @foo(i32 noundef %0)  {
  %2 = alloca i32, align 4
  store i32 %0, i32* %2, align 4
  %3 = load i32, i32* %2, align 4
  %4 = add nsw i32 %3, 5
  %5 = add nsw i32 4, %4
  ret i32 %5
}

