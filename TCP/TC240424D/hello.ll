; ModuleID = 'hello.c'
source_filename = "hello.c"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

@.str = private unnamed_addr constant [3 x i8] c"x\0A\00", align 1
@.str.1 = private unnamed_addr constant [4 x i8] c"x2\0A\00", align 1

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @func(i32 noundef %0) #0 !dbg !10 {
  %2 = alloca i32, align 4
  store i32 %0, i32* %2, align 4
  call void @llvm.dbg.declare(metadata i32* %2, metadata !15, metadata !DIExpression()), !dbg !16
  %3 = load i32, i32* %2, align 4, !dbg !17
  %4 = icmp sgt i32 %3, 1, !dbg !19
  br i1 %4, label %5, label %7, !dbg !20

5:                                                ; preds = %1
  %6 = call i32 (i8*, ...) @printf(i8* noundef getelementptr inbounds ([3 x i8], [3 x i8]* @.str, i64 0, i64 0)), !dbg !21
  br label %7, !dbg !23

7:                                                ; preds = %5, %1
  call void (...) @f1(), !dbg !24
  %8 = load i32, i32* %2, align 4, !dbg !25
  %9 = icmp sgt i32 %8, 1, !dbg !27
  br i1 %9, label %10, label %12, !dbg !28

10:                                               ; preds = %7
  %11 = call i32 (i8*, ...) @printf(i8* noundef getelementptr inbounds ([4 x i8], [4 x i8]* @.str.1, i64 0, i64 0)), !dbg !29
  br label %12, !dbg !31

12:                                               ; preds = %10, %7
  call void (...) @f2(), !dbg !32
  %13 = load i32, i32* %2, align 4, !dbg !33
  ret i32 %13, !dbg !34
}

; Function Attrs: nofree nosync nounwind readnone speculatable willreturn
declare void @llvm.dbg.declare(metadata, metadata, metadata) #1

declare i32 @printf(i8* noundef, ...) #2

declare void @f1(...) #2

declare void @f2(...) #2

attributes #0 = { noinline nounwind optnone uwtable "frame-pointer"="all" "min-legal-vector-width"="0" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #1 = { nofree nosync nounwind readnone speculatable willreturn }
attributes #2 = { "frame-pointer"="all" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }

!llvm.dbg.cu = !{!0}
!llvm.module.flags = !{!2, !3, !4, !5, !6, !7, !8}
!llvm.ident = !{!9}

!0 = distinct !DICompileUnit(language: DW_LANG_C99, file: !1, producer: "Ubuntu clang version 14.0.0-1ubuntu1.1", isOptimized: false, runtimeVersion: 0, emissionKind: FullDebug, splitDebugInlining: false, nameTableKind: None)
!1 = !DIFile(filename: "hello.c", directory: "/mnt/c/data/public/ctl/TCP/TC240424D", checksumkind: CSK_MD5, checksum: "dc631401f346697e4b52c89343baff07")
!2 = !{i32 7, !"Dwarf Version", i32 5}
!3 = !{i32 2, !"Debug Info Version", i32 3}
!4 = !{i32 1, !"wchar_size", i32 4}
!5 = !{i32 7, !"PIC Level", i32 2}
!6 = !{i32 7, !"PIE Level", i32 2}
!7 = !{i32 7, !"uwtable", i32 1}
!8 = !{i32 7, !"frame-pointer", i32 2}
!9 = !{!"Ubuntu clang version 14.0.0-1ubuntu1.1"}
!10 = distinct !DISubprogram(name: "func", scope: !1, file: !1, line: 6, type: !11, scopeLine: 7, flags: DIFlagPrototyped, spFlags: DISPFlagDefinition, unit: !0, retainedNodes: !14)
!11 = !DISubroutineType(types: !12)
!12 = !{!13, !13}
!13 = !DIBasicType(name: "int", size: 32, encoding: DW_ATE_signed)
!14 = !{}
!15 = !DILocalVariable(name: "x", arg: 1, scope: !10, file: !1, line: 6, type: !13)
!16 = !DILocation(line: 6, column: 14, scope: !10)
!17 = !DILocation(line: 8, column: 9, scope: !18)
!18 = distinct !DILexicalBlock(scope: !10, file: !1, line: 8, column: 9)
!19 = !DILocation(line: 8, column: 11, scope: !18)
!20 = !DILocation(line: 8, column: 9, scope: !10)
!21 = !DILocation(line: 9, column: 9, scope: !22)
!22 = distinct !DILexicalBlock(scope: !18, file: !1, line: 8, column: 16)
!23 = !DILocation(line: 10, column: 5, scope: !22)
!24 = !DILocation(line: 12, column: 5, scope: !10)
!25 = !DILocation(line: 14, column: 9, scope: !26)
!26 = distinct !DILexicalBlock(scope: !10, file: !1, line: 14, column: 9)
!27 = !DILocation(line: 14, column: 11, scope: !26)
!28 = !DILocation(line: 14, column: 9, scope: !10)
!29 = !DILocation(line: 15, column: 9, scope: !30)
!30 = distinct !DILexicalBlock(scope: !26, file: !1, line: 14, column: 16)
!31 = !DILocation(line: 16, column: 5, scope: !30)
!32 = !DILocation(line: 18, column: 5, scope: !10)
!33 = !DILocation(line: 19, column: 12, scope: !10)
!34 = !DILocation(line: 19, column: 5, scope: !10)
