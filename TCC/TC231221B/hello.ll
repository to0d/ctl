; ModuleID = 'hello.c'
source_filename = "hello.c"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

@simd_block = dso_local global i32 0, align 4, !dbg !0
@.str = private unnamed_addr constant [5 x i8] c"x=%d\00", align 1

; Function Attrs: noinline nounwind optnone uwtable
define dso_local void @foo() #0 !dbg !15 {
  %1 = alloca i32, align 4
  %2 = alloca i32, align 4
  %3 = call i32 (...) @foo1(), !dbg !19
  %4 = call i32 (...) @foo2(), !dbg !20
  %5 = load i32, i32* @simd_block, align 4, !dbg !21
  %6 = icmp ne i32 %5, 0, !dbg !21
  br i1 %6, label %7, label %10, !dbg !23

7:                                                ; preds = %0
  call void @llvm.dbg.declare(metadata i32* %1, metadata !24, metadata !DIExpression()), !dbg !26
  store i32 1, i32* %1, align 4, !dbg !26
  %8 = load i32, i32* %1, align 4, !dbg !27
  %9 = call i32 (i8*, ...) @printf(i8* noundef getelementptr inbounds ([5 x i8], [5 x i8]* @.str, i64 0, i64 0), i32 noundef %8), !dbg !28
  br label %10, !dbg !29

10:                                               ; preds = %7, %0
  %11 = call i32 (...) @foo1(), !dbg !30
  %12 = load i32, i32* @simd_block, align 4, !dbg !31
  %13 = icmp ne i32 %12, 0, !dbg !31
  br i1 %13, label %14, label %17, !dbg !33

14:                                               ; preds = %10
  call void @llvm.dbg.declare(metadata i32* %2, metadata !34, metadata !DIExpression()), !dbg !36
  store i32 1, i32* %2, align 4, !dbg !36
  %15 = load i32, i32* %2, align 4, !dbg !37
  %16 = call i32 (i8*, ...) @printf(i8* noundef getelementptr inbounds ([5 x i8], [5 x i8]* @.str, i64 0, i64 0), i32 noundef %15), !dbg !38
  br label %17, !dbg !39

17:                                               ; preds = %14, %10
  ret void, !dbg !40
}

declare i32 @foo1(...) #1

declare i32 @foo2(...) #1

; Function Attrs: nofree nosync nounwind readnone speculatable willreturn
declare void @llvm.dbg.declare(metadata, metadata, metadata) #2

declare i32 @printf(i8* noundef, ...) #1

attributes #0 = { noinline nounwind optnone uwtable "frame-pointer"="all" "min-legal-vector-width"="0" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #1 = { "frame-pointer"="all" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #2 = { nofree nosync nounwind readnone speculatable willreturn }

!llvm.dbg.cu = !{!2}
!llvm.module.flags = !{!7, !8, !9, !10, !11, !12, !13}
!llvm.ident = !{!14}

!0 = !DIGlobalVariableExpression(var: !1, expr: !DIExpression())
!1 = distinct !DIGlobalVariable(name: "simd_block", scope: !2, file: !5, line: 2, type: !6, isLocal: false, isDefinition: true)
!2 = distinct !DICompileUnit(language: DW_LANG_C99, file: !3, producer: "Ubuntu clang version 14.0.6", isOptimized: false, runtimeVersion: 0, emissionKind: FullDebug, globals: !4, splitDebugInlining: false, nameTableKind: None)
!3 = !DIFile(filename: "hello.c", directory: "/mnt/c/data/public/ctl/TCC/TC231221B", checksumkind: CSK_MD5, checksum: "40b655c4d21aa16bea8532b87b3e9170")
!4 = !{!0}
!5 = !DIFile(filename: "./test.h", directory: "/mnt/c/data/public/ctl/TCC/TC231221B", checksumkind: CSK_MD5, checksum: "6558f6f95a24c6f24372d2f5a5c8e1e9")
!6 = !DIBasicType(name: "int", size: 32, encoding: DW_ATE_signed)
!7 = !{i32 7, !"Dwarf Version", i32 5}
!8 = !{i32 2, !"Debug Info Version", i32 3}
!9 = !{i32 1, !"wchar_size", i32 4}
!10 = !{i32 7, !"PIC Level", i32 2}
!11 = !{i32 7, !"PIE Level", i32 2}
!12 = !{i32 7, !"uwtable", i32 1}
!13 = !{i32 7, !"frame-pointer", i32 2}
!14 = !{!"Ubuntu clang version 14.0.6"}
!15 = distinct !DISubprogram(name: "foo", scope: !3, file: !3, line: 7, type: !16, scopeLine: 7, spFlags: DISPFlagDefinition, unit: !2, retainedNodes: !18)
!16 = !DISubroutineType(types: !17)
!17 = !{null}
!18 = !{}
!19 = !DILocation(line: 8, column: 5, scope: !15)
!20 = !DILocation(line: 9, column: 5, scope: !15)
!21 = !DILocation(line: 11, column: 9, scope: !22)
!22 = distinct !DILexicalBlock(scope: !15, file: !3, line: 11, column: 9)
!23 = !DILocation(line: 11, column: 9, scope: !15)
!24 = !DILocalVariable(name: "x", scope: !25, file: !3, line: 13, type: !6)
!25 = distinct !DILexicalBlock(scope: !22, file: !3, line: 12, column: 5)
!26 = !DILocation(line: 13, column: 13, scope: !25)
!27 = !DILocation(line: 14, column: 24, scope: !25)
!28 = !DILocation(line: 14, column: 9, scope: !25)
!29 = !DILocation(line: 15, column: 5, scope: !25)
!30 = !DILocation(line: 17, column: 5, scope: !15)
!31 = !DILocation(line: 19, column: 9, scope: !32)
!32 = distinct !DILexicalBlock(scope: !15, file: !3, line: 19, column: 9)
!33 = !DILocation(line: 19, column: 9, scope: !15)
!34 = !DILocalVariable(name: "x", scope: !35, file: !3, line: 21, type: !6)
!35 = distinct !DILexicalBlock(scope: !32, file: !3, line: 20, column: 5)
!36 = !DILocation(line: 21, column: 13, scope: !35)
!37 = !DILocation(line: 22, column: 24, scope: !35)
!38 = !DILocation(line: 22, column: 9, scope: !35)
!39 = !DILocation(line: 23, column: 5, scope: !35)
!40 = !DILocation(line: 24, column: 1, scope: !15)
