; ModuleID = 'hello.c'
source_filename = "hello.c"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @foo1() #0 !dbg !10 {
  %1 = alloca i32, align 4
  %2 = alloca i32*, align 8
  call void @llvm.dbg.declare(metadata i32* %1, metadata !15, metadata !DIExpression()), !dbg !16
  store i32 1, i32* %1, align 4, !dbg !16
  call void @llvm.dbg.declare(metadata i32** %2, metadata !17, metadata !DIExpression()), !dbg !19
  store i32* %1, i32** %2, align 8, !dbg !19
  store i32 1, i32* %1, align 4, !dbg !20
  %3 = load i32*, i32** %2, align 8, !dbg !21
  store i32 2, i32* %3, align 4, !dbg !22
  %4 = load i32, i32* %1, align 4, !dbg !23
  %5 = load i32*, i32** %2, align 8, !dbg !24
  %6 = load i32, i32* %5, align 4, !dbg !25
  %7 = add nsw i32 %4, %6, !dbg !26
  ret i32 %7, !dbg !27
}

; Function Attrs: nofree nosync nounwind readnone speculatable willreturn
declare void @llvm.dbg.declare(metadata, metadata, metadata) #1

; Function Attrs: noinline nounwind optnone uwtable
define dso_local void @foo() #0 !dbg !28 {
  %1 = call i32 @foo1(), !dbg !31
  %2 = call i32 (...) @foo2(), !dbg !32
  ret void, !dbg !33
}

declare i32 @foo2(...) #2

attributes #0 = { noinline nounwind optnone uwtable "frame-pointer"="all" "min-legal-vector-width"="0" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #1 = { nofree nosync nounwind readnone speculatable willreturn }
attributes #2 = { "frame-pointer"="all" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }

!llvm.dbg.cu = !{!0}
!llvm.module.flags = !{!2, !3, !4, !5, !6, !7, !8}
!llvm.ident = !{!9}

!0 = distinct !DICompileUnit(language: DW_LANG_C99, file: !1, producer: "Ubuntu clang version 14.0.6", isOptimized: false, runtimeVersion: 0, emissionKind: FullDebug, splitDebugInlining: false, nameTableKind: None)
!1 = !DIFile(filename: "hello.c", directory: "/mnt/c/data/public/ctl/TCC/TC231221A", checksumkind: CSK_MD5, checksum: "cee2f51b295b435597071d5a2d25481f")
!2 = !{i32 7, !"Dwarf Version", i32 5}
!3 = !{i32 2, !"Debug Info Version", i32 3}
!4 = !{i32 1, !"wchar_size", i32 4}
!5 = !{i32 7, !"PIC Level", i32 2}
!6 = !{i32 7, !"PIE Level", i32 2}
!7 = !{i32 7, !"uwtable", i32 1}
!8 = !{i32 7, !"frame-pointer", i32 2}
!9 = !{!"Ubuntu clang version 14.0.6"}
!10 = distinct !DISubprogram(name: "foo1", scope: !1, file: !1, line: 4, type: !11, scopeLine: 4, spFlags: DISPFlagDefinition, unit: !0, retainedNodes: !14)
!11 = !DISubroutineType(types: !12)
!12 = !{!13}
!13 = !DIBasicType(name: "int", size: 32, encoding: DW_ATE_signed)
!14 = !{}
!15 = !DILocalVariable(name: "x", scope: !10, file: !1, line: 5, type: !13)
!16 = !DILocation(line: 5, column: 9, scope: !10)
!17 = !DILocalVariable(name: "y", scope: !10, file: !1, line: 6, type: !18)
!18 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: !13, size: 64)
!19 = !DILocation(line: 6, column: 10, scope: !10)
!20 = !DILocation(line: 7, column: 7, scope: !10)
!21 = !DILocation(line: 8, column: 6, scope: !10)
!22 = !DILocation(line: 8, column: 8, scope: !10)
!23 = !DILocation(line: 9, column: 12, scope: !10)
!24 = !DILocation(line: 9, column: 17, scope: !10)
!25 = !DILocation(line: 9, column: 16, scope: !10)
!26 = !DILocation(line: 9, column: 14, scope: !10)
!27 = !DILocation(line: 9, column: 5, scope: !10)
!28 = distinct !DISubprogram(name: "foo", scope: !1, file: !1, line: 14, type: !29, scopeLine: 14, spFlags: DISPFlagDefinition, unit: !0, retainedNodes: !14)
!29 = !DISubroutineType(types: !30)
!30 = !{null}
!31 = !DILocation(line: 15, column: 5, scope: !28)
!32 = !DILocation(line: 16, column: 5, scope: !28)
!33 = !DILocation(line: 17, column: 1, scope: !28)
