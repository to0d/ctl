; ModuleID = 'hello.cpp'
source_filename = "hello.cpp"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

%struct.XX = type { i32 }

@.str = private unnamed_addr constant [5 x i8] c"x=%d\00", align 1
@.str.1 = private unnamed_addr constant [5 x i8] c"x=%f\00", align 1
@.str.2 = private unnamed_addr constant [5 x i8] c"y=%d\00", align 1

; Function Attrs: mustprogress noinline optnone uwtable
define dso_local void @_Z3fooP2XXRS_(%struct.XX* noundef %0, %struct.XX* noundef nonnull align 4 dereferenceable(4) %1) #0 !dbg !10 {
  %3 = alloca %struct.XX*, align 8
  %4 = alloca %struct.XX*, align 8
  %5 = alloca %struct.XX, align 4
  store %struct.XX* %0, %struct.XX** %3, align 8
  call void @llvm.dbg.declare(metadata %struct.XX** %3, metadata !20, metadata !DIExpression()), !dbg !21
  store %struct.XX* %1, %struct.XX** %4, align 8
  call void @llvm.dbg.declare(metadata %struct.XX** %4, metadata !22, metadata !DIExpression()), !dbg !23
  call void @llvm.dbg.declare(metadata %struct.XX* %5, metadata !24, metadata !DIExpression()), !dbg !25
  %6 = load %struct.XX*, %struct.XX** %3, align 8, !dbg !26
  %7 = getelementptr inbounds %struct.XX, %struct.XX* %6, i32 0, i32 0, !dbg !27
  %8 = load i32, i32* %7, align 4, !dbg !27
  %9 = call i32 (i8*, ...) @printf(i8* noundef getelementptr inbounds ([5 x i8], [5 x i8]* @.str, i64 0, i64 0), i32 noundef %8), !dbg !28
  %10 = load %struct.XX*, %struct.XX** %4, align 8, !dbg !29
  %11 = getelementptr inbounds %struct.XX, %struct.XX* %10, i32 0, i32 0, !dbg !30
  %12 = load i32, i32* %11, align 4, !dbg !30
  %13 = call i32 (i8*, ...) @printf(i8* noundef getelementptr inbounds ([5 x i8], [5 x i8]* @.str, i64 0, i64 0), i32 noundef %12), !dbg !31
  %14 = getelementptr inbounds %struct.XX, %struct.XX* %5, i32 0, i32 0, !dbg !32
  %15 = load i32, i32* %14, align 4, !dbg !32
  %16 = call i32 (i8*, ...) @printf(i8* noundef getelementptr inbounds ([5 x i8], [5 x i8]* @.str, i64 0, i64 0), i32 noundef %15), !dbg !33
  ret void, !dbg !34
}

; Function Attrs: nofree nosync nounwind readnone speculatable willreturn
declare void @llvm.dbg.declare(metadata, metadata, metadata) #1

declare i32 @printf(i8* noundef, ...) #2

; Function Attrs: mustprogress noinline optnone uwtable
define dso_local void @_Z4foo2Pdi(double* noundef %0, i32 noundef %1) #0 !dbg !35 {
  %3 = alloca double*, align 8
  %4 = alloca i32, align 4
  store double* %0, double** %3, align 8
  call void @llvm.dbg.declare(metadata double** %3, metadata !40, metadata !DIExpression()), !dbg !41
  store i32 %1, i32* %4, align 4
  call void @llvm.dbg.declare(metadata i32* %4, metadata !42, metadata !DIExpression()), !dbg !43
  %5 = load double*, double** %3, align 8, !dbg !44
  %6 = load double, double* %5, align 8, !dbg !45
  %7 = call i32 (i8*, ...) @printf(i8* noundef getelementptr inbounds ([5 x i8], [5 x i8]* @.str.1, i64 0, i64 0), double noundef %6), !dbg !46
  %8 = load i32, i32* %4, align 4, !dbg !47
  %9 = call i32 (i8*, ...) @printf(i8* noundef getelementptr inbounds ([5 x i8], [5 x i8]* @.str.2, i64 0, i64 0), i32 noundef %8), !dbg !48
  ret void, !dbg !49
}

attributes #0 = { mustprogress noinline optnone uwtable "frame-pointer"="all" "min-legal-vector-width"="0" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #1 = { nofree nosync nounwind readnone speculatable willreturn }
attributes #2 = { "frame-pointer"="all" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }

!llvm.dbg.cu = !{!0}
!llvm.module.flags = !{!2, !3, !4, !5, !6, !7, !8}
!llvm.ident = !{!9}

!0 = distinct !DICompileUnit(language: DW_LANG_C_plus_plus_14, file: !1, producer: "Ubuntu clang version 14.0.6", isOptimized: false, runtimeVersion: 0, emissionKind: FullDebug, splitDebugInlining: false, nameTableKind: None)
!1 = !DIFile(filename: "hello.cpp", directory: "/mnt/c/data/public/ctl/TCC/TC231222B", checksumkind: CSK_MD5, checksum: "8588751918efac098c392aabbeaf11ed")
!2 = !{i32 7, !"Dwarf Version", i32 5}
!3 = !{i32 2, !"Debug Info Version", i32 3}
!4 = !{i32 1, !"wchar_size", i32 4}
!5 = !{i32 7, !"PIC Level", i32 2}
!6 = !{i32 7, !"PIE Level", i32 2}
!7 = !{i32 7, !"uwtable", i32 1}
!8 = !{i32 7, !"frame-pointer", i32 2}
!9 = !{!"Ubuntu clang version 14.0.6"}
!10 = distinct !DISubprogram(name: "foo", linkageName: "_Z3fooP2XXRS_", scope: !1, file: !1, line: 8, type: !11, scopeLine: 8, flags: DIFlagPrototyped, spFlags: DISPFlagDefinition, unit: !0, retainedNodes: !19)
!11 = !DISubroutineType(types: !12)
!12 = !{null, !13, !18}
!13 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: !14, size: 64)
!14 = distinct !DICompositeType(tag: DW_TAG_structure_type, name: "XX", file: !1, line: 3, size: 32, flags: DIFlagTypePassByValue, elements: !15, identifier: "_ZTS2XX")
!15 = !{!16}
!16 = !DIDerivedType(tag: DW_TAG_member, name: "val", scope: !14, file: !1, line: 5, baseType: !17, size: 32)
!17 = !DIBasicType(name: "int", size: 32, encoding: DW_ATE_signed)
!18 = !DIDerivedType(tag: DW_TAG_reference_type, baseType: !14, size: 64)
!19 = !{}
!20 = !DILocalVariable(name: "x1", arg: 1, scope: !10, file: !1, line: 8, type: !13)
!21 = !DILocation(line: 8, column: 14, scope: !10)
!22 = !DILocalVariable(name: "x2", arg: 2, scope: !10, file: !1, line: 8, type: !18)
!23 = !DILocation(line: 8, column: 22, scope: !10)
!24 = !DILocalVariable(name: "x3", scope: !10, file: !1, line: 9, type: !14)
!25 = !DILocation(line: 9, column: 8, scope: !10)
!26 = !DILocation(line: 11, column: 20, scope: !10)
!27 = !DILocation(line: 11, column: 24, scope: !10)
!28 = !DILocation(line: 11, column: 5, scope: !10)
!29 = !DILocation(line: 12, column: 20, scope: !10)
!30 = !DILocation(line: 12, column: 23, scope: !10)
!31 = !DILocation(line: 12, column: 5, scope: !10)
!32 = !DILocation(line: 13, column: 23, scope: !10)
!33 = !DILocation(line: 13, column: 5, scope: !10)
!34 = !DILocation(line: 14, column: 1, scope: !10)
!35 = distinct !DISubprogram(name: "foo2", linkageName: "_Z4foo2Pdi", scope: !1, file: !1, line: 17, type: !36, scopeLine: 17, flags: DIFlagPrototyped, spFlags: DISPFlagDefinition, unit: !0, retainedNodes: !19)
!36 = !DISubroutineType(types: !37)
!37 = !{null, !38, !17}
!38 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: !39, size: 64)
!39 = !DIBasicType(name: "double", size: 64, encoding: DW_ATE_float)
!40 = !DILocalVariable(name: "x", arg: 1, scope: !35, file: !1, line: 17, type: !38)
!41 = !DILocation(line: 17, column: 19, scope: !35)
!42 = !DILocalVariable(name: "y", arg: 2, scope: !35, file: !1, line: 17, type: !17)
!43 = !DILocation(line: 17, column: 26, scope: !35)
!44 = !DILocation(line: 18, column: 21, scope: !35)
!45 = !DILocation(line: 18, column: 20, scope: !35)
!46 = !DILocation(line: 18, column: 5, scope: !35)
!47 = !DILocation(line: 19, column: 20, scope: !35)
!48 = !DILocation(line: 19, column: 5, scope: !35)
!49 = !DILocation(line: 20, column: 1, scope: !35)
