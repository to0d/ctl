; ModuleID = 'TC240521A2.c'
source_filename = "TC240521A2.c"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

; Function Attrs: nofree norecurse nosync nounwind uwtable
define dso_local void @foo(i32* noalias nocapture noundef writeonly %0, i32* noalias nocapture noundef readonly %1, i32* noalias nocapture noundef %2, i32 noundef %3) local_unnamed_addr #0 !dbg !8 {
  %5 = icmp ugt i32 %3, 1, !dbg !11
  br i1 %5, label %6, label %94, !dbg !12

6:                                                ; preds = %4
  %7 = zext i32 %3 to i64, !dbg !11
  %8 = load i32, i32* %2, align 4, !dbg !13, !tbaa !14
  %9 = add nsw i64 %7, -1, !dbg !12
  %10 = icmp ult i64 %9, 8, !dbg !12
  br i1 %10, label %91, label %11, !dbg !12

11:                                               ; preds = %6
  %12 = and i64 %9, -8, !dbg !12
  %13 = or i64 %12, 1, !dbg !12
  %14 = insertelement <4 x i32> poison, i32 %8, i64 3, !dbg !12
  %15 = add nsw i64 %12, -8, !dbg !12
  %16 = lshr exact i64 %15, 3, !dbg !12
  %17 = add nuw nsw i64 %16, 1, !dbg !12
  %18 = and i64 %17, 1, !dbg !12
  %19 = icmp eq i64 %15, 0, !dbg !12
  br i1 %19, label %65, label %20, !dbg !12

20:                                               ; preds = %11
  %21 = and i64 %17, 4611686018427387902, !dbg !12
  br label %22, !dbg !12

22:                                               ; preds = %22, %20
  %23 = phi i64 [ 0, %20 ], [ %60, %22 ]
  %24 = phi <4 x i32> [ %14, %20 ], [ %49, %22 ]
  %25 = phi i64 [ 0, %20 ], [ %61, %22 ]
  %26 = or i64 %23, 1
  %27 = getelementptr inbounds i32, i32* %1, i64 %26, !dbg !18
  %28 = bitcast i32* %27 to <4 x i32>*, !dbg !18
  %29 = load <4 x i32>, <4 x i32>* %28, align 4, !dbg !18, !tbaa !14
  %30 = getelementptr inbounds i32, i32* %27, i64 4, !dbg !18
  %31 = bitcast i32* %30 to <4 x i32>*, !dbg !18
  %32 = load <4 x i32>, <4 x i32>* %31, align 4, !dbg !18, !tbaa !14
  %33 = shufflevector <4 x i32> %24, <4 x i32> %29, <4 x i32> <i32 3, i32 4, i32 5, i32 6>
  %34 = shufflevector <4 x i32> %29, <4 x i32> %32, <4 x i32> <i32 3, i32 4, i32 5, i32 6>
  %35 = getelementptr inbounds i32, i32* %2, i64 %26, !dbg !19
  %36 = bitcast i32* %35 to <4 x i32>*, !dbg !20
  store <4 x i32> %29, <4 x i32>* %36, align 4, !dbg !20, !tbaa !14
  %37 = getelementptr inbounds i32, i32* %35, i64 4, !dbg !20
  %38 = bitcast i32* %37 to <4 x i32>*, !dbg !20
  store <4 x i32> %32, <4 x i32>* %38, align 4, !dbg !20, !tbaa !14
  %39 = getelementptr inbounds i32, i32* %0, i64 %26, !dbg !21
  %40 = bitcast i32* %39 to <4 x i32>*, !dbg !22
  store <4 x i32> %33, <4 x i32>* %40, align 4, !dbg !22, !tbaa !14
  %41 = getelementptr inbounds i32, i32* %39, i64 4, !dbg !22
  %42 = bitcast i32* %41 to <4 x i32>*, !dbg !22
  store <4 x i32> %34, <4 x i32>* %42, align 4, !dbg !22, !tbaa !14
  %43 = or i64 %23, 9
  %44 = getelementptr inbounds i32, i32* %1, i64 %43, !dbg !18
  %45 = bitcast i32* %44 to <4 x i32>*, !dbg !18
  %46 = load <4 x i32>, <4 x i32>* %45, align 4, !dbg !18, !tbaa !14
  %47 = getelementptr inbounds i32, i32* %44, i64 4, !dbg !18
  %48 = bitcast i32* %47 to <4 x i32>*, !dbg !18
  %49 = load <4 x i32>, <4 x i32>* %48, align 4, !dbg !18, !tbaa !14
  %50 = shufflevector <4 x i32> %32, <4 x i32> %46, <4 x i32> <i32 3, i32 4, i32 5, i32 6>
  %51 = shufflevector <4 x i32> %46, <4 x i32> %49, <4 x i32> <i32 3, i32 4, i32 5, i32 6>
  %52 = getelementptr inbounds i32, i32* %2, i64 %43, !dbg !19
  %53 = bitcast i32* %52 to <4 x i32>*, !dbg !20
  store <4 x i32> %46, <4 x i32>* %53, align 4, !dbg !20, !tbaa !14
  %54 = getelementptr inbounds i32, i32* %52, i64 4, !dbg !20
  %55 = bitcast i32* %54 to <4 x i32>*, !dbg !20
  store <4 x i32> %49, <4 x i32>* %55, align 4, !dbg !20, !tbaa !14
  %56 = getelementptr inbounds i32, i32* %0, i64 %43, !dbg !21
  %57 = bitcast i32* %56 to <4 x i32>*, !dbg !22
  store <4 x i32> %50, <4 x i32>* %57, align 4, !dbg !22, !tbaa !14
  %58 = getelementptr inbounds i32, i32* %56, i64 4, !dbg !22
  %59 = bitcast i32* %58 to <4 x i32>*, !dbg !22
  store <4 x i32> %51, <4 x i32>* %59, align 4, !dbg !22, !tbaa !14
  %60 = add nuw i64 %23, 16
  %61 = add i64 %25, 2
  %62 = icmp eq i64 %61, %21
  br i1 %62, label %63, label %22, !llvm.loop !23

63:                                               ; preds = %22
  %64 = or i64 %60, 1
  br label %65

65:                                               ; preds = %63, %11
  %66 = phi <4 x i32> [ undef, %11 ], [ %49, %63 ]
  %67 = phi i64 [ 1, %11 ], [ %64, %63 ]
  %68 = phi <4 x i32> [ %14, %11 ], [ %49, %63 ]
  %69 = icmp eq i64 %18, 0
  br i1 %69, label %87, label %70

70:                                               ; preds = %65
  %71 = getelementptr inbounds i32, i32* %1, i64 %67, !dbg !18
  %72 = bitcast i32* %71 to <4 x i32>*, !dbg !18
  %73 = load <4 x i32>, <4 x i32>* %72, align 4, !dbg !18, !tbaa !14
  %74 = getelementptr inbounds i32, i32* %71, i64 4, !dbg !18
  %75 = bitcast i32* %74 to <4 x i32>*, !dbg !18
  %76 = load <4 x i32>, <4 x i32>* %75, align 4, !dbg !18, !tbaa !14
  %77 = shufflevector <4 x i32> %68, <4 x i32> %73, <4 x i32> <i32 3, i32 4, i32 5, i32 6>
  %78 = shufflevector <4 x i32> %73, <4 x i32> %76, <4 x i32> <i32 3, i32 4, i32 5, i32 6>
  %79 = getelementptr inbounds i32, i32* %2, i64 %67, !dbg !19
  %80 = bitcast i32* %79 to <4 x i32>*, !dbg !20
  store <4 x i32> %73, <4 x i32>* %80, align 4, !dbg !20, !tbaa !14
  %81 = getelementptr inbounds i32, i32* %79, i64 4, !dbg !20
  %82 = bitcast i32* %81 to <4 x i32>*, !dbg !20
  store <4 x i32> %76, <4 x i32>* %82, align 4, !dbg !20, !tbaa !14
  %83 = getelementptr inbounds i32, i32* %0, i64 %67, !dbg !21
  %84 = bitcast i32* %83 to <4 x i32>*, !dbg !22
  store <4 x i32> %77, <4 x i32>* %84, align 4, !dbg !22, !tbaa !14
  %85 = getelementptr inbounds i32, i32* %83, i64 4, !dbg !22
  %86 = bitcast i32* %85 to <4 x i32>*, !dbg !22
  store <4 x i32> %78, <4 x i32>* %86, align 4, !dbg !22, !tbaa !14
  br label %87, !dbg !12

87:                                               ; preds = %65, %70
  %88 = phi <4 x i32> [ %66, %65 ], [ %76, %70 ], !dbg !18
  %89 = icmp eq i64 %9, %12, !dbg !12
  %90 = extractelement <4 x i32> %88, i64 3, !dbg !12
  br i1 %89, label %94, label %91, !dbg !12

91:                                               ; preds = %6, %87
  %92 = phi i32 [ %90, %87 ], [ %8, %6 ]
  %93 = phi i64 [ %13, %87 ], [ 1, %6 ]
  br label %95, !dbg !12

94:                                               ; preds = %95, %87, %4
  ret void, !dbg !27

95:                                               ; preds = %91, %95
  %96 = phi i32 [ %99, %95 ], [ %92, %91 ], !dbg !13
  %97 = phi i64 [ %102, %95 ], [ %93, %91 ]
  %98 = getelementptr inbounds i32, i32* %1, i64 %97, !dbg !18
  %99 = load i32, i32* %98, align 4, !dbg !18, !tbaa !14
  %100 = getelementptr inbounds i32, i32* %2, i64 %97, !dbg !19
  store i32 %99, i32* %100, align 4, !dbg !20, !tbaa !14
  %101 = getelementptr inbounds i32, i32* %0, i64 %97, !dbg !21
  store i32 %96, i32* %101, align 4, !dbg !22, !tbaa !14
  %102 = add nuw nsw i64 %97, 1, !dbg !28
  %103 = icmp eq i64 %102, %7, !dbg !11
  br i1 %103, label %94, label %95, !dbg !12, !llvm.loop !29
}

attributes #0 = { nofree norecurse nosync nounwind uwtable "frame-pointer"="none" "min-legal-vector-width"="0" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }

!llvm.dbg.cu = !{!0}
!llvm.module.flags = !{!2, !3, !4, !5, !6}
!llvm.ident = !{!7}

!0 = distinct !DICompileUnit(language: DW_LANG_C99, file: !1, producer: "Ubuntu clang version 14.0.0-1ubuntu1.1", isOptimized: true, runtimeVersion: 0, emissionKind: NoDebug, splitDebugInlining: false, nameTableKind: None)
!1 = !DIFile(filename: "TC240521A2.c", directory: "/mnt/c/data/public/ctl/TCP/TC240521A")
!2 = !{i32 2, !"Debug Info Version", i32 3}
!3 = !{i32 1, !"wchar_size", i32 4}
!4 = !{i32 7, !"PIC Level", i32 2}
!5 = !{i32 7, !"PIE Level", i32 2}
!6 = !{i32 7, !"uwtable", i32 1}
!7 = !{!"Ubuntu clang version 14.0.0-1ubuntu1.1"}
!8 = distinct !DISubprogram(name: "foo", scope: !1, file: !1, line: 1, type: !9, scopeLine: 6, flags: DIFlagPrototyped, spFlags: DISPFlagDefinition | DISPFlagOptimized, unit: !0, retainedNodes: !10)
!9 = !DISubroutineType(types: !10)
!10 = !{}
!11 = !DILocation(line: 7, column: 27, scope: !8)
!12 = !DILocation(line: 7, column: 5, scope: !8)
!13 = !DILocation(line: 9, column: 15, scope: !8)
!14 = !{!15, !15, i64 0}
!15 = !{!"int", !16, i64 0}
!16 = !{!"omnipotent char", !17, i64 0}
!17 = !{!"Simple C/C++ TBAA"}
!18 = !DILocation(line: 8, column: 15, scope: !8)
!19 = !DILocation(line: 8, column: 8, scope: !8)
!20 = !DILocation(line: 8, column: 13, scope: !8)
!21 = !DILocation(line: 9, column: 8, scope: !8)
!22 = !DILocation(line: 9, column: 13, scope: !8)
!23 = distinct !{!23, !12, !24, !25, !26}
!24 = !DILocation(line: 10, column: 5, scope: !8)
!25 = !{!"llvm.loop.mustprogress"}
!26 = !{!"llvm.loop.isvectorized", i32 1}
!27 = !DILocation(line: 11, column: 1, scope: !8)
!28 = !DILocation(line: 7, column: 32, scope: !8)
!29 = distinct !{!29, !12, !24, !25, !30, !26}
!30 = !{!"llvm.loop.unroll.runtime.disable"}
