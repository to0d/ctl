
define i32 @test_function(i32 %a, i32 %b) {
  %add_result = add i32 %a, %b
  %sub_result = sub i32 %add_result, 1
  %mul_result = mul i32 %sub_result, 2
  %div_result = sdiv i32 %mul_result, 2
  ret i32 %div_result
}
