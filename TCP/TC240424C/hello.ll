; ModuleID = 'hello.c'
source_filename = "hello.c"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @func(i32 noundef %0) #0 !dbg !10 {
  %2 = alloca i32, align 4
  %3 = alloca i32, align 4
  store i32 %0, i32* %3, align 4
  call void @llvm.dbg.declare(metadata i32* %3, metadata !15, metadata !DIExpression()), !dbg !16
  %4 = load i32, i32* %3, align 4, !dbg !17
  %5 = icmp sgt i32 %4, 0, !dbg !19
  br i1 %5, label %6, label %7, !dbg !20

6:                                                ; preds = %1
  store i32 1, i32* %2, align 4, !dbg !21
  br label %10, !dbg !21

7:                                                ; preds = %1
  %8 = load i32, i32* %3, align 4, !dbg !23
  %9 = add nsw i32 %8, 1, !dbg !24
  store i32 %9, i32* %2, align 4, !dbg !25
  br label %10, !dbg !25

10:                                               ; preds = %7, %6
  %11 = load i32, i32* %2, align 4, !dbg !26
  ret i32 %11, !dbg !26
}

; Function Attrs: nofree nosync nounwind readnone speculatable willreturn
declare void @llvm.dbg.declare(metadata, metadata, metadata) #1

attributes #0 = { noinline nounwind optnone uwtable "frame-pointer"="all" "min-legal-vector-width"="0" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #1 = { nofree nosync nounwind readnone speculatable willreturn }

!llvm.dbg.cu = !{!0}
!llvm.module.flags = !{!2, !3, !4, !5, !6, !7, !8}
!llvm.ident = !{!9}

!0 = distinct !DICompileUnit(language: DW_LANG_C99, file: !1, producer: "Ubuntu clang version 14.0.0-1ubuntu1.1", isOptimized: false, runtimeVersion: 0, emissionKind: FullDebug, splitDebugInlining: false, nameTableKind: None)
!1 = !DIFile(filename: "hello.c", directory: "/mnt/c/data/public/ctl/TCP/TC240424C", checksumkind: CSK_MD5, checksum: "ebea38051ed9181cd578d969625c550b")
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
!12 = !{!13, !13}
!13 = !DIBasicType(name: "int", size: 32, encoding: DW_ATE_signed)
!14 = !{}
!15 = !DILocalVariable(name: "x", arg: 1, scope: !10, file: !1, line: 3, type: !13)
!16 = !DILocation(line: 3, column: 14, scope: !10)
!17 = !DILocation(line: 4, column: 7, scope: !18)
!18 = distinct !DILexicalBlock(scope: !10, file: !1, line: 4, column: 7)
!19 = !DILocation(line: 4, column: 9, scope: !18)
!20 = !DILocation(line: 4, column: 7, scope: !10)
!21 = !DILocation(line: 5, column: 8, scope: !22)
!22 = distinct !DILexicalBlock(scope: !18, file: !1, line: 4, column: 13)
!23 = !DILocation(line: 7, column: 11, scope: !10)
!24 = !DILocation(line: 7, column: 13, scope: !10)
!25 = !DILocation(line: 7, column: 4, scope: !10)
!26 = !DILocation(line: 8, column: 1, scope: !10)
