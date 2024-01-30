; ModuleID = '/mnt/c/data/work_thu/code_thu/hpcc/test/TC231206B/input.cpp.4.tmp.cpp'
source_filename = "/mnt/c/data/work_thu/code_thu/hpcc/test/TC231206B/input.cpp.4.tmp.cpp"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

%class.Simdcore_param_type = type { i8 }
%class.Pack_param_type = type { i8 }
%class.InitInstr = type { i8 }
%class.LoadInstr = type { i8 }
%class.StoreInstr = type { i8 }
%class.GemmInstr = type { i8 }
%class.VectorInstr = type { i8 }

@Simdcore_param = dso_local global %class.Simdcore_param_type zeroinitializer, align 1, !dbg !0
@Pack_param = dso_local global %class.Pack_param_type zeroinitializer, align 1, !dbg !5
@.str.1 = private unnamed_addr constant [5 x i8] c"simd\00", align 1
@.str.2 = private unnamed_addr constant [5 x i8] c"acti\00", align 1
@.str.3 = private unnamed_addr constant [7 x i8] c"double\00", align 1
@.str.4 = private unnamed_addr constant [4 x i8] c"wgt\00", align 1
@.str.5 = private unnamed_addr constant [5 x i8] c"bias\00", align 1
@.str.6 = private unnamed_addr constant [5 x i8] c"acto\00", align 1
@.str.7 = private unnamed_addr constant [8 x i8] c"uniform\00", align 1
@.str.8 = private unnamed_addr constant [10 x i8] c"load_func\00", align 1
@.str.9 = private unnamed_addr constant [5 x i8] c"load\00", align 1
@.str.10 = private unnamed_addr constant [10 x i8] c"gemm_func\00", align 1
@.str.11 = private unnamed_addr constant [5 x i8] c"gemm\00", align 1
@__const.main.log_param_vector = private unnamed_addr constant [8 x double] [double 1.000000e-01, double 2.000000e-01, double 3.000000e-01, double 4.000000e-01, double 1.000000e-01, double 2.000000e-01, double 3.000000e-01, double 4.000000e-01], align 16
@.str.12 = private unnamed_addr constant [6 x i8] c"log2x\00", align 1
@.str.13 = private unnamed_addr constant [7 x i8] c"vector\00", align 1
@str = private unnamed_addr constant [9 x i8] c"HW START\00", align 1
@str.15 = private unnamed_addr constant [10 x i8] c"HW finish\00", align 1

; Function Attrs: mustprogress norecurse uwtable
define dso_local noundef i32 @test_1() local_unnamed_addr #0 !dbg !292 {
  %1 = alloca %class.InitInstr, align 1
  %2 = alloca %class.LoadInstr, align 1
  %3 = alloca %class.StoreInstr, align 1
  %4 = alloca %class.GemmInstr, align 1
  %5 = alloca %class.VectorInstr, align 1
  call void @llvm.dbg.declare(metadata i8* undef, metadata !343, metadata !DIExpression()), !dbg !375
  %6 = alloca [8 x double], align 16
  %7 = tail call i32 @puts(i8* nonnull dereferenceable(1) getelementptr inbounds ([9 x i8], [9 x i8]* @str, i64 0, i64 0)), !dbg !376
  call void @llvm.dbg.value(metadata i32 600, metadata !294, metadata !DIExpression()), !dbg !377
  call void @llvm.dbg.value(metadata i32 1204, metadata !295, metadata !DIExpression()), !dbg !377
  call void @llvm.dbg.value(metadata i32 128, metadata !296, metadata !DIExpression()), !dbg !377
  call void @llvm.dbg.value(metadata i32 2, metadata !297, metadata !DIExpression()), !dbg !377
  call void @llvm.dbg.value(metadata i32 3, metadata !298, metadata !DIExpression()), !dbg !377
  call void @llvm.dbg.value(metadata i32 3, metadata !299, metadata !DIExpression()), !dbg !377
  call void @llvm.dbg.value(metadata i32 5, metadata !300, metadata !DIExpression()), !dbg !377
  call void @llvm.dbg.value(metadata i32 300, metadata !301, metadata !DIExpression()), !dbg !377
  call void @llvm.dbg.value(metadata i32 400, metadata !302, metadata !DIExpression()), !dbg !377
  call void @llvm.dbg.value(metadata i32 100, metadata !303, metadata !DIExpression()), !dbg !377
  tail call void @_Z18reg2simd_start_seti(i32 noundef 0), !dbg !378
  %8 = getelementptr inbounds %class.InitInstr, %class.InitInstr* %1, i64 0, i32 0, !dbg !379
  call void @llvm.lifetime.start.p0i8(i64 1, i8* nonnull %8) #7, !dbg !379
  call void @llvm.dbg.declare(metadata %class.InitInstr* %1, metadata !304, metadata !DIExpression()), !dbg !380
  %9 = getelementptr inbounds %class.LoadInstr, %class.LoadInstr* %2, i64 0, i32 0, !dbg !381
  call void @llvm.lifetime.start.p0i8(i64 1, i8* nonnull %9) #7, !dbg !381
  call void @llvm.dbg.declare(metadata %class.LoadInstr* %2, metadata !315, metadata !DIExpression()), !dbg !382
  %10 = getelementptr inbounds %class.StoreInstr, %class.StoreInstr* %3, i64 0, i32 0, !dbg !383
  call void @llvm.lifetime.start.p0i8(i64 1, i8* nonnull %10) #7, !dbg !383
  call void @llvm.dbg.declare(metadata %class.StoreInstr* %3, metadata !322, metadata !DIExpression()), !dbg !384
  %11 = getelementptr inbounds %class.GemmInstr, %class.GemmInstr* %4, i64 0, i32 0, !dbg !385
  call void @llvm.lifetime.start.p0i8(i64 1, i8* nonnull %11) #7, !dbg !385
  call void @llvm.dbg.declare(metadata %class.GemmInstr* %4, metadata !329, metadata !DIExpression()), !dbg !386
  %12 = getelementptr inbounds %class.VectorInstr, %class.VectorInstr* %5, i64 0, i32 0, !dbg !387
  call void @llvm.lifetime.start.p0i8(i64 1, i8* nonnull %12) #7, !dbg !387
  call void @llvm.dbg.declare(metadata %class.VectorInstr* %5, metadata !336, metadata !DIExpression()), !dbg !388
  %13 = tail call noundef i32 @_ZN19Simdcore_param_type6mallocEPKcS1_S1_iii(%class.Simdcore_param_type* noundef nonnull align 1 dereferenceable(1) @Simdcore_param, i8* noundef getelementptr inbounds ([5 x i8], [5 x i8]* @.str.1, i64 0, i64 0), i8* noundef getelementptr inbounds ([5 x i8], [5 x i8]* @.str.2, i64 0, i64 0), i8* noundef getelementptr inbounds ([7 x i8], [7 x i8]* @.str.3, i64 0, i64 0), i32 noundef 600, i32 noundef 1204, i32 noundef 128), !dbg !389
  call void @llvm.dbg.value(metadata i32 %13, metadata !346, metadata !DIExpression()), !dbg !377
  %14 = tail call noundef i32 @_ZN19Simdcore_param_type17get_arranged_addrEPKc(%class.Simdcore_param_type* noundef nonnull align 1 dereferenceable(1) @Simdcore_param, i8* noundef getelementptr inbounds ([5 x i8], [5 x i8]* @.str.2, i64 0, i64 0)), !dbg !390
  call void @llvm.dbg.value(metadata i32 %14, metadata !347, metadata !DIExpression()), !dbg !377
  %15 = tail call noundef i32 @_ZN19Simdcore_param_type6mallocEPKcS1_S1_iii(%class.Simdcore_param_type* noundef nonnull align 1 dereferenceable(1) @Simdcore_param, i8* noundef getelementptr inbounds ([5 x i8], [5 x i8]* @.str.1, i64 0, i64 0), i8* noundef getelementptr inbounds ([4 x i8], [4 x i8]* @.str.4, i64 0, i64 0), i8* noundef getelementptr inbounds ([7 x i8], [7 x i8]* @.str.3, i64 0, i64 0), i32 noundef 1, i32 noundef 400, i32 noundef 768), !dbg !391
  call void @llvm.dbg.value(metadata i32 %15, metadata !348, metadata !DIExpression()), !dbg !377
  %16 = tail call noundef i32 @_ZN19Simdcore_param_type17get_arranged_addrEPKc(%class.Simdcore_param_type* noundef nonnull align 1 dereferenceable(1) @Simdcore_param, i8* noundef getelementptr inbounds ([4 x i8], [4 x i8]* @.str.4, i64 0, i64 0)), !dbg !392
  call void @llvm.dbg.value(metadata i32 %16, metadata !349, metadata !DIExpression()), !dbg !377
  %17 = tail call noundef i32 @_ZN19Simdcore_param_type6mallocEPKcS1_S1_iii(%class.Simdcore_param_type* noundef nonnull align 1 dereferenceable(1) @Simdcore_param, i8* noundef getelementptr inbounds ([5 x i8], [5 x i8]* @.str.1, i64 0, i64 0), i8* noundef getelementptr inbounds ([5 x i8], [5 x i8]* @.str.5, i64 0, i64 0), i8* noundef getelementptr inbounds ([7 x i8], [7 x i8]* @.str.3, i64 0, i64 0), i32 noundef 1, i32 noundef 1, i32 noundef 100), !dbg !393
  call void @llvm.dbg.value(metadata i32 %17, metadata !350, metadata !DIExpression()), !dbg !377
  %18 = tail call noundef i32 @_ZN19Simdcore_param_type17get_arranged_addrEPKc(%class.Simdcore_param_type* noundef nonnull align 1 dereferenceable(1) @Simdcore_param, i8* noundef getelementptr inbounds ([5 x i8], [5 x i8]* @.str.5, i64 0, i64 0)), !dbg !394
  call void @llvm.dbg.value(metadata i32 %18, metadata !351, metadata !DIExpression()), !dbg !377
  %19 = tail call noundef i32 @_ZN19Simdcore_param_type6mallocEPKcS1_S1_iii(%class.Simdcore_param_type* noundef nonnull align 1 dereferenceable(1) @Simdcore_param, i8* noundef getelementptr inbounds ([5 x i8], [5 x i8]* @.str.1, i64 0, i64 0), i8* noundef getelementptr inbounds ([5 x i8], [5 x i8]* @.str.6, i64 0, i64 0), i8* noundef getelementptr inbounds ([7 x i8], [7 x i8]* @.str.3, i64 0, i64 0), i32 noundef 300, i32 noundef 400, i32 noundef 100), !dbg !395
  call void @llvm.dbg.value(metadata i32 %19, metadata !352, metadata !DIExpression()), !dbg !377
  %20 = tail call noundef i32 @_ZN19Simdcore_param_type17get_arranged_addrEPKc(%class.Simdcore_param_type* noundef nonnull align 1 dereferenceable(1) @Simdcore_param, i8* noundef getelementptr inbounds ([5 x i8], [5 x i8]* @.str.6, i64 0, i64 0)), !dbg !396
  call void @llvm.dbg.value(metadata i32 %20, metadata !353, metadata !DIExpression()), !dbg !377
  call void @llvm.dbg.value(metadata i32 0, metadata !354, metadata !DIExpression()), !dbg !397
  %21 = bitcast [8 x double]* %6 to i8*
  %22 = getelementptr inbounds [8 x double], [8 x double]* %6, i64 0, i64 0
  br label %23, !dbg !398

23:                                               ; preds = %0, %23
  %24 = phi i32 [ 0, %0 ], [ %45, %23 ]
  call void @llvm.dbg.value(metadata i32 %24, metadata !354, metadata !DIExpression()), !dbg !397
  call void @_Z12SIMDLOOP_TAGi(i32 noundef 1), !dbg !399
  %25 = call noundef i32 @_ZN15Pack_param_type9settensorEPKc(%class.Pack_param_type* noundef nonnull align 1 dereferenceable(1) @Pack_param, i8* noundef getelementptr inbounds ([8 x i8], [8 x i8]* @.str.7, i64 0, i64 0)), !dbg !400
  call void @llvm.dbg.value(metadata i32 %25, metadata !356, metadata !DIExpression()), !dbg !401
  %26 = call noundef i32 @_ZN19Simdcore_param_type23get_arranged_config_selEPKcS1_(%class.Simdcore_param_type* noundef nonnull align 1 dereferenceable(1) @Simdcore_param, i8* noundef getelementptr inbounds ([10 x i8], [10 x i8]* @.str.8, i64 0, i64 0), i8* noundef getelementptr inbounds ([5 x i8], [5 x i8]* @.str.9, i64 0, i64 0)), !dbg !402
  call void @llvm.dbg.value(metadata i32 %26, metadata !359, metadata !DIExpression()), !dbg !401
  call void @_ZN9InitInstr8loadinitEiiii(%class.InitInstr* noundef nonnull align 1 dereferenceable(1) %1, i32 noundef 102, i32 noundef %25, i32 noundef %26, i32 noundef 65535), !dbg !403
  %27 = call noundef i32 @_ZN19Simdcore_param_type23get_arranged_config_selEPKcS1_(%class.Simdcore_param_type* noundef nonnull align 1 dereferenceable(1) @Simdcore_param, i8* noundef getelementptr inbounds ([5 x i8], [5 x i8]* @.str.2, i64 0, i64 0), i8* noundef getelementptr inbounds ([5 x i8], [5 x i8]* @.str.9, i64 0, i64 0)), !dbg !404
  call void @llvm.dbg.value(metadata i32 %27, metadata !360, metadata !DIExpression()), !dbg !401
  call void @_ZN9InitInstr8loadinitEiiii(%class.InitInstr* noundef nonnull align 1 dereferenceable(1) %1, i32 noundef 104, i32 noundef %27, i32 noundef %13, i32 noundef 65535), !dbg !405
  call void @_ZN9LoadInstr9settensorEiiiii(%class.LoadInstr* noundef nonnull align 1 dereferenceable(1) %2, i32 noundef 105, i32 noundef 123, i32 noundef %14, i32 noundef %27, i32 noundef %26), !dbg !406
  %28 = call noundef i32 @_ZN19Simdcore_param_type23get_arranged_config_selEPKcS1_(%class.Simdcore_param_type* noundef nonnull align 1 dereferenceable(1) @Simdcore_param, i8* noundef getelementptr inbounds ([4 x i8], [4 x i8]* @.str.4, i64 0, i64 0), i8* noundef getelementptr inbounds ([5 x i8], [5 x i8]* @.str.9, i64 0, i64 0)), !dbg !407
  call void @llvm.dbg.value(metadata i32 %28, metadata !361, metadata !DIExpression()), !dbg !401
  call void @_ZN9InitInstr8loadinitEiiii(%class.InitInstr* noundef nonnull align 1 dereferenceable(1) %1, i32 noundef 108, i32 noundef %28, i32 noundef %15, i32 noundef 65535), !dbg !408
  call void @_ZN9LoadInstr9settensorEiiiii(%class.LoadInstr* noundef nonnull align 1 dereferenceable(1) %2, i32 noundef 109, i32 noundef 456, i32 noundef %16, i32 noundef %28, i32 noundef %26), !dbg !409
  %29 = call noundef i32 @_ZN19Simdcore_param_type23get_arranged_config_selEPKcS1_(%class.Simdcore_param_type* noundef nonnull align 1 dereferenceable(1) @Simdcore_param, i8* noundef getelementptr inbounds ([5 x i8], [5 x i8]* @.str.5, i64 0, i64 0), i8* noundef getelementptr inbounds ([5 x i8], [5 x i8]* @.str.9, i64 0, i64 0)), !dbg !410
  call void @llvm.dbg.value(metadata i32 %29, metadata !362, metadata !DIExpression()), !dbg !401
  call void @_ZN9InitInstr8loadinitEiiii(%class.InitInstr* noundef nonnull align 1 dereferenceable(1) %1, i32 noundef 112, i32 noundef %29, i32 noundef %17, i32 noundef 65535), !dbg !411
  call void @_ZN9LoadInstr9settensorEiiiii(%class.LoadInstr* noundef nonnull align 1 dereferenceable(1) %2, i32 noundef 113, i32 noundef 789, i32 noundef %18, i32 noundef %29, i32 noundef %26), !dbg !412
  %30 = call noundef i32 @_ZN15Pack_param_type4convEiiii(%class.Pack_param_type* noundef nonnull align 1 dereferenceable(1) @Pack_param, i32 noundef 2, i32 noundef 3, i32 noundef 3, i32 noundef 5), !dbg !413
  call void @llvm.dbg.value(metadata i32 %30, metadata !363, metadata !DIExpression()), !dbg !401
  %31 = call noundef i32 @_ZN19Simdcore_param_type23get_arranged_config_selEPKcS1_(%class.Simdcore_param_type* noundef nonnull align 1 dereferenceable(1) @Simdcore_param, i8* noundef getelementptr inbounds ([10 x i8], [10 x i8]* @.str.10, i64 0, i64 0), i8* noundef getelementptr inbounds ([5 x i8], [5 x i8]* @.str.11, i64 0, i64 0)), !dbg !414
  call void @llvm.dbg.value(metadata i32 %31, metadata !364, metadata !DIExpression()), !dbg !401
  call void @_ZN9InitInstr8gemminitEiiii(%class.InitInstr* noundef nonnull align 1 dereferenceable(1) %1, i32 noundef 117, i32 noundef %31, i32 noundef %30, i32 noundef 65535), !dbg !415
  %32 = call noundef i32 @_ZN19Simdcore_param_type23get_arranged_config_selEPKcS1_(%class.Simdcore_param_type* noundef nonnull align 1 dereferenceable(1) @Simdcore_param, i8* noundef getelementptr inbounds ([5 x i8], [5 x i8]* @.str.2, i64 0, i64 0), i8* noundef getelementptr inbounds ([5 x i8], [5 x i8]* @.str.11, i64 0, i64 0)), !dbg !416
  call void @llvm.dbg.value(metadata i32 %32, metadata !365, metadata !DIExpression()), !dbg !401
  call void @_ZN9InitInstr8gemminitEiiii(%class.InitInstr* noundef nonnull align 1 dereferenceable(1) %1, i32 noundef 119, i32 noundef %32, i32 noundef %13, i32 noundef 65535), !dbg !417
  %33 = call noundef i32 @_ZN19Simdcore_param_type23get_arranged_config_selEPKcS1_(%class.Simdcore_param_type* noundef nonnull align 1 dereferenceable(1) @Simdcore_param, i8* noundef getelementptr inbounds ([4 x i8], [4 x i8]* @.str.4, i64 0, i64 0), i8* noundef getelementptr inbounds ([5 x i8], [5 x i8]* @.str.11, i64 0, i64 0)), !dbg !418
  call void @llvm.dbg.value(metadata i32 %33, metadata !366, metadata !DIExpression()), !dbg !401
  call void @_ZN9InitInstr8gemminitEiiii(%class.InitInstr* noundef nonnull align 1 dereferenceable(1) %1, i32 noundef 121, i32 noundef %33, i32 noundef %15, i32 noundef 65535), !dbg !419
  %34 = call noundef i32 @_ZN19Simdcore_param_type23get_arranged_config_selEPKcS1_(%class.Simdcore_param_type* noundef nonnull align 1 dereferenceable(1) @Simdcore_param, i8* noundef getelementptr inbounds ([5 x i8], [5 x i8]* @.str.5, i64 0, i64 0), i8* noundef getelementptr inbounds ([5 x i8], [5 x i8]* @.str.11, i64 0, i64 0)), !dbg !420
  call void @llvm.dbg.value(metadata i32 %34, metadata !367, metadata !DIExpression()), !dbg !401
  call void @_ZN9InitInstr8gemminitEiiii(%class.InitInstr* noundef nonnull align 1 dereferenceable(1) %1, i32 noundef 123, i32 noundef %34, i32 noundef %17, i32 noundef 65535), !dbg !421
  %35 = call noundef i32 @_ZN19Simdcore_param_type23get_arranged_config_selEPKcS1_(%class.Simdcore_param_type* noundef nonnull align 1 dereferenceable(1) @Simdcore_param, i8* noundef getelementptr inbounds ([5 x i8], [5 x i8]* @.str.6, i64 0, i64 0), i8* noundef getelementptr inbounds ([5 x i8], [5 x i8]* @.str.11, i64 0, i64 0)), !dbg !422
  call void @llvm.dbg.value(metadata i32 %35, metadata !368, metadata !DIExpression()), !dbg !401
  call void @_ZN9InitInstr8gemminitEiiii(%class.InitInstr* noundef nonnull align 1 dereferenceable(1) %1, i32 noundef 125, i32 noundef %35, i32 noundef %19, i32 noundef 65535), !dbg !423
  call void @_ZN9GemmInstr6conv2dEiiiiiiiiii(%class.GemmInstr* noundef nonnull align 1 dereferenceable(1) %4, i32 noundef 126, i32 noundef %14, i32 noundef %16, i32 noundef %18, i32 noundef %20, i32 noundef %32, i32 noundef %33, i32 noundef %34, i32 noundef %35, i32 noundef %31), !dbg !424
  call void @llvm.lifetime.start.p0i8(i64 64, i8* nonnull %21) #7, !dbg !425
  call void @llvm.dbg.declare(metadata [8 x double]* %6, metadata !369, metadata !DIExpression()), !dbg !426
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* noundef nonnull align 16 dereferenceable(64) %21, i8* noundef nonnull align 16 dereferenceable(64) bitcast ([8 x double]* @__const.main.log_param_vector to i8*), i64 64, i1 false), !dbg !426
  %36 = call noundef i32* @_ZN15Pack_param_type6vectorEPKcPd(%class.Pack_param_type* noundef nonnull align 1 dereferenceable(1) @Pack_param, i8* noundef getelementptr inbounds ([6 x i8], [6 x i8]* @.str.12, i64 0, i64 0), double* noundef nonnull %22), !dbg !427
  call void @llvm.dbg.value(metadata i32* %36, metadata !373, metadata !DIExpression()), !dbg !401
  %37 = load i32, i32* %36, align 4, !dbg !428, !tbaa !429
  call void @_ZN9InitInstr10vectorinitEiiii(%class.InitInstr* noundef nonnull align 1 dereferenceable(1) %1, i32 noundef 131, i32 noundef 0, i32 noundef %37, i32 noundef 65535), !dbg !433
  %38 = getelementptr inbounds i32, i32* %36, i64 1, !dbg !434
  %39 = load i32, i32* %38, align 4, !dbg !435, !tbaa !429
  call void @_ZN9InitInstr10vectorinitEiiii(%class.InitInstr* noundef nonnull align 1 dereferenceable(1) %1, i32 noundef 132, i32 noundef 1, i32 noundef %39, i32 noundef 65535), !dbg !436
  %40 = getelementptr inbounds i32, i32* %36, i64 2, !dbg !437
  %41 = load i32, i32* %40, align 4, !dbg !438, !tbaa !429
  call void @_ZN9InitInstr10vectorinitEiiii(%class.InitInstr* noundef nonnull align 1 dereferenceable(1) %1, i32 noundef 133, i32 noundef 2, i32 noundef %41, i32 noundef 65535), !dbg !439
  %42 = getelementptr inbounds i32, i32* %36, i64 3, !dbg !440
  %43 = load i32, i32* %42, align 4, !dbg !441, !tbaa !429
  call void @_ZN9InitInstr10vectorinitEiiii(%class.InitInstr* noundef nonnull align 1 dereferenceable(1) %1, i32 noundef 134, i32 noundef 3, i32 noundef %43, i32 noundef 65535), !dbg !442
  %44 = call noundef i32 @_ZN19Simdcore_param_type23get_arranged_config_selEPKcS1_(%class.Simdcore_param_type* noundef nonnull align 1 dereferenceable(1) @Simdcore_param, i8* noundef getelementptr inbounds ([5 x i8], [5 x i8]* @.str.6, i64 0, i64 0), i8* noundef getelementptr inbounds ([7 x i8], [7 x i8]* @.str.13, i64 0, i64 0)), !dbg !443
  call void @llvm.dbg.value(metadata i32 %44, metadata !374, metadata !DIExpression()), !dbg !401
  call void @_ZN9InitInstr10vectorinitEiiii(%class.InitInstr* noundef nonnull align 1 dereferenceable(1) %1, i32 noundef 136, i32 noundef %44, i32 noundef %19, i32 noundef 65535), !dbg !444
  call void @_ZN11VectorInstr5log2xEiiiiii(%class.VectorInstr* noundef nonnull align 1 dereferenceable(1) %5, i32 noundef 137, i32 noundef %20, i32 noundef 0, i32 noundef 0, i32 noundef %20, i32 noundef 0), !dbg !445
  call void @_ZN10StoreInstr6finishEi(%class.StoreInstr* noundef nonnull align 1 dereferenceable(1) %3, i32 noundef 139), !dbg !446
  call void @llvm.lifetime.end.p0i8(i64 64, i8* nonnull %21) #7, !dbg !447
  %45 = add nuw nsw i32 %24, 1, !dbg !448
  call void @llvm.dbg.value(metadata i32 %45, metadata !354, metadata !DIExpression()), !dbg !397
  %46 = icmp eq i32 %45, 8, !dbg !449
  br i1 %46, label %47, label %23, !dbg !398, !llvm.loop !450

47:                                               ; preds = %23, %47
  %48 = call noundef i32 @_Z10detect_irqv(), !dbg !454
  %49 = icmp eq i32 %48, 0, !dbg !455
  br i1 %49, label %47, label %50, !dbg !456, !llvm.loop !457

50:                                               ; preds = %47
  call void @_Z18reg2simd_start_clrv(), !dbg !459
  %51 = call i32 @puts(i8* nonnull dereferenceable(1) getelementptr inbounds ([10 x i8], [10 x i8]* @str.15, i64 0, i64 0)), !dbg !460
  call void @llvm.lifetime.end.p0i8(i64 1, i8* nonnull %12) #7, !dbg !461
  call void @llvm.lifetime.end.p0i8(i64 1, i8* nonnull %11) #7, !dbg !461
  call void @llvm.lifetime.end.p0i8(i64 1, i8* nonnull %10) #7, !dbg !461
  call void @llvm.lifetime.end.p0i8(i64 1, i8* nonnull %9) #7, !dbg !461
  call void @llvm.lifetime.end.p0i8(i64 1, i8* nonnull %8) #7, !dbg !461
  ret i32 0, !dbg !462
}

; Function Attrs: argmemonly mustprogress nofree nosync nounwind willreturn
declare void @llvm.lifetime.start.p0i8(i64 immarg, i8* nocapture) #1

; Function Attrs: mustprogress nofree nosync nounwind readnone speculatable willreturn
declare void @llvm.dbg.declare(metadata, metadata, metadata) #2

declare !dbg !463 void @_Z18reg2simd_start_seti(i32 noundef) local_unnamed_addr #3

declare noundef i32 @_ZN19Simdcore_param_type6mallocEPKcS1_S1_iii(%class.Simdcore_param_type* noundef nonnull align 1 dereferenceable(1), i8* noundef, i8* noundef, i8* noundef, i32 noundef, i32 noundef, i32 noundef) local_unnamed_addr #3

declare noundef i32 @_ZN19Simdcore_param_type17get_arranged_addrEPKc(%class.Simdcore_param_type* noundef nonnull align 1 dereferenceable(1), i8* noundef) local_unnamed_addr #3

declare !dbg !466 void @_Z12SIMDLOOP_TAGi(i32 noundef) local_unnamed_addr #3

declare noundef i32 @_ZN15Pack_param_type9settensorEPKc(%class.Pack_param_type* noundef nonnull align 1 dereferenceable(1), i8* noundef) local_unnamed_addr #3

declare noundef i32 @_ZN19Simdcore_param_type23get_arranged_config_selEPKcS1_(%class.Simdcore_param_type* noundef nonnull align 1 dereferenceable(1), i8* noundef, i8* noundef) local_unnamed_addr #3

declare void @_ZN9InitInstr8loadinitEiiii(%class.InitInstr* noundef nonnull align 1 dereferenceable(1), i32 noundef, i32 noundef, i32 noundef, i32 noundef) local_unnamed_addr #3

declare void @_ZN9LoadInstr9settensorEiiiii(%class.LoadInstr* noundef nonnull align 1 dereferenceable(1), i32 noundef, i32 noundef, i32 noundef, i32 noundef, i32 noundef) local_unnamed_addr #3

declare noundef i32 @_ZN15Pack_param_type4convEiiii(%class.Pack_param_type* noundef nonnull align 1 dereferenceable(1), i32 noundef, i32 noundef, i32 noundef, i32 noundef) local_unnamed_addr #3

declare void @_ZN9InitInstr8gemminitEiiii(%class.InitInstr* noundef nonnull align 1 dereferenceable(1), i32 noundef, i32 noundef, i32 noundef, i32 noundef) local_unnamed_addr #3

declare void @_ZN9GemmInstr6conv2dEiiiiiiiiii(%class.GemmInstr* noundef nonnull align 1 dereferenceable(1), i32 noundef, i32 noundef, i32 noundef, i32 noundef, i32 noundef, i32 noundef, i32 noundef, i32 noundef, i32 noundef, i32 noundef) local_unnamed_addr #3

; Function Attrs: argmemonly mustprogress nofree nounwind willreturn
declare void @llvm.memcpy.p0i8.p0i8.i64(i8* noalias nocapture writeonly, i8* noalias nocapture readonly, i64, i1 immarg) #4

declare noundef i32* @_ZN15Pack_param_type6vectorEPKcPd(%class.Pack_param_type* noundef nonnull align 1 dereferenceable(1), i8* noundef, double* noundef) local_unnamed_addr #3

declare void @_ZN9InitInstr10vectorinitEiiii(%class.InitInstr* noundef nonnull align 1 dereferenceable(1), i32 noundef, i32 noundef, i32 noundef, i32 noundef) local_unnamed_addr #3

declare void @_ZN11VectorInstr5log2xEiiiiii(%class.VectorInstr* noundef nonnull align 1 dereferenceable(1), i32 noundef, i32 noundef, i32 noundef, i32 noundef, i32 noundef, i32 noundef) local_unnamed_addr #3

declare void @_ZN10StoreInstr6finishEi(%class.StoreInstr* noundef nonnull align 1 dereferenceable(1), i32 noundef) local_unnamed_addr #3

; Function Attrs: argmemonly mustprogress nofree nosync nounwind willreturn
declare void @llvm.lifetime.end.p0i8(i64 immarg, i8* nocapture) #1

declare !dbg !467 noundef i32 @_Z10detect_irqv() local_unnamed_addr #3

declare !dbg !468 void @_Z18reg2simd_start_clrv() local_unnamed_addr #3

; Function Attrs: nofree nosync nounwind readnone speculatable willreturn
declare void @llvm.dbg.value(metadata, metadata, metadata) #5

; Function Attrs: nofree nounwind
declare noundef i32 @puts(i8* nocapture noundef readonly) local_unnamed_addr #6

attributes #0 = { mustprogress norecurse uwtable "frame-pointer"="none" "min-legal-vector-width"="0" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #1 = { argmemonly mustprogress nofree nosync nounwind willreturn }
attributes #2 = { mustprogress nofree nosync nounwind readnone speculatable willreturn }
attributes #3 = { "frame-pointer"="none" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #4 = { argmemonly mustprogress nofree nounwind willreturn }
attributes #5 = { nofree nosync nounwind readnone speculatable willreturn }
attributes #6 = { nofree nounwind }
attributes #7 = { nounwind }

!llvm.dbg.cu = !{!2}
!llvm.module.flags = !{!285, !286, !287, !288, !289, !290}
!llvm.ident = !{!291}

!0 = !DIGlobalVariableExpression(var: !1, expr: !DIExpression())
!1 = distinct !DIGlobalVariable(name: "Simdcore_param", scope: !2, file: !7, line: 14, type: !273, isLocal: false, isDefinition: true)
!2 = distinct !DICompileUnit(language: DW_LANG_C_plus_plus_14, file: !3, producer: "Ubuntu clang version 14.0.6", isOptimized: true, runtimeVersion: 0, emissionKind: FullDebug, globals: !4, imports: !27, splitDebugInlining: false, nameTableKind: None)
!3 = !DIFile(filename: "/mnt/c/data/work_thu/code_thu/hpcc/test/TC231206B/input.cpp.4.tmp.cpp", directory: "/mnt/c/data/work_thu/code_thu/hpcc/test/TC231206B", checksumkind: CSK_MD5, checksum: "e43c0b0925844bfebb78bae34d252f5d")
!4 = !{!0, !5}
!5 = !DIGlobalVariableExpression(var: !6, expr: !DIExpression())
!6 = distinct !DIGlobalVariable(name: "Pack_param", scope: !2, file: !7, line: 24, type: !8, isLocal: false, isDefinition: true)
!7 = !DIFile(filename: "input.cpp.4.tmp.cpp", directory: "/mnt/c/data/work_thu/code_thu/hpcc/test/TC231206B", checksumkind: CSK_MD5, checksum: "e43c0b0925844bfebb78bae34d252f5d")
!8 = distinct !DICompositeType(tag: DW_TAG_class_type, name: "Pack_param_type", file: !7, line: 16, size: 8, flags: DIFlagTypePassByValue, elements: !9, identifier: "_ZTS15Pack_param_type")
!9 = !{!10, !18, !21}
!10 = !DISubprogram(name: "settensor", linkageName: "_ZN15Pack_param_type9settensorEPKc", scope: !8, file: !7, line: 19, type: !11, scopeLine: 19, flags: DIFlagPublic | DIFlagPrototyped, spFlags: DISPFlagOptimized)
!11 = !DISubroutineType(types: !12)
!12 = !{!13, !14, !15}
!13 = !DIBasicType(name: "int", size: 32, encoding: DW_ATE_signed)
!14 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: !8, size: 64, flags: DIFlagArtificial | DIFlagObjectPointer)
!15 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: !16, size: 64)
!16 = !DIDerivedType(tag: DW_TAG_const_type, baseType: !17)
!17 = !DIBasicType(name: "char", size: 8, encoding: DW_ATE_signed_char)
!18 = !DISubprogram(name: "conv", linkageName: "_ZN15Pack_param_type4convEiiii", scope: !8, file: !7, line: 20, type: !19, scopeLine: 20, flags: DIFlagPublic | DIFlagPrototyped, spFlags: DISPFlagOptimized)
!19 = !DISubroutineType(types: !20)
!20 = !{!13, !14, !13, !13, !13, !13}
!21 = !DISubprogram(name: "vector", linkageName: "_ZN15Pack_param_type6vectorEPKcPd", scope: !8, file: !7, line: 21, type: !22, scopeLine: 21, flags: DIFlagPublic | DIFlagPrototyped, spFlags: DISPFlagOptimized)
!22 = !DISubroutineType(types: !23)
!23 = !{!24, !14, !15, !25}
!24 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: !13, size: 64)
!25 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: !26, size: 64)
!26 = !DIBasicType(name: "double", size: 64, encoding: DW_ATE_float)
!27 = !{!28, !91, !97, !102, !106, !108, !110, !112, !114, !121, !126, !131, !135, !139, !143, !148, !152, !154, !158, !164, !168, !175, !177, !182, !186, !190, !192, !196, !200, !202, !206, !208, !210, !214, !218, !222, !226, !230, !234, !236, !243, !247, !251, !256, !258, !260, !264, !268, !269, !270, !271, !272}
!28 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !29, entity: !30, file: !90, line: 98)
!29 = !DINamespace(name: "std", scope: null)
!30 = !DIDerivedType(tag: DW_TAG_typedef, name: "FILE", file: !31, line: 7, baseType: !32)
!31 = !DIFile(filename: "/usr/include/x86_64-linux-gnu/bits/types/FILE.h", directory: "", checksumkind: CSK_MD5, checksum: "571f9fb6223c42439075fdde11a0de5d")
!32 = distinct !DICompositeType(tag: DW_TAG_structure_type, name: "_IO_FILE", file: !33, line: 49, size: 1728, flags: DIFlagTypePassByValue, elements: !34, identifier: "_ZTS8_IO_FILE")
!33 = !DIFile(filename: "/usr/include/x86_64-linux-gnu/bits/types/struct_FILE.h", directory: "", checksumkind: CSK_MD5, checksum: "f3c970561f3408448ce03a9676ead8f4")
!34 = !{!35, !36, !38, !39, !40, !41, !42, !43, !44, !45, !46, !47, !48, !51, !53, !54, !55, !59, !61, !63, !67, !70, !72, !75, !78, !79, !81, !85, !86}
!35 = !DIDerivedType(tag: DW_TAG_member, name: "_flags", scope: !32, file: !33, line: 51, baseType: !13, size: 32)
!36 = !DIDerivedType(tag: DW_TAG_member, name: "_IO_read_ptr", scope: !32, file: !33, line: 54, baseType: !37, size: 64, offset: 64)
!37 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: !17, size: 64)
!38 = !DIDerivedType(tag: DW_TAG_member, name: "_IO_read_end", scope: !32, file: !33, line: 55, baseType: !37, size: 64, offset: 128)
!39 = !DIDerivedType(tag: DW_TAG_member, name: "_IO_read_base", scope: !32, file: !33, line: 56, baseType: !37, size: 64, offset: 192)
!40 = !DIDerivedType(tag: DW_TAG_member, name: "_IO_write_base", scope: !32, file: !33, line: 57, baseType: !37, size: 64, offset: 256)
!41 = !DIDerivedType(tag: DW_TAG_member, name: "_IO_write_ptr", scope: !32, file: !33, line: 58, baseType: !37, size: 64, offset: 320)
!42 = !DIDerivedType(tag: DW_TAG_member, name: "_IO_write_end", scope: !32, file: !33, line: 59, baseType: !37, size: 64, offset: 384)
!43 = !DIDerivedType(tag: DW_TAG_member, name: "_IO_buf_base", scope: !32, file: !33, line: 60, baseType: !37, size: 64, offset: 448)
!44 = !DIDerivedType(tag: DW_TAG_member, name: "_IO_buf_end", scope: !32, file: !33, line: 61, baseType: !37, size: 64, offset: 512)
!45 = !DIDerivedType(tag: DW_TAG_member, name: "_IO_save_base", scope: !32, file: !33, line: 64, baseType: !37, size: 64, offset: 576)
!46 = !DIDerivedType(tag: DW_TAG_member, name: "_IO_backup_base", scope: !32, file: !33, line: 65, baseType: !37, size: 64, offset: 640)
!47 = !DIDerivedType(tag: DW_TAG_member, name: "_IO_save_end", scope: !32, file: !33, line: 66, baseType: !37, size: 64, offset: 704)
!48 = !DIDerivedType(tag: DW_TAG_member, name: "_markers", scope: !32, file: !33, line: 68, baseType: !49, size: 64, offset: 768)
!49 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: !50, size: 64)
!50 = !DICompositeType(tag: DW_TAG_structure_type, name: "_IO_marker", file: !33, line: 36, flags: DIFlagFwdDecl | DIFlagNonTrivial, identifier: "_ZTS10_IO_marker")
!51 = !DIDerivedType(tag: DW_TAG_member, name: "_chain", scope: !32, file: !33, line: 70, baseType: !52, size: 64, offset: 832)
!52 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: !32, size: 64)
!53 = !DIDerivedType(tag: DW_TAG_member, name: "_fileno", scope: !32, file: !33, line: 72, baseType: !13, size: 32, offset: 896)
!54 = !DIDerivedType(tag: DW_TAG_member, name: "_flags2", scope: !32, file: !33, line: 73, baseType: !13, size: 32, offset: 928)
!55 = !DIDerivedType(tag: DW_TAG_member, name: "_old_offset", scope: !32, file: !33, line: 74, baseType: !56, size: 64, offset: 960)
!56 = !DIDerivedType(tag: DW_TAG_typedef, name: "__off_t", file: !57, line: 152, baseType: !58)
!57 = !DIFile(filename: "/usr/include/x86_64-linux-gnu/bits/types.h", directory: "", checksumkind: CSK_MD5, checksum: "f6304b1a6dcfc6bee76e9a51043b5090")
!58 = !DIBasicType(name: "long", size: 64, encoding: DW_ATE_signed)
!59 = !DIDerivedType(tag: DW_TAG_member, name: "_cur_column", scope: !32, file: !33, line: 77, baseType: !60, size: 16, offset: 1024)
!60 = !DIBasicType(name: "unsigned short", size: 16, encoding: DW_ATE_unsigned)
!61 = !DIDerivedType(tag: DW_TAG_member, name: "_vtable_offset", scope: !32, file: !33, line: 78, baseType: !62, size: 8, offset: 1040)
!62 = !DIBasicType(name: "signed char", size: 8, encoding: DW_ATE_signed_char)
!63 = !DIDerivedType(tag: DW_TAG_member, name: "_shortbuf", scope: !32, file: !33, line: 79, baseType: !64, size: 8, offset: 1048)
!64 = !DICompositeType(tag: DW_TAG_array_type, baseType: !17, size: 8, elements: !65)
!65 = !{!66}
!66 = !DISubrange(count: 1)
!67 = !DIDerivedType(tag: DW_TAG_member, name: "_lock", scope: !32, file: !33, line: 81, baseType: !68, size: 64, offset: 1088)
!68 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: !69, size: 64)
!69 = !DIDerivedType(tag: DW_TAG_typedef, name: "_IO_lock_t", file: !33, line: 43, baseType: null)
!70 = !DIDerivedType(tag: DW_TAG_member, name: "_offset", scope: !32, file: !33, line: 89, baseType: !71, size: 64, offset: 1152)
!71 = !DIDerivedType(tag: DW_TAG_typedef, name: "__off64_t", file: !57, line: 153, baseType: !58)
!72 = !DIDerivedType(tag: DW_TAG_member, name: "_codecvt", scope: !32, file: !33, line: 91, baseType: !73, size: 64, offset: 1216)
!73 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: !74, size: 64)
!74 = !DICompositeType(tag: DW_TAG_structure_type, name: "_IO_codecvt", file: !33, line: 37, flags: DIFlagFwdDecl | DIFlagNonTrivial, identifier: "_ZTS11_IO_codecvt")
!75 = !DIDerivedType(tag: DW_TAG_member, name: "_wide_data", scope: !32, file: !33, line: 92, baseType: !76, size: 64, offset: 1280)
!76 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: !77, size: 64)
!77 = !DICompositeType(tag: DW_TAG_structure_type, name: "_IO_wide_data", file: !33, line: 38, flags: DIFlagFwdDecl | DIFlagNonTrivial, identifier: "_ZTS13_IO_wide_data")
!78 = !DIDerivedType(tag: DW_TAG_member, name: "_freeres_list", scope: !32, file: !33, line: 93, baseType: !52, size: 64, offset: 1344)
!79 = !DIDerivedType(tag: DW_TAG_member, name: "_freeres_buf", scope: !32, file: !33, line: 94, baseType: !80, size: 64, offset: 1408)
!80 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: null, size: 64)
!81 = !DIDerivedType(tag: DW_TAG_member, name: "__pad5", scope: !32, file: !33, line: 95, baseType: !82, size: 64, offset: 1472)
!82 = !DIDerivedType(tag: DW_TAG_typedef, name: "size_t", file: !83, line: 46, baseType: !84)
!83 = !DIFile(filename: "/usr/lib/llvm-14/lib/clang/14.0.6/include/stddef.h", directory: "", checksumkind: CSK_MD5, checksum: "2499dd2361b915724b073282bea3a7bc")
!84 = !DIBasicType(name: "unsigned long", size: 64, encoding: DW_ATE_unsigned)
!85 = !DIDerivedType(tag: DW_TAG_member, name: "_mode", scope: !32, file: !33, line: 96, baseType: !13, size: 32, offset: 1536)
!86 = !DIDerivedType(tag: DW_TAG_member, name: "_unused2", scope: !32, file: !33, line: 98, baseType: !87, size: 160, offset: 1568)
!87 = !DICompositeType(tag: DW_TAG_array_type, baseType: !17, size: 160, elements: !88)
!88 = !{!89}
!89 = !DISubrange(count: 20)
!90 = !DIFile(filename: "/usr/bin/../lib/gcc/x86_64-linux-gnu/9/../../../../include/c++/9/cstdio", directory: "")
!91 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !29, entity: !92, file: !90, line: 99)
!92 = !DIDerivedType(tag: DW_TAG_typedef, name: "fpos_t", file: !93, line: 84, baseType: !94)
!93 = !DIFile(filename: "/usr/include/stdio.h", directory: "", checksumkind: CSK_MD5, checksum: "5b917eded35ce2507d1e294bf8cb74d7")
!94 = !DIDerivedType(tag: DW_TAG_typedef, name: "__fpos_t", file: !95, line: 14, baseType: !96)
!95 = !DIFile(filename: "/usr/include/x86_64-linux-gnu/bits/types/__fpos_t.h", directory: "", checksumkind: CSK_MD5, checksum: "32de8bdaf3551a6c0a9394f9af4389ce")
!96 = !DICompositeType(tag: DW_TAG_structure_type, name: "_G_fpos_t", file: !95, line: 10, size: 128, flags: DIFlagFwdDecl, identifier: "_ZTS9_G_fpos_t")
!97 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !29, entity: !98, file: !90, line: 101)
!98 = !DISubprogram(name: "clearerr", scope: !93, file: !93, line: 757, type: !99, flags: DIFlagPrototyped, spFlags: DISPFlagOptimized)
!99 = !DISubroutineType(types: !100)
!100 = !{null, !101}
!101 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: !30, size: 64)
!102 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !29, entity: !103, file: !90, line: 102)
!103 = !DISubprogram(name: "fclose", scope: !93, file: !93, line: 213, type: !104, flags: DIFlagPrototyped, spFlags: DISPFlagOptimized)
!104 = !DISubroutineType(types: !105)
!105 = !{!13, !101}
!106 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !29, entity: !107, file: !90, line: 103)
!107 = !DISubprogram(name: "feof", scope: !93, file: !93, line: 759, type: !104, flags: DIFlagPrototyped, spFlags: DISPFlagOptimized)
!108 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !29, entity: !109, file: !90, line: 104)
!109 = !DISubprogram(name: "ferror", scope: !93, file: !93, line: 761, type: !104, flags: DIFlagPrototyped, spFlags: DISPFlagOptimized)
!110 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !29, entity: !111, file: !90, line: 105)
!111 = !DISubprogram(name: "fflush", scope: !93, file: !93, line: 218, type: !104, flags: DIFlagPrototyped, spFlags: DISPFlagOptimized)
!112 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !29, entity: !113, file: !90, line: 106)
!113 = !DISubprogram(name: "fgetc", scope: !93, file: !93, line: 485, type: !104, flags: DIFlagPrototyped, spFlags: DISPFlagOptimized)
!114 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !29, entity: !115, file: !90, line: 107)
!115 = !DISubprogram(name: "fgetpos", scope: !93, file: !93, line: 731, type: !116, flags: DIFlagPrototyped, spFlags: DISPFlagOptimized)
!116 = !DISubroutineType(types: !117)
!117 = !{!13, !118, !119}
!118 = !DIDerivedType(tag: DW_TAG_restrict_type, baseType: !101)
!119 = !DIDerivedType(tag: DW_TAG_restrict_type, baseType: !120)
!120 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: !92, size: 64)
!121 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !29, entity: !122, file: !90, line: 108)
!122 = !DISubprogram(name: "fgets", scope: !93, file: !93, line: 564, type: !123, flags: DIFlagPrototyped, spFlags: DISPFlagOptimized)
!123 = !DISubroutineType(types: !124)
!124 = !{!37, !125, !13, !118}
!125 = !DIDerivedType(tag: DW_TAG_restrict_type, baseType: !37)
!126 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !29, entity: !127, file: !90, line: 109)
!127 = !DISubprogram(name: "fopen", scope: !93, file: !93, line: 246, type: !128, flags: DIFlagPrototyped, spFlags: DISPFlagOptimized)
!128 = !DISubroutineType(types: !129)
!129 = !{!101, !130, !130}
!130 = !DIDerivedType(tag: DW_TAG_restrict_type, baseType: !15)
!131 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !29, entity: !132, file: !90, line: 110)
!132 = !DISubprogram(name: "fprintf", scope: !93, file: !93, line: 326, type: !133, flags: DIFlagPrototyped, spFlags: DISPFlagOptimized)
!133 = !DISubroutineType(types: !134)
!134 = !{!13, !118, !130, null}
!135 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !29, entity: !136, file: !90, line: 111)
!136 = !DISubprogram(name: "fputc", scope: !93, file: !93, line: 521, type: !137, flags: DIFlagPrototyped, spFlags: DISPFlagOptimized)
!137 = !DISubroutineType(types: !138)
!138 = !{!13, !13, !101}
!139 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !29, entity: !140, file: !90, line: 112)
!140 = !DISubprogram(name: "fputs", scope: !93, file: !93, line: 626, type: !141, flags: DIFlagPrototyped, spFlags: DISPFlagOptimized)
!141 = !DISubroutineType(types: !142)
!142 = !{!13, !130, !118}
!143 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !29, entity: !144, file: !90, line: 113)
!144 = !DISubprogram(name: "fread", scope: !93, file: !93, line: 646, type: !145, flags: DIFlagPrototyped, spFlags: DISPFlagOptimized)
!145 = !DISubroutineType(types: !146)
!146 = !{!82, !147, !82, !82, !118}
!147 = !DIDerivedType(tag: DW_TAG_restrict_type, baseType: !80)
!148 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !29, entity: !149, file: !90, line: 114)
!149 = !DISubprogram(name: "freopen", scope: !93, file: !93, line: 252, type: !150, flags: DIFlagPrototyped, spFlags: DISPFlagOptimized)
!150 = !DISubroutineType(types: !151)
!151 = !{!101, !130, !130, !118}
!152 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !29, entity: !153, file: !90, line: 115)
!153 = !DISubprogram(name: "fscanf", linkageName: "__isoc99_fscanf", scope: !93, file: !93, line: 407, type: !133, flags: DIFlagPrototyped, spFlags: DISPFlagOptimized)
!154 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !29, entity: !155, file: !90, line: 116)
!155 = !DISubprogram(name: "fseek", scope: !93, file: !93, line: 684, type: !156, flags: DIFlagPrototyped, spFlags: DISPFlagOptimized)
!156 = !DISubroutineType(types: !157)
!157 = !{!13, !101, !58, !13}
!158 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !29, entity: !159, file: !90, line: 117)
!159 = !DISubprogram(name: "fsetpos", scope: !93, file: !93, line: 736, type: !160, flags: DIFlagPrototyped, spFlags: DISPFlagOptimized)
!160 = !DISubroutineType(types: !161)
!161 = !{!13, !101, !162}
!162 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: !163, size: 64)
!163 = !DIDerivedType(tag: DW_TAG_const_type, baseType: !92)
!164 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !29, entity: !165, file: !90, line: 118)
!165 = !DISubprogram(name: "ftell", scope: !93, file: !93, line: 689, type: !166, flags: DIFlagPrototyped, spFlags: DISPFlagOptimized)
!166 = !DISubroutineType(types: !167)
!167 = !{!58, !101}
!168 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !29, entity: !169, file: !90, line: 119)
!169 = !DISubprogram(name: "fwrite", scope: !93, file: !93, line: 652, type: !170, flags: DIFlagPrototyped, spFlags: DISPFlagOptimized)
!170 = !DISubroutineType(types: !171)
!171 = !{!82, !172, !82, !82, !118}
!172 = !DIDerivedType(tag: DW_TAG_restrict_type, baseType: !173)
!173 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: !174, size: 64)
!174 = !DIDerivedType(tag: DW_TAG_const_type, baseType: null)
!175 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !29, entity: !176, file: !90, line: 120)
!176 = !DISubprogram(name: "getc", scope: !93, file: !93, line: 486, type: !104, flags: DIFlagPrototyped, spFlags: DISPFlagOptimized)
!177 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !29, entity: !178, file: !90, line: 121)
!178 = !DISubprogram(name: "getchar", scope: !179, file: !179, line: 47, type: !180, flags: DIFlagPrototyped, spFlags: DISPFlagOptimized)
!179 = !DIFile(filename: "/usr/include/x86_64-linux-gnu/bits/stdio.h", directory: "", checksumkind: CSK_MD5, checksum: "fe48be26b3c1dd399597f5e6205450c5")
!180 = !DISubroutineType(types: !181)
!181 = !{!13}
!182 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !29, entity: !183, file: !90, line: 126)
!183 = !DISubprogram(name: "perror", scope: !93, file: !93, line: 775, type: !184, flags: DIFlagPrototyped, spFlags: DISPFlagOptimized)
!184 = !DISubroutineType(types: !185)
!185 = !{null, !15}
!186 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !29, entity: !187, file: !90, line: 127)
!187 = !DISubprogram(name: "printf", scope: !93, file: !93, line: 332, type: !188, flags: DIFlagPrototyped, spFlags: DISPFlagOptimized)
!188 = !DISubroutineType(types: !189)
!189 = !{!13, !130, null}
!190 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !29, entity: !191, file: !90, line: 128)
!191 = !DISubprogram(name: "putc", scope: !93, file: !93, line: 522, type: !137, flags: DIFlagPrototyped, spFlags: DISPFlagOptimized)
!192 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !29, entity: !193, file: !90, line: 129)
!193 = !DISubprogram(name: "putchar", scope: !179, file: !179, line: 82, type: !194, flags: DIFlagPrototyped, spFlags: DISPFlagOptimized)
!194 = !DISubroutineType(types: !195)
!195 = !{!13, !13}
!196 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !29, entity: !197, file: !90, line: 130)
!197 = !DISubprogram(name: "puts", scope: !93, file: !93, line: 632, type: !198, flags: DIFlagPrototyped, spFlags: DISPFlagOptimized)
!198 = !DISubroutineType(types: !199)
!199 = !{!13, !15}
!200 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !29, entity: !201, file: !90, line: 131)
!201 = !DISubprogram(name: "remove", scope: !93, file: !93, line: 146, type: !198, flags: DIFlagPrototyped, spFlags: DISPFlagOptimized)
!202 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !29, entity: !203, file: !90, line: 132)
!203 = !DISubprogram(name: "rename", scope: !93, file: !93, line: 148, type: !204, flags: DIFlagPrototyped, spFlags: DISPFlagOptimized)
!204 = !DISubroutineType(types: !205)
!205 = !{!13, !15, !15}
!206 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !29, entity: !207, file: !90, line: 133)
!207 = !DISubprogram(name: "rewind", scope: !93, file: !93, line: 694, type: !99, flags: DIFlagPrototyped, spFlags: DISPFlagOptimized)
!208 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !29, entity: !209, file: !90, line: 134)
!209 = !DISubprogram(name: "scanf", linkageName: "__isoc99_scanf", scope: !93, file: !93, line: 410, type: !188, flags: DIFlagPrototyped, spFlags: DISPFlagOptimized)
!210 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !29, entity: !211, file: !90, line: 135)
!211 = !DISubprogram(name: "setbuf", scope: !93, file: !93, line: 304, type: !212, flags: DIFlagPrototyped, spFlags: DISPFlagOptimized)
!212 = !DISubroutineType(types: !213)
!213 = !{null, !118, !125}
!214 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !29, entity: !215, file: !90, line: 136)
!215 = !DISubprogram(name: "setvbuf", scope: !93, file: !93, line: 308, type: !216, flags: DIFlagPrototyped, spFlags: DISPFlagOptimized)
!216 = !DISubroutineType(types: !217)
!217 = !{!13, !118, !125, !13, !82}
!218 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !29, entity: !219, file: !90, line: 137)
!219 = !DISubprogram(name: "sprintf", scope: !93, file: !93, line: 334, type: !220, flags: DIFlagPrototyped, spFlags: DISPFlagOptimized)
!220 = !DISubroutineType(types: !221)
!221 = !{!13, !125, !130, null}
!222 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !29, entity: !223, file: !90, line: 138)
!223 = !DISubprogram(name: "sscanf", linkageName: "__isoc99_sscanf", scope: !93, file: !93, line: 412, type: !224, flags: DIFlagPrototyped, spFlags: DISPFlagOptimized)
!224 = !DISubroutineType(types: !225)
!225 = !{!13, !130, !130, null}
!226 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !29, entity: !227, file: !90, line: 139)
!227 = !DISubprogram(name: "tmpfile", scope: !93, file: !93, line: 173, type: !228, flags: DIFlagPrototyped, spFlags: DISPFlagOptimized)
!228 = !DISubroutineType(types: !229)
!229 = !{!101}
!230 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !29, entity: !231, file: !90, line: 141)
!231 = !DISubprogram(name: "tmpnam", scope: !93, file: !93, line: 187, type: !232, flags: DIFlagPrototyped, spFlags: DISPFlagOptimized)
!232 = !DISubroutineType(types: !233)
!233 = !{!37, !37}
!234 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !29, entity: !235, file: !90, line: 143)
!235 = !DISubprogram(name: "ungetc", scope: !93, file: !93, line: 639, type: !137, flags: DIFlagPrototyped, spFlags: DISPFlagOptimized)
!236 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !29, entity: !237, file: !90, line: 144)
!237 = !DISubprogram(name: "vfprintf", scope: !93, file: !93, line: 341, type: !238, flags: DIFlagPrototyped, spFlags: DISPFlagOptimized)
!238 = !DISubroutineType(types: !239)
!239 = !{!13, !118, !130, !240}
!240 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: !241, size: 64)
!241 = !DICompositeType(tag: DW_TAG_structure_type, name: "__va_list_tag", file: !242, line: 24, size: 192, flags: DIFlagFwdDecl, identifier: "_ZTS13__va_list_tag")
!242 = !DIFile(filename: "input.cpp.4.tmp.cpp", directory: "/mnt/c/data/work_thu/code_thu/hpcc/test/TC231206B")
!243 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !29, entity: !244, file: !90, line: 145)
!244 = !DISubprogram(name: "vprintf", scope: !179, file: !179, line: 39, type: !245, flags: DIFlagPrototyped, spFlags: DISPFlagOptimized)
!245 = !DISubroutineType(types: !246)
!246 = !{!13, !130, !240}
!247 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !29, entity: !248, file: !90, line: 146)
!248 = !DISubprogram(name: "vsprintf", scope: !93, file: !93, line: 349, type: !249, flags: DIFlagPrototyped, spFlags: DISPFlagOptimized)
!249 = !DISubroutineType(types: !250)
!250 = !{!13, !125, !130, !240}
!251 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !252, entity: !253, file: !90, line: 175)
!252 = !DINamespace(name: "__gnu_cxx", scope: null)
!253 = !DISubprogram(name: "snprintf", scope: !93, file: !93, line: 354, type: !254, flags: DIFlagPrototyped, spFlags: DISPFlagOptimized)
!254 = !DISubroutineType(types: !255)
!255 = !{!13, !125, !82, !130, null}
!256 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !252, entity: !257, file: !90, line: 176)
!257 = !DISubprogram(name: "vfscanf", linkageName: "__isoc99_vfscanf", scope: !93, file: !93, line: 451, type: !238, flags: DIFlagPrototyped, spFlags: DISPFlagOptimized)
!258 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !252, entity: !259, file: !90, line: 177)
!259 = !DISubprogram(name: "vscanf", linkageName: "__isoc99_vscanf", scope: !93, file: !93, line: 456, type: !245, flags: DIFlagPrototyped, spFlags: DISPFlagOptimized)
!260 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !252, entity: !261, file: !90, line: 178)
!261 = !DISubprogram(name: "vsnprintf", scope: !93, file: !93, line: 358, type: !262, flags: DIFlagPrototyped, spFlags: DISPFlagOptimized)
!262 = !DISubroutineType(types: !263)
!263 = !{!13, !125, !82, !130, !240}
!264 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !252, entity: !265, file: !90, line: 179)
!265 = !DISubprogram(name: "vsscanf", linkageName: "__isoc99_vsscanf", scope: !93, file: !93, line: 459, type: !266, flags: DIFlagPrototyped, spFlags: DISPFlagOptimized)
!266 = !DISubroutineType(types: !267)
!267 = !{!13, !130, !130, !240}
!268 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !29, entity: !253, file: !90, line: 185)
!269 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !29, entity: !257, file: !90, line: 186)
!270 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !29, entity: !259, file: !90, line: 187)
!271 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !29, entity: !261, file: !90, line: 188)
!272 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !29, entity: !265, file: !90, line: 189)
!273 = distinct !DICompositeType(tag: DW_TAG_class_type, name: "Simdcore_param_type", file: !7, line: 6, size: 8, flags: DIFlagTypePassByValue, elements: !274, identifier: "_ZTS19Simdcore_param_type")
!274 = !{!275, !279, !282}
!275 = !DISubprogram(name: "malloc", linkageName: "_ZN19Simdcore_param_type6mallocEPKcS1_S1_iii", scope: !273, file: !7, line: 9, type: !276, scopeLine: 9, flags: DIFlagPublic | DIFlagPrototyped, spFlags: DISPFlagOptimized)
!276 = !DISubroutineType(types: !277)
!277 = !{!13, !278, !15, !15, !15, !13, !13, !13}
!278 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: !273, size: 64, flags: DIFlagArtificial | DIFlagObjectPointer)
!279 = !DISubprogram(name: "get_arranged_addr", linkageName: "_ZN19Simdcore_param_type17get_arranged_addrEPKc", scope: !273, file: !7, line: 10, type: !280, scopeLine: 10, flags: DIFlagPublic | DIFlagPrototyped, spFlags: DISPFlagOptimized)
!280 = !DISubroutineType(types: !281)
!281 = !{!13, !278, !15}
!282 = !DISubprogram(name: "get_arranged_config_sel", linkageName: "_ZN19Simdcore_param_type23get_arranged_config_selEPKcS1_", scope: !273, file: !7, line: 11, type: !283, scopeLine: 11, flags: DIFlagPublic | DIFlagPrototyped, spFlags: DISPFlagOptimized)
!283 = !DISubroutineType(types: !284)
!284 = !{!13, !278, !15, !15}
!285 = !{i32 7, !"Dwarf Version", i32 5}
!286 = !{i32 2, !"Debug Info Version", i32 3}
!287 = !{i32 1, !"wchar_size", i32 4}
!288 = !{i32 7, !"PIC Level", i32 2}
!289 = !{i32 7, !"PIE Level", i32 2}
!290 = !{i32 7, !"uwtable", i32 1}
!291 = !{!"Ubuntu clang version 14.0.6"}
!292 = distinct !DISubprogram(name: "test_1", scope: !7, file: !7, line: 77, type: !180, scopeLine: 78, flags: DIFlagPrototyped | DIFlagAllCallsDescribed, spFlags: DISPFlagDefinition | DISPFlagOptimized, unit: !2, retainedNodes: !293)
!293 = !{!294, !295, !296, !297, !298, !299, !300, !301, !302, !303, !304, !315, !322, !329, !336, !343, !346, !347, !348, !349, !350, !351, !352, !353, !354, !356, !359, !360, !361, !362, !363, !364, !365, !366, !367, !368, !369, !373, !374}
!294 = !DILocalVariable(name: "ih", scope: !292, file: !7, line: 81, type: !13)
!295 = !DILocalVariable(name: "iw", scope: !292, file: !7, line: 81, type: !13)
!296 = !DILocalVariable(name: "ic", scope: !292, file: !7, line: 81, type: !13)
!297 = !DILocalVariable(name: "kernel_h", scope: !292, file: !7, line: 82, type: !13)
!298 = !DILocalVariable(name: "kernel_w", scope: !292, file: !7, line: 82, type: !13)
!299 = !DILocalVariable(name: "stride_h", scope: !292, file: !7, line: 82, type: !13)
!300 = !DILocalVariable(name: "stride_w", scope: !292, file: !7, line: 82, type: !13)
!301 = !DILocalVariable(name: "oh", scope: !292, file: !7, line: 83, type: !13)
!302 = !DILocalVariable(name: "ow", scope: !292, file: !7, line: 83, type: !13)
!303 = !DILocalVariable(name: "oc", scope: !292, file: !7, line: 83, type: !13)
!304 = !DILocalVariable(name: "init_instruction", scope: !292, file: !7, line: 86, type: !305)
!305 = distinct !DICompositeType(tag: DW_TAG_class_type, name: "InitInstr", file: !7, line: 32, size: 8, flags: DIFlagTypePassByValue, elements: !306, identifier: "_ZTS9InitInstr")
!306 = !{!307, !311, !312, !313, !314}
!307 = !DISubprogram(name: "loadinit", linkageName: "_ZN9InitInstr8loadinitEiiii", scope: !305, file: !7, line: 35, type: !308, scopeLine: 35, flags: DIFlagPublic | DIFlagPrototyped, spFlags: DISPFlagOptimized)
!308 = !DISubroutineType(types: !309)
!309 = !{null, !310, !13, !13, !13, !13}
!310 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: !305, size: 64, flags: DIFlagArtificial | DIFlagObjectPointer)
!311 = !DISubprogram(name: "storeinit", linkageName: "_ZN9InitInstr9storeinitEiiii", scope: !305, file: !7, line: 36, type: !308, scopeLine: 36, flags: DIFlagPublic | DIFlagPrototyped, spFlags: DISPFlagOptimized)
!312 = !DISubprogram(name: "gemminit", linkageName: "_ZN9InitInstr8gemminitEiiii", scope: !305, file: !7, line: 37, type: !308, scopeLine: 37, flags: DIFlagPublic | DIFlagPrototyped, spFlags: DISPFlagOptimized)
!313 = !DISubprogram(name: "vectorinit", linkageName: "_ZN9InitInstr10vectorinitEiiii", scope: !305, file: !7, line: 38, type: !308, scopeLine: 38, flags: DIFlagPublic | DIFlagPrototyped, spFlags: DISPFlagOptimized)
!314 = !DISubprogram(name: "dreinit", linkageName: "_ZN9InitInstr7dreinitEiiii", scope: !305, file: !7, line: 39, type: !308, scopeLine: 39, flags: DIFlagPublic | DIFlagPrototyped, spFlags: DISPFlagOptimized)
!315 = !DILocalVariable(name: "load", scope: !292, file: !7, line: 87, type: !316)
!316 = distinct !DICompositeType(tag: DW_TAG_class_type, name: "LoadInstr", file: !7, line: 42, size: 8, flags: DIFlagTypePassByValue, elements: !317, identifier: "_ZTS9LoadInstr")
!317 = !{!318}
!318 = !DISubprogram(name: "settensor", linkageName: "_ZN9LoadInstr9settensorEiiiii", scope: !316, file: !7, line: 45, type: !319, scopeLine: 45, flags: DIFlagPublic | DIFlagPrototyped, spFlags: DISPFlagOptimized)
!319 = !DISubroutineType(types: !320)
!320 = !{null, !321, !13, !13, !13, !13, !13}
!321 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: !316, size: 64, flags: DIFlagArtificial | DIFlagObjectPointer)
!322 = !DILocalVariable(name: "store", scope: !292, file: !7, line: 88, type: !323)
!323 = distinct !DICompositeType(tag: DW_TAG_class_type, name: "StoreInstr", file: !7, line: 60, size: 8, flags: DIFlagTypePassByValue, elements: !324, identifier: "_ZTS10StoreInstr")
!324 = !{!325}
!325 = !DISubprogram(name: "finish", linkageName: "_ZN10StoreInstr6finishEi", scope: !323, file: !7, line: 63, type: !326, scopeLine: 63, flags: DIFlagPublic | DIFlagPrototyped, spFlags: DISPFlagOptimized)
!326 = !DISubroutineType(types: !327)
!327 = !{null, !328, !13}
!328 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: !323, size: 64, flags: DIFlagArtificial | DIFlagObjectPointer)
!329 = !DILocalVariable(name: "gemm", scope: !292, file: !7, line: 89, type: !330)
!330 = distinct !DICompositeType(tag: DW_TAG_class_type, name: "GemmInstr", file: !7, line: 48, size: 8, flags: DIFlagTypePassByValue, elements: !331, identifier: "_ZTS9GemmInstr")
!331 = !{!332}
!332 = !DISubprogram(name: "conv2d", linkageName: "_ZN9GemmInstr6conv2dEiiiiiiiiii", scope: !330, file: !7, line: 51, type: !333, scopeLine: 51, flags: DIFlagPublic | DIFlagPrototyped, spFlags: DISPFlagOptimized)
!333 = !DISubroutineType(types: !334)
!334 = !{null, !335, !13, !13, !13, !13, !13, !13, !13, !13, !13, !13}
!335 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: !330, size: 64, flags: DIFlagArtificial | DIFlagObjectPointer)
!336 = !DILocalVariable(name: "vector", scope: !292, file: !7, line: 90, type: !337)
!337 = distinct !DICompositeType(tag: DW_TAG_class_type, name: "VectorInstr", file: !7, line: 54, size: 8, flags: DIFlagTypePassByValue, elements: !338, identifier: "_ZTS11VectorInstr")
!338 = !{!339}
!339 = !DISubprogram(name: "log2x", linkageName: "_ZN11VectorInstr5log2xEiiiiii", scope: !337, file: !7, line: 57, type: !340, scopeLine: 57, flags: DIFlagPublic | DIFlagPrototyped, spFlags: DISPFlagOptimized)
!340 = !DISubroutineType(types: !341)
!341 = !{null, !342, !13, !13, !13, !13, !13, !13}
!342 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: !337, size: 64, flags: DIFlagArtificial | DIFlagObjectPointer)
!343 = !DILocalVariable(name: "dre", scope: !292, file: !7, line: 91, type: !344)
!344 = distinct !DICompositeType(tag: DW_TAG_class_type, name: "DreInstr", file: !7, line: 66, size: 8, flags: DIFlagTypePassByValue, elements: !345, identifier: "_ZTS8DreInstr")
!345 = !{}
!346 = !DILocalVariable(name: "acti_config", scope: !292, file: !7, line: 92, type: !13)
!347 = !DILocalVariable(name: "acti_bank_addr", scope: !292, file: !7, line: 93, type: !13)
!348 = !DILocalVariable(name: "wgt_config", scope: !292, file: !7, line: 94, type: !13)
!349 = !DILocalVariable(name: "wgt_bank_addr", scope: !292, file: !7, line: 95, type: !13)
!350 = !DILocalVariable(name: "bias_config", scope: !292, file: !7, line: 96, type: !13)
!351 = !DILocalVariable(name: "bias_bank_addr", scope: !292, file: !7, line: 97, type: !13)
!352 = !DILocalVariable(name: "acto_config", scope: !292, file: !7, line: 98, type: !13)
!353 = !DILocalVariable(name: "acto_bank_addr", scope: !292, file: !7, line: 99, type: !13)
!354 = !DILocalVariable(name: "wwfi", scope: !355, file: !7, line: 100, type: !13)
!355 = distinct !DILexicalBlock(scope: !292, file: !7, line: 100, column: 5)
!356 = !DILocalVariable(name: "settensor_func_description", scope: !357, file: !7, line: 102, type: !13)
!357 = distinct !DILexicalBlock(scope: !358, file: !7, line: 100, column: 41)
!358 = distinct !DILexicalBlock(scope: !355, file: !7, line: 100, column: 5)
!359 = !DILocalVariable(name: "settensor_func_config_sel", scope: !357, file: !7, line: 103, type: !13)
!360 = !DILocalVariable(name: "acti_load_config_sel", scope: !357, file: !7, line: 105, type: !13)
!361 = !DILocalVariable(name: "wgt_load_config_sel", scope: !357, file: !7, line: 109, type: !13)
!362 = !DILocalVariable(name: "bias_load_config_sel", scope: !357, file: !7, line: 113, type: !13)
!363 = !DILocalVariable(name: "conv_func_description", scope: !357, file: !7, line: 117, type: !13)
!364 = !DILocalVariable(name: "conv_func_config_sel", scope: !357, file: !7, line: 118, type: !13)
!365 = !DILocalVariable(name: "acti_gemm_config_sel", scope: !357, file: !7, line: 120, type: !13)
!366 = !DILocalVariable(name: "wgt_gemm_config_sel", scope: !357, file: !7, line: 122, type: !13)
!367 = !DILocalVariable(name: "bias_gemm_config_sel", scope: !357, file: !7, line: 124, type: !13)
!368 = !DILocalVariable(name: "acto_gemm_config_sel", scope: !357, file: !7, line: 126, type: !13)
!369 = !DILocalVariable(name: "log_param_vector", scope: !357, file: !7, line: 131, type: !370)
!370 = !DICompositeType(tag: DW_TAG_array_type, baseType: !26, size: 512, elements: !371)
!371 = !{!372}
!372 = !DISubrange(count: 8)
!373 = !DILocalVariable(name: "log2x_upd_param", scope: !357, file: !7, line: 132, type: !24)
!374 = !DILocalVariable(name: "acto_vector_config_sel", scope: !357, file: !7, line: 137, type: !13)
!375 = !DILocation(line: 91, column: 14, scope: !292)
!376 = !DILocation(line: 79, column: 5, scope: !292)
!377 = !DILocation(line: 0, scope: !292)
!378 = !DILocation(line: 85, column: 5, scope: !292)
!379 = !DILocation(line: 86, column: 5, scope: !292)
!380 = !DILocation(line: 86, column: 15, scope: !292)
!381 = !DILocation(line: 87, column: 5, scope: !292)
!382 = !DILocation(line: 87, column: 15, scope: !292)
!383 = !DILocation(line: 88, column: 5, scope: !292)
!384 = !DILocation(line: 88, column: 16, scope: !292)
!385 = !DILocation(line: 89, column: 5, scope: !292)
!386 = !DILocation(line: 89, column: 15, scope: !292)
!387 = !DILocation(line: 90, column: 5, scope: !292)
!388 = !DILocation(line: 90, column: 17, scope: !292)
!389 = !DILocation(line: 92, column: 42, scope: !292)
!390 = !DILocation(line: 93, column: 41, scope: !292)
!391 = !DILocation(line: 94, column: 41, scope: !292)
!392 = !DILocation(line: 95, column: 40, scope: !292)
!393 = !DILocation(line: 96, column: 42, scope: !292)
!394 = !DILocation(line: 97, column: 41, scope: !292)
!395 = !DILocation(line: 98, column: 42, scope: !292)
!396 = !DILocation(line: 99, column: 41, scope: !292)
!397 = !DILocation(line: 0, scope: !355)
!398 = !DILocation(line: 100, column: 5, scope: !355)
!399 = !DILocation(line: 101, column: 1, scope: !357)
!400 = !DILocation(line: 102, column: 47, scope: !357)
!401 = !DILocation(line: 0, scope: !357)
!402 = !DILocation(line: 103, column: 50, scope: !357)
!403 = !DILocation(line: 104, column: 22, scope: !357)
!404 = !DILocation(line: 105, column: 47, scope: !357)
!405 = !DILocation(line: 106, column: 22, scope: !357)
!406 = !DILocation(line: 107, column: 10, scope: !357)
!407 = !DILocation(line: 109, column: 46, scope: !357)
!408 = !DILocation(line: 110, column: 22, scope: !357)
!409 = !DILocation(line: 111, column: 10, scope: !357)
!410 = !DILocation(line: 113, column: 47, scope: !357)
!411 = !DILocation(line: 114, column: 22, scope: !357)
!412 = !DILocation(line: 115, column: 10, scope: !357)
!413 = !DILocation(line: 117, column: 42, scope: !357)
!414 = !DILocation(line: 118, column: 45, scope: !357)
!415 = !DILocation(line: 119, column: 22, scope: !357)
!416 = !DILocation(line: 120, column: 47, scope: !357)
!417 = !DILocation(line: 121, column: 22, scope: !357)
!418 = !DILocation(line: 122, column: 46, scope: !357)
!419 = !DILocation(line: 123, column: 22, scope: !357)
!420 = !DILocation(line: 124, column: 47, scope: !357)
!421 = !DILocation(line: 125, column: 22, scope: !357)
!422 = !DILocation(line: 126, column: 47, scope: !357)
!423 = !DILocation(line: 127, column: 22, scope: !357)
!424 = !DILocation(line: 128, column: 10, scope: !357)
!425 = !DILocation(line: 131, column: 5, scope: !357)
!426 = !DILocation(line: 131, column: 12, scope: !357)
!427 = !DILocation(line: 132, column: 43, scope: !357)
!428 = !DILocation(line: 133, column: 39, scope: !357)
!429 = !{!430, !430, i64 0}
!430 = !{!"int", !431, i64 0}
!431 = !{!"omnipotent char", !432, i64 0}
!432 = !{!"Simple C++ TBAA"}
!433 = !DILocation(line: 133, column: 22, scope: !357)
!434 = !DILocation(line: 134, column: 56, scope: !357)
!435 = !DILocation(line: 134, column: 39, scope: !357)
!436 = !DILocation(line: 134, column: 22, scope: !357)
!437 = !DILocation(line: 135, column: 56, scope: !357)
!438 = !DILocation(line: 135, column: 39, scope: !357)
!439 = !DILocation(line: 135, column: 22, scope: !357)
!440 = !DILocation(line: 136, column: 56, scope: !357)
!441 = !DILocation(line: 136, column: 39, scope: !357)
!442 = !DILocation(line: 136, column: 22, scope: !357)
!443 = !DILocation(line: 137, column: 49, scope: !357)
!444 = !DILocation(line: 138, column: 22, scope: !357)
!445 = !DILocation(line: 139, column: 12, scope: !357)
!446 = !DILocation(line: 141, column: 11, scope: !357)
!447 = !DILocation(line: 143, column: 5, scope: !358)
!448 = !DILocation(line: 100, column: 37, scope: !358)
!449 = !DILocation(line: 100, column: 28, scope: !358)
!450 = distinct !{!450, !398, !451, !452, !453}
!451 = !DILocation(line: 143, column: 5, scope: !355)
!452 = !{!"llvm.loop.mustprogress"}
!453 = !{!"llvm.loop.unroll.disable"}
!454 = !DILocation(line: 145, column: 11, scope: !292)
!455 = !DILocation(line: 145, column: 23, scope: !292)
!456 = !DILocation(line: 145, column: 5, scope: !292)
!457 = distinct !{!457, !456, !458, !452, !453}
!458 = !DILocation(line: 145, column: 27, scope: !292)
!459 = !DILocation(line: 146, column: 5, scope: !292)
!460 = !DILocation(line: 148, column: 5, scope: !292)
!461 = !DILocation(line: 151, column: 1, scope: !292)
!462 = !DILocation(line: 150, column: 5, scope: !292)
!463 = !DISubprogram(name: "reg2simd_start_set", linkageName: "_Z18reg2simd_start_seti", scope: !7, file: !7, line: 28, type: !464, flags: DIFlagPrototyped, spFlags: DISPFlagOptimized, retainedNodes: !345)
!464 = !DISubroutineType(types: !465)
!465 = !{null, !13}
!466 = !DISubprogram(name: "SIMDLOOP_TAG", linkageName: "_Z12SIMDLOOP_TAGi", scope: !7, file: !7, line: 71, type: !464, flags: DIFlagPrototyped, spFlags: DISPFlagOptimized, retainedNodes: !345)
!467 = !DISubprogram(name: "detect_irq", linkageName: "_Z10detect_irqv", scope: !7, file: !7, line: 29, type: !180, flags: DIFlagPrototyped, spFlags: DISPFlagOptimized, retainedNodes: !345)
!468 = !DISubprogram(name: "reg2simd_start_clr", linkageName: "_Z18reg2simd_start_clrv", scope: !7, file: !7, line: 26, type: !469, flags: DIFlagPrototyped, spFlags: DISPFlagOptimized, retainedNodes: !345)
!469 = !DISubroutineType(types: !470)
!470 = !{null}
