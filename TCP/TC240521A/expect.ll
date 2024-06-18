target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

; Function Attrs: nofree norecurse nosync nounwind uwtable
define dso_local void @foo(i32* noalias nocapture noundef writeonly %0, i32* noalias nocapture noundef readonly %1, i32* noalias nocapture noundef %2, i32 noundef %3) local_unnamed_addr #0 !dbg !8 {
  %5 = icmp ugt i32 %3, 1, !dbg !11
  br i1 %5, label %6, label %30, !dbg !12

6:                                                ; preds = %4
  %7 = zext i32 %3 to i64, !dbg !11
  %8 = load i32, i32* %2, align 4, !dbg !13, !tbaa !14
  %9 = add nsw i64 %7, -1, !dbg !12
  %10 = add nsw i64 %7, -2, !dbg !12
  %11 = and i64 %9, 3, !dbg !12
  %12 = icmp ult i64 %10, 3, !dbg !12
  br i1 %12, label %15, label %13, !dbg !12

13:                                               ; preds = %6
  %14 = and i64 %9, -4, !dbg !12
  br label %31, !dbg !12

15:                                               ; preds = %31, %6
  %16 = phi i32 [ %8, %6 ], [ %52, %31 ]
  %17 = phi i64 [ 1, %6 ], [ %54, %31 ]
  %18 = icmp eq i64 %11, 0, !dbg !12
  br i1 %18, label %30, label %19, !dbg !12

19:                                               ; preds = %15, %19
  %20 = phi i32 [ %25, %19 ], [ %16, %15 ], !dbg !13
  %21 = phi i64 [ %27, %19 ], [ %17, %15 ]
  %22 = phi i64 [ %28, %19 ], [ 0, %15 ]
  %23 = getelementptr inbounds i32, i32* %0, i64 %21, !dbg !18
  store i32 %20, i32* %23, align 4, !dbg !19, !tbaa !14
  %24 = getelementptr inbounds i32, i32* %1, i64 %21, !dbg !20
  %25 = load i32, i32* %24, align 4, !dbg !20, !tbaa !14
  %26 = getelementptr inbounds i32, i32* %2, i64 %21, !dbg !21
  store i32 %25, i32* %26, align 4, !dbg !22, !tbaa !14
  %27 = add nuw nsw i64 %21, 1, !dbg !23
  %28 = add i64 %22, 1, !dbg !12
  %29 = icmp eq i64 %28, %11, !dbg !12
  br i1 %29, label %30, label %19, !dbg !12, !llvm.loop !24

30:                                               ; preds = %15, %19, %4
  ret void, !dbg !26

31:                                               ; preds = %31, %13
  %32 = phi i32 [ %8, %13 ], [ %52, %31 ], !dbg !13
  %33 = phi i64 [ 1, %13 ], [ %54, %31 ]
  %34 = phi i64 [ 0, %13 ], [ %55, %31 ]
  %35 = getelementptr inbounds i32, i32* %0, i64 %33, !dbg !18
  store i32 %32, i32* %35, align 4, !dbg !19, !tbaa !14
  %36 = getelementptr inbounds i32, i32* %1, i64 %33, !dbg !20
  %37 = load i32, i32* %36, align 4, !dbg !20, !tbaa !14
  %38 = getelementptr inbounds i32, i32* %2, i64 %33, !dbg !21
  store i32 %37, i32* %38, align 4, !dbg !22, !tbaa !14
  %39 = add nuw nsw i64 %33, 1, !dbg !23
  %40 = getelementptr inbounds i32, i32* %0, i64 %39, !dbg !18
  store i32 %37, i32* %40, align 4, !dbg !19, !tbaa !14
  %41 = getelementptr inbounds i32, i32* %1, i64 %39, !dbg !20
  %42 = load i32, i32* %41, align 4, !dbg !20, !tbaa !14
  %43 = getelementptr inbounds i32, i32* %2, i64 %39, !dbg !21
  store i32 %42, i32* %43, align 4, !dbg !22, !tbaa !14
  %44 = add nuw nsw i64 %33, 2, !dbg !23
  %45 = getelementptr inbounds i32, i32* %0, i64 %44, !dbg !18
  store i32 %42, i32* %45, align 4, !dbg !19, !tbaa !14
  %46 = getelementptr inbounds i32, i32* %1, i64 %44, !dbg !20
  %47 = load i32, i32* %46, align 4, !dbg !20, !tbaa !14
  %48 = getelementptr inbounds i32, i32* %2, i64 %44, !dbg !21
  store i32 %47, i32* %48, align 4, !dbg !22, !tbaa !14
  %49 = add nuw nsw i64 %33, 3, !dbg !23
  %50 = getelementptr inbounds i32, i32* %0, i64 %49, !dbg !18
  store i32 %47, i32* %50, align 4, !dbg !19, !tbaa !14
  %51 = getelementptr inbounds i32, i32* %1, i64 %49, !dbg !20
  %52 = load i32, i32* %51, align 4, !dbg !20, !tbaa !14
  %53 = getelementptr inbounds i32, i32* %2, i64 %49, !dbg !21
  store i32 %52, i32* %53, align 4, !dbg !22, !tbaa !14
  %54 = add nuw nsw i64 %33, 4, !dbg !23
  %55 = add i64 %34, 4, !dbg !12
  %56 = icmp eq i64 %55, %14, !dbg !12
  br i1 %56, label %15, label %31, !dbg !12, !llvm.loop !27
}

attributes #0 = { nofree norecurse nosync nounwind uwtable "frame-pointer"="none" "min-legal-vector-width"="0" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }

!llvm.dbg.cu = !{!0}
!llvm.module.flags = !{!2, !3, !4, !5, !6}
!llvm.ident = !{!7}

!1 = !DIFile(filename: "TC240521A.c", directory: "/mnt/c/data/public/ctl/TCP/TC240521A")
!2 = !{i32 2, !"Debug Info Version", i32 3}
!3 = !{i32 1, !"wchar_size", i32 4}
!4 = !{i32 7, !"PIC Level", i32 2}
!5 = !{i32 7, !"PIE Level", i32 2}
!6 = !{i32 7, !"uwtable", i32 1}
!8 = distinct !DISubprogram(name: "foo", scope: !1, file: !1, line: 1, type: !9, scopeLine: 6, flags: DIFlagPrototyped, spFlags: DISPFlagDefinition | DISPFlagOptimized, unit: !0, retainedNodes: !10)
!9 = !DISubroutineType(types: !10)
!10 = !{}
!11 = !DILocation(line: 7, column: 27, scope: !8)
!12 = !DILocation(line: 7, column: 5, scope: !8)
!13 = !DILocation(line: 8, column: 15, scope: !8)
!14 = !{!15, !15, i64 0}
!15 = !{!"int", !16, i64 0}
!16 = !{!"omnipotent char", !17, i64 0}
!17 = !{!"Simple C/C++ TBAA"}
!18 = !DILocation(line: 8, column: 8, scope: !8)
!19 = !DILocation(line: 8, column: 13, scope: !8)
!20 = !DILocation(line: 9, column: 15, scope: !8)
!21 = !DILocation(line: 9, column: 8, scope: !8)
!22 = !DILocation(line: 9, column: 13, scope: !8)
!23 = !DILocation(line: 7, column: 32, scope: !8)
!24 = distinct !{!24, !25}
!25 = !{!"llvm.loop.unroll.disable"}
!26 = !DILocation(line: 11, column: 1, scope: !8)
!27 = distinct !{!27, !12, !28, !29}
!28 = !DILocation(line: 10, column: 5, scope: !8)
!29 = !{!"llvm.loop.mustprogress"}
