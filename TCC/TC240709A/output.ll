; ModuleID = 'input.ll'
source_filename = "input.ll"

define dso_local noundef zeroext i1 @_Z9is_sortedPii(i32* noundef %0, i32 noundef %1) {
  br label %3

3:                                                ; preds = %17, %2
  %.0 = phi i32 [ 0, %2 ], [ %18, %17 ]
  %4 = sub nsw i32 %1, 1
  %5 = icmp slt i32 %.0, %4
  br i1 %5, label %6, label %19

6:                                                ; preds = %3
  %7 = sext i32 %.0 to i64
  %8 = getelementptr inbounds i32, i32* %0, i64 %7
  %9 = load i32, i32* %8, align 4
  %10 = add nsw i32 %.0, 1
  %11 = sext i32 %10 to i64
  %12 = getelementptr inbounds i32, i32* %0, i64 %11
  %13 = load i32, i32* %12, align 4
  %14 = icmp sgt i32 %9, %13
  br i1 %14, label %15, label %16

15:                                               ; preds = %6
  br label %20

16:                                               ; preds = %6
  br label %17

17:                                               ; preds = %16
  %18 = add nsw i32 %.0, 1
  br label %3

19:                                               ; preds = %3
  br label %20

20:                                               ; preds = %19, %15
  %.07 = phi i1 [ false, %15 ], [ true, %19 ]
  ret i1 %.07
}
