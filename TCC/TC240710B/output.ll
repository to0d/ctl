; ModuleID = 'input.ll'
source_filename = "input.ll"

define dso_local i32 @foo(i32 noundef %arg) {
bb:
  %i = alloca i32, align 4
  %i1 = alloca i32, align 4
  store i32 %arg, i32* %i1, align 4
  %i2 = load i32, i32* %i1, align 4
  %i3 = icmp sle i32 %i2, 0
  br i1 %i3, label %bb4, label %bb5

bb4:                                              ; preds = %bb
  store i32 0, i32* %i, align 4
  br label %bb11

bb5:                                              ; preds = %bb
  %i6 = load i32, i32* %i1, align 4
  %i7 = load i32, i32* %i1, align 4
  %i8 = sub nsw i32 %i7, 1
  %i9 = call i32 @foo(i32 noundef %i8)
  %i10 = add nsw i32 %i6, %i9
  store i32 %i10, i32* %i, align 4
  br label %bb11

bb11:                                             ; preds = %bb5, %bb4
  %i12 = load i32, i32* %i, align 4
  ret i32 %i12
}
