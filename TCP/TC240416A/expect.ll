
define dso_local i32 @foo(i32 noundef %0, i32 noundef %1) {
  %add_result = add i32 %0, %1
  %sub_result = shl i32 %add_result, 1
  %mul_result = add i32 %sub_result, -2
  %div_result = sdiv i32 %mul_result, 3
  ret i32 %div_result
}
