; ModuleID = 'input.ll'
source_filename = "input.ll"

@__const.foo.xx = private unnamed_addr constant [3 x i32] [i32 1, i32 2, i32 3], align 4

define internal i32 @foo(i32 noundef %0) {
  %2 = alloca i32, align 4
  %3 = alloca [3 x i32], align 4
  store i32 %0, i32* %2, align 4
  %4 = bitcast [3 x i32]* %3 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 4 %4, i8* align 4 bitcast ([3 x i32]* @__const.foo.xx to i8*), i64 12, i1 false)
  %5 = load i32, i32* %2, align 4
  %6 = sext i32 %5 to i64
  %7 = getelementptr inbounds [3 x i32], [3 x i32]* %3, i64 0, i64 %6
  %8 = load i32, i32* %7, align 4
  ret i32 %8
}

; Function Attrs: argmemonly nofree nounwind willreturn
declare void @llvm.memcpy.p0i8.p0i8.i64(i8* noalias nocapture writeonly, i8* noalias nocapture readonly, i64, i1 immarg) #0

attributes #0 = { argmemonly nofree nounwind willreturn }
