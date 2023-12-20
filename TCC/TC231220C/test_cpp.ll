; ModuleID = 'test.c'
source_filename = "test.c"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

%struct.S1 = type { i32, i64 }
%struct.S2 = type { float, double, %struct.S1 }

; Function Attrs: mustprogress nofree norecurse nosync nounwind readnone uwtable willreturn
define dso_local noundef i32 @_Z3fooi(i32 noundef %0) local_unnamed_addr #0 {
  ret i32 2
}

; Function Attrs: mustprogress nofree norecurse nosync nounwind uwtable willreturn
define dso_local noundef i32 @_Z4foo2P2S1P2S2(%struct.S1* nocapture noundef %0, %struct.S2* nocapture noundef writeonly %1) local_unnamed_addr #1 {
  %3 = getelementptr inbounds %struct.S1, %struct.S1* %0, i64 0, i32 0
  store i32 1, i32* %3, align 8, !tbaa !5
  %4 = getelementptr inbounds %struct.S2, %struct.S2* %1, i64 0, i32 2, i32 0
  store i32 2, i32* %4, align 8, !tbaa !11
  %5 = load i32, i32* %3, align 8, !tbaa !5
  ret i32 %5
}

attributes #0 = { mustprogress nofree norecurse nosync nounwind readnone uwtable willreturn "frame-pointer"="none" "min-legal-vector-width"="0" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #1 = { mustprogress nofree norecurse nosync nounwind uwtable willreturn "frame-pointer"="none" "min-legal-vector-width"="0" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }

!llvm.module.flags = !{!0, !1, !2, !3}
!llvm.ident = !{!4}

!0 = !{i32 1, !"wchar_size", i32 4}
!1 = !{i32 7, !"PIC Level", i32 2}
!2 = !{i32 7, !"PIE Level", i32 2}
!3 = !{i32 7, !"uwtable", i32 1}
!4 = !{!"Ubuntu clang version 14.0.6"}
!5 = !{!6, !7, i64 0}
!6 = !{!"_ZTS2S1", !7, i64 0, !10, i64 8}
!7 = !{!"int", !8, i64 0}
!8 = !{!"omnipotent char", !9, i64 0}
!9 = !{!"Simple C++ TBAA"}
!10 = !{!"long", !8, i64 0}
!11 = !{!12, !7, i64 16}
!12 = !{!"_ZTS2S2", !13, i64 0, !14, i64 8, !6, i64 16}
!13 = !{!"float", !8, i64 0}
!14 = !{!"double", !8, i64 0}
