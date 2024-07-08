; ModuleID = 'partial-inline-act.ll'
source_filename = "partial-inline-act.ll"

define internal i32 @inlinedFunc(i1 %cond, i32* align 4 %align.val) {
entry:
  br i1 %cond, label %if.then, label %return

if.then:                                          ; preds = %entry
  store i32 10, i32* %align.val, align 4
  br label %return

return:                                           ; preds = %if.then, %entry
  ret i32 0
}

define internal i32 @dummyCaller(i1 %cond, i32* align 2 %align.val) {
entry:
  %val = call i32 @inlinedFunc(i1 %cond, i32* %align.val)
  ret i32 %val
}
