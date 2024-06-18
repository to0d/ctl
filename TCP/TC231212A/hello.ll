; ModuleID = 'hello.c'
source_filename = "hello.c"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @func() #0 !dbg !10 {
  %1 = alloca i32, align 4
  %2 = alloca i32*, align 8
  %3 = alloca i32, align 4
  call void @llvm.dbg.declare(metadata i32* %1, metadata !15, metadata !DIExpression()), !dbg !16
  store i32 1, i32* %1, align 4, !dbg !16
  call void @llvm.dbg.declare(metadata i32** %2, metadata !17, metadata !DIExpression()), !dbg !19
  store i32* %1, i32** %2, align 8, !dbg !19
  call void @llvm.dbg.declare(metadata i32* %3, metadata !20, metadata !DIExpression()), !dbg !21
  %4 = load i32*, i32** %2, align 8, !dbg !22
  %5 = load i32, i32* %4, align 4, !dbg !23
  store i32 %5, i32* %3, align 4, !dbg !21
  %6 = load i32, i32* %1, align 4, !dbg !24
  %7 = load i32*, i32** %2, align 8, !dbg !25
  %8 = load i32, i32* %7, align 4, !dbg !26
  %9 = add nsw i32 %6, %8, !dbg !27
  %10 = load i32, i32* %3, align 4, !dbg !28
  %11 = add nsw i32 %9, %10, !dbg !29
  ret i32 %11, !dbg !30
}

; Function Attrs: nofree nosync nounwind readnone speculatable willreturn
declare void @llvm.dbg.declare(metadata, metadata, metadata) #1

attributes #0 = { noinline nounwind optnone uwtable "frame-pointer"="all" "min-legal-vector-width"="0" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #1 = { nofree nosync nounwind readnone speculatable willreturn }

!llvm.dbg.cu = !{!0}
!llvm.module.flags = !{!2, !3, !4, !5, !6, !7, !8}
!llvm.ident = !{!9}

!0 = distinct !DICompileUnit(language: DW_LANG_C99, file: !1, producer: "Ubuntu clang version 14.0.0-1ubuntu1.1", isOptimized: false, runtimeVersion: 0, emissionKind: FullDebug, splitDebugInlining: false, nameTableKind: None)
!1 = !DIFile(filename: "hello.c", directory: "/mnt/c/data/public/ctl/TCP/TC231212A", checksumkind: CSK_MD5, checksum: "025c74415bcbd9a86224c0e54bfa25a8")
!2 = !{i32 7, !"Dwarf Version", i32 5}
!3 = !{i32 2, !"Debug Info Version", i32 3}
!4 = !{i32 1, !"wchar_size", i32 4}
!5 = !{i32 7, !"PIC Level", i32 2}
!6 = !{i32 7, !"PIE Level", i32 2}
!7 = !{i32 7, !"uwtable", i32 1}
!8 = !{i32 7, !"frame-pointer", i32 2}
!9 = !{!"Ubuntu clang version 14.0.0-1ubuntu1.1"}
!10 = distinct !DISubprogram(name: "func", scope: !1, file: !1, line: 3, type: !11, scopeLine: 4, spFlags: DISPFlagDefinition, unit: !0, retainedNodes: !14)
!11 = !DISubroutineType(types: !12)
!12 = !{!13}
!13 = !DIBasicType(name: "int", size: 32, encoding: DW_ATE_signed)
!14 = !{}
!15 = !DILocalVariable(name: "x", scope: !10, file: !1, line: 5, type: !13)
!16 = !DILocation(line: 5, column: 9, scope: !10)
!17 = !DILocalVariable(name: "y", scope: !10, file: !1, line: 6, type: !18)
!18 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: !13, size: 64)
!19 = !DILocation(line: 6, column: 10, scope: !10)
!20 = !DILocalVariable(name: "z", scope: !10, file: !1, line: 7, type: !13)
!21 = !DILocation(line: 7, column: 9, scope: !10)
!22 = !DILocation(line: 7, column: 14, scope: !10)
!23 = !DILocation(line: 7, column: 13, scope: !10)
!24 = !DILocation(line: 8, column: 12, scope: !10)
!25 = !DILocation(line: 8, column: 17, scope: !10)
!26 = !DILocation(line: 8, column: 16, scope: !10)
!27 = !DILocation(line: 8, column: 14, scope: !10)
!28 = !DILocation(line: 8, column: 21, scope: !10)
!29 = !DILocation(line: 8, column: 19, scope: !10)
!30 = !DILocation(line: 8, column: 5, scope: !10)
