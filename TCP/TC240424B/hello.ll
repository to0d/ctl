; ModuleID = 'hello.c'
source_filename = "hello.c"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

@__const.func.guard = private unnamed_addr constant [1 x i32] [i32 1], align 4

; Function Attrs: noinline nounwind optnone uwtable
define dso_local void @func(i32 noundef %0) #0 !dbg !10 {
  %2 = alloca i32, align 4
  %3 = alloca [100 x i32], align 16
  %4 = alloca [1 x i32], align 4
  store i32 %0, i32* %2, align 4
  call void @llvm.dbg.declare(metadata i32* %2, metadata !15, metadata !DIExpression()), !dbg !16
  call void @llvm.dbg.declare(metadata [100 x i32]* %3, metadata !17, metadata !DIExpression()), !dbg !21
  call void @llvm.dbg.declare(metadata [1 x i32]* %4, metadata !22, metadata !DIExpression()), !dbg !26
  %5 = bitcast [1 x i32]* %4 to i8*, !dbg !26
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 4 %5, i8* align 4 bitcast ([1 x i32]* @__const.func.guard to i8*), i64 4, i1 false), !dbg !26
  %6 = load i32, i32* %2, align 4, !dbg !27
  %7 = sext i32 %6 to i64, !dbg !28
  %8 = getelementptr inbounds [100 x i32], [100 x i32]* %3, i64 0, i64 %7, !dbg !28
  store i32 10, i32* %8, align 4, !dbg !29
  ret void, !dbg !30
}

; Function Attrs: nofree nosync nounwind readnone speculatable willreturn
declare void @llvm.dbg.declare(metadata, metadata, metadata) #1

; Function Attrs: argmemonly nofree nounwind willreturn
declare void @llvm.memcpy.p0i8.p0i8.i64(i8* noalias nocapture writeonly, i8* noalias nocapture readonly, i64, i1 immarg) #2

attributes #0 = { noinline nounwind optnone uwtable "frame-pointer"="all" "min-legal-vector-width"="0" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #1 = { nofree nosync nounwind readnone speculatable willreturn }
attributes #2 = { argmemonly nofree nounwind willreturn }

!llvm.dbg.cu = !{!0}
!llvm.module.flags = !{!2, !3, !4, !5, !6, !7, !8}
!llvm.ident = !{!9}

!0 = distinct !DICompileUnit(language: DW_LANG_C99, file: !1, producer: "Ubuntu clang version 14.0.0-1ubuntu1.1", isOptimized: false, runtimeVersion: 0, emissionKind: FullDebug, splitDebugInlining: false, nameTableKind: None)
!1 = !DIFile(filename: "hello.c", directory: "/mnt/c/data/public/ctl/TCP/TC240424B", checksumkind: CSK_MD5, checksum: "5ce543d934fbe0f332f8ad2e74e47d72")
!2 = !{i32 7, !"Dwarf Version", i32 5}
!3 = !{i32 2, !"Debug Info Version", i32 3}
!4 = !{i32 1, !"wchar_size", i32 4}
!5 = !{i32 7, !"PIC Level", i32 2}
!6 = !{i32 7, !"PIE Level", i32 2}
!7 = !{i32 7, !"uwtable", i32 1}
!8 = !{i32 7, !"frame-pointer", i32 2}
!9 = !{!"Ubuntu clang version 14.0.0-1ubuntu1.1"}
!10 = distinct !DISubprogram(name: "func", scope: !1, file: !1, line: 3, type: !11, scopeLine: 3, flags: DIFlagPrototyped, spFlags: DISPFlagDefinition, unit: !0, retainedNodes: !14)
!11 = !DISubroutineType(types: !12)
!12 = !{null, !13}
!13 = !DIBasicType(name: "int", size: 32, encoding: DW_ATE_signed)
!14 = !{}
!15 = !DILocalVariable(name: "x", arg: 1, scope: !10, file: !1, line: 3, type: !13)
!16 = !DILocation(line: 3, column: 15, scope: !10)
!17 = !DILocalVariable(name: "arr", scope: !10, file: !1, line: 4, type: !18)
!18 = !DICompositeType(tag: DW_TAG_array_type, baseType: !13, size: 3200, elements: !19)
!19 = !{!20}
!20 = !DISubrange(count: 100)
!21 = !DILocation(line: 4, column: 9, scope: !10)
!22 = !DILocalVariable(name: "guard", scope: !10, file: !1, line: 5, type: !23)
!23 = !DICompositeType(tag: DW_TAG_array_type, baseType: !13, size: 32, elements: !24)
!24 = !{!25}
!25 = !DISubrange(count: 1)
!26 = !DILocation(line: 5, column: 9, scope: !10)
!27 = !DILocation(line: 6, column: 9, scope: !10)
!28 = !DILocation(line: 6, column: 5, scope: !10)
!29 = !DILocation(line: 6, column: 12, scope: !10)
!30 = !DILocation(line: 7, column: 1, scope: !10)
