; ModuleID = '/mnt/c/data/work_thu/code_thu/hpcc/ss-cc/test_func/TC240112B/input.cpp.2.expand.mark_if.ll'
source_filename = "/mnt/c/data/work_thu/code_thu/hpcc/ss-cc/test_func/TC240112B/input.cpp.1.expand.mark_if.cpp"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

%struct.GemmExecutor_T = type { i32 }
%struct.DreExecutor_T = type { i32 }

@__const.simd_gemm_executor_AB.positions_src0 = private unnamed_addr constant [3 x i32] [i32 0, i32 2, i32 3], align 4
@__const.simd_gemm_executor_AB.positions_src1 = private unnamed_addr constant [2 x i32] [i32 0, i32 2], align 4
@__const.simd_gemm_executor_AB.positions_dst0 = private unnamed_addr constant [2 x i32] [i32 0, i32 2], align 4
@__const.simd_gemm_executor_AB.positions_func = private unnamed_addr constant [2 x i32] [i32 2, i32 3], align 4

; Function Attrs: alwaysinline mustprogress uwtable
define dso_local i32 @simd_gemm_executor_AB_wrap(%struct.GemmExecutor_T* noundef %0, double* noundef %1, double* noundef %2, double* noundef %3, i32 noundef %4, i32 noundef %5, i32 noundef %6, i32 noundef %7, i32 noundef %8, i32 noundef %9, double noundef %10, double noundef %11) #0 {
  %13 = alloca %struct.GemmExecutor_T*, align 8
  %14 = alloca double*, align 8
  %15 = alloca double*, align 8
  %16 = alloca double*, align 8
  %17 = alloca i32, align 4
  %18 = alloca i32, align 4
  %19 = alloca i32, align 4
  %20 = alloca i32, align 4
  %21 = alloca i32, align 4
  %22 = alloca i32, align 4
  %23 = alloca double, align 8
  %24 = alloca double, align 8
  %25 = alloca i32, align 4
  %26 = alloca i32, align 4
  %27 = alloca i32, align 4
  %28 = alloca i32, align 4
  %29 = alloca i32, align 4
  %30 = alloca i8, align 1
  %31 = alloca i8, align 1
  %32 = alloca i8, align 1
  %33 = alloca i16, align 2
  %34 = alloca i32, align 4
  %35 = alloca i8, align 1
  %36 = alloca i8, align 1
  %37 = alloca i8, align 1
  %38 = alloca i8, align 1
  %39 = alloca i8, align 1
  %40 = alloca i8, align 1
  %41 = alloca [3 x i32], align 4
  %42 = alloca [3 x i32], align 4
  %43 = alloca i128, align 16
  %44 = alloca i128, align 16
  %45 = alloca [2 x i32], align 4
  %46 = alloca [2 x i32], align 4
  %47 = alloca i128, align 16
  %48 = alloca i128, align 16
  %49 = alloca [2 x i32], align 4
  %50 = alloca [2 x i32], align 4
  %51 = alloca i128, align 16
  %52 = alloca i128, align 16
  %53 = alloca [2 x i32], align 4
  %54 = alloca [2 x i32], align 4
  %55 = alloca i128, align 16
  %56 = alloca i128, align 16
  %57 = alloca i128, align 16
  %58 = alloca i128, align 16
  %59 = alloca i128, align 16
  %60 = alloca i128, align 16
  store %struct.GemmExecutor_T* %0, %struct.GemmExecutor_T** %13, align 8
  store double* %1, double** %14, align 8
  store double* %2, double** %15, align 8
  store double* %3, double** %16, align 8
  store i32 %4, i32* %17, align 4
  store i32 %5, i32* %18, align 4
  store i32 %6, i32* %19, align 4
  store i32 %7, i32* %20, align 4
  store i32 %8, i32* %21, align 4
  store i32 %9, i32* %22, align 4
  store double %10, double* %23, align 8
  store double %11, double* %24, align 8
  %61 = load double*, double** %14, align 8
  %62 = bitcast double* %61 to i8*
  %63 = ptrtoint i8* %62 to i64
  %64 = call i32 @simd_convert_to_relative_addr(i64 noundef %63)
  store i32 %64, i32* %25, align 4
  %65 = load double*, double** %15, align 8
  %66 = bitcast double* %65 to i8*
  %67 = ptrtoint i8* %66 to i64
  %68 = call i32 @simd_convert_to_relative_addr(i64 noundef %67)
  store i32 %68, i32* %26, align 4
  store i32 0, i32* %27, align 4
  %69 = load double*, double** %16, align 8
  %70 = bitcast double* %69 to i8*
  %71 = ptrtoint i8* %70 to i64
  %72 = call i32 @simd_convert_to_relative_addr(i64 noundef %71)
  store i32 %72, i32* %28, align 4
  store i32 0, i32* %29, align 4
  store i8 0, i8* %30, align 1
  store i8 0, i8* %31, align 1
  store i8 0, i8* %32, align 1
  store i16 4369, i16* %33, align 2
  store i32 1, i32* %34, align 4
  store i8 1, i8* %35, align 1
  store i8 2, i8* %36, align 1
  store i8 0, i8* %37, align 1
  store i8 3, i8* %38, align 1
  store i8 4, i8* %39, align 1
  store i8 0, i8* %40, align 1
  %73 = bitcast [3 x i32]* %41 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 4 %73, i8* align 4 bitcast ([3 x i32]* @__const.simd_gemm_executor_AB.positions_src0 to i8*), i64 12, i1 false)
  %74 = getelementptr inbounds [3 x i32], [3 x i32]* %42, i64 0, i64 0
  %75 = load i32, i32* %18, align 4
  store i32 %75, i32* %74, align 4
  %76 = getelementptr inbounds i32, i32* %74, i64 1
  %77 = load i32, i32* %17, align 4
  store i32 %77, i32* %76, align 4
  %78 = getelementptr inbounds i32, i32* %76, i64 1
  %79 = load i32, i32* %18, align 4
  %80 = add nsw i32 %79, 16
  %81 = sdiv i32 %80, 16
  %82 = sub nsw i32 %81, 1
  store i32 %82, i32* %78, align 4
  %83 = getelementptr inbounds [3 x i32], [3 x i32]* %41, i64 0, i64 0
  %84 = getelementptr inbounds [3 x i32], [3 x i32]* %42, i64 0, i64 0
  %85 = call { i64, i64 } @simd_set_update_data(i32* noundef %83, i32* noundef %84)
  %86 = bitcast i128* %44 to { i64, i64 }*
  %87 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %86, i32 0, i32 0
  %88 = extractvalue { i64, i64 } %85, 0
  store i64 %88, i64* %87, align 16
  %89 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %86, i32 0, i32 1
  %90 = extractvalue { i64, i64 } %85, 1
  store i64 %90, i64* %89, align 8
  %91 = load i128, i128* %44, align 16
  store i128 %91, i128* %43, align 16
  %92 = bitcast [2 x i32]* %45 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 4 %92, i8* align 4 bitcast ([2 x i32]* @__const.simd_gemm_executor_AB.positions_src1 to i8*), i64 8, i1 false)
  %93 = getelementptr inbounds [2 x i32], [2 x i32]* %46, i64 0, i64 0
  %94 = load i32, i32* %18, align 4
  store i32 %94, i32* %93, align 4
  %95 = getelementptr inbounds i32, i32* %93, i64 1
  %96 = load i32, i32* %19, align 4
  store i32 %96, i32* %95, align 4
  %97 = getelementptr inbounds [2 x i32], [2 x i32]* %45, i64 0, i64 0
  %98 = getelementptr inbounds [2 x i32], [2 x i32]* %46, i64 0, i64 0
  %99 = call { i64, i64 } @simd_set_update_data(i32* noundef %97, i32* noundef %98)
  %100 = bitcast i128* %48 to { i64, i64 }*
  %101 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %100, i32 0, i32 0
  %102 = extractvalue { i64, i64 } %99, 0
  store i64 %102, i64* %101, align 16
  %103 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %100, i32 0, i32 1
  %104 = extractvalue { i64, i64 } %99, 1
  store i64 %104, i64* %103, align 8
  %105 = load i128, i128* %48, align 16
  store i128 %105, i128* %47, align 16
  %106 = bitcast [2 x i32]* %49 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 4 %106, i8* align 4 bitcast ([2 x i32]* @__const.simd_gemm_executor_AB.positions_dst0 to i8*), i64 8, i1 false)
  %107 = getelementptr inbounds [2 x i32], [2 x i32]* %50, i64 0, i64 0
  %108 = load i32, i32* %17, align 4
  store i32 %108, i32* %107, align 4
  %109 = getelementptr inbounds i32, i32* %107, i64 1
  %110 = load i32, i32* %19, align 4
  store i32 %110, i32* %109, align 4
  %111 = getelementptr inbounds [2 x i32], [2 x i32]* %49, i64 0, i64 0
  %112 = getelementptr inbounds [2 x i32], [2 x i32]* %50, i64 0, i64 0
  %113 = call { i64, i64 } @simd_set_update_data(i32* noundef %111, i32* noundef %112)
  %114 = bitcast i128* %52 to { i64, i64 }*
  %115 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %114, i32 0, i32 0
  %116 = extractvalue { i64, i64 } %113, 0
  store i64 %116, i64* %115, align 16
  %117 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %114, i32 0, i32 1
  %118 = extractvalue { i64, i64 } %113, 1
  store i64 %118, i64* %117, align 8
  %119 = load i128, i128* %52, align 16
  store i128 %119, i128* %51, align 16
  %120 = bitcast [2 x i32]* %53 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 4 %120, i8* align 4 bitcast ([2 x i32]* @__const.simd_gemm_executor_AB.positions_func to i8*), i64 8, i1 false)
  %121 = getelementptr inbounds [2 x i32], [2 x i32]* %54, i64 0, i64 0
  %122 = load i32, i32* %18, align 4
  %123 = load i32, i32* %17, align 4
  %124 = mul nsw i32 %122, %123
  %125 = sdiv i32 %124, 128
  store i32 %125, i32* %121, align 4
  %126 = getelementptr inbounds i32, i32* %121, i64 1
  %127 = load i32, i32* %18, align 4
  %128 = load i32, i32* %19, align 4
  %129 = mul nsw i32 %127, %128
  %130 = sdiv i32 %129, 128
  store i32 %130, i32* %126, align 4
  %131 = getelementptr inbounds [2 x i32], [2 x i32]* %53, i64 0, i64 0
  %132 = getelementptr inbounds [2 x i32], [2 x i32]* %54, i64 0, i64 0
  %133 = call { i64, i64 } @simd_set_update_data(i32* noundef %131, i32* noundef %132)
  %134 = bitcast i128* %56 to { i64, i64 }*
  %135 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %134, i32 0, i32 0
  %136 = extractvalue { i64, i64 } %133, 0
  store i64 %136, i64* %135, align 16
  %137 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %134, i32 0, i32 1
  %138 = extractvalue { i64, i64 } %133, 1
  store i64 %138, i64* %137, align 8
  %139 = load i128, i128* %56, align 16
  store i128 %139, i128* %55, align 16
  %140 = load %struct.GemmExecutor_T*, %struct.GemmExecutor_T** %13, align 8
  %141 = load i16, i16* %33, align 2
  %142 = load i32, i32* %34, align 4
  %143 = load i128, i128* %43, align 16
  %144 = load i8, i8* %30, align 1
  %145 = load i8, i8* %31, align 1
  %146 = load i8, i8* %32, align 1
  store i128 %143, i128* %57, align 16
  %147 = bitcast i128* %57 to { i64, i64 }*
  %148 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %147, i32 0, i32 0
  %149 = load i64, i64* %148, align 16
  %150 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %147, i32 0, i32 1
  %151 = load i64, i64* %150, align 8
  call void @simd_gemm_init(%struct.GemmExecutor_T* noundef %140, i16 noundef zeroext %141, i32 noundef %142, i64 noundef %149, i64 noundef %151, i8 noundef zeroext %144, i8 noundef zeroext %145, i8 noundef zeroext %146, i8 noundef zeroext 5)
  %152 = load %struct.GemmExecutor_T*, %struct.GemmExecutor_T** %13, align 8
  %153 = load i16, i16* %33, align 2
  %154 = load i32, i32* %34, align 4
  %155 = add i32 %154, 1
  %156 = load i128, i128* %47, align 16
  %157 = load i8, i8* %30, align 1
  %158 = load i8, i8* %31, align 1
  %159 = load i8, i8* %32, align 1
  store i128 %156, i128* %58, align 16
  %160 = bitcast i128* %58 to { i64, i64 }*
  %161 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %160, i32 0, i32 0
  %162 = load i64, i64* %161, align 16
  %163 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %160, i32 0, i32 1
  %164 = load i64, i64* %163, align 8
  call void @simd_gemm_init(%struct.GemmExecutor_T* noundef %152, i16 noundef zeroext %153, i32 noundef %155, i64 noundef %162, i64 noundef %164, i8 noundef zeroext %157, i8 noundef zeroext %158, i8 noundef zeroext %159, i8 noundef zeroext 5)
  %165 = load %struct.GemmExecutor_T*, %struct.GemmExecutor_T** %13, align 8
  %166 = load i16, i16* %33, align 2
  %167 = load i32, i32* %34, align 4
  %168 = add i32 %167, 2
  %169 = load i128, i128* %51, align 16
  %170 = load i8, i8* %30, align 1
  %171 = load i8, i8* %31, align 1
  %172 = load i8, i8* %32, align 1
  store i128 %169, i128* %59, align 16
  %173 = bitcast i128* %59 to { i64, i64 }*
  %174 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %173, i32 0, i32 0
  %175 = load i64, i64* %174, align 16
  %176 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %173, i32 0, i32 1
  %177 = load i64, i64* %176, align 8
  call void @simd_gemm_init(%struct.GemmExecutor_T* noundef %165, i16 noundef zeroext %166, i32 noundef %168, i64 noundef %175, i64 noundef %177, i8 noundef zeroext %170, i8 noundef zeroext %171, i8 noundef zeroext %172, i8 noundef zeroext 5)
  %178 = load %struct.GemmExecutor_T*, %struct.GemmExecutor_T** %13, align 8
  %179 = load i16, i16* %33, align 2
  %180 = load i32, i32* %34, align 4
  %181 = add i32 %180, 3
  %182 = load i128, i128* %55, align 16
  %183 = load i8, i8* %30, align 1
  %184 = load i8, i8* %31, align 1
  %185 = load i8, i8* %32, align 1
  store i128 %182, i128* %60, align 16
  %186 = bitcast i128* %60 to { i64, i64 }*
  %187 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %186, i32 0, i32 0
  %188 = load i64, i64* %187, align 16
  %189 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %186, i32 0, i32 1
  %190 = load i64, i64* %189, align 8
  call void @simd_gemm_init(%struct.GemmExecutor_T* noundef %178, i16 noundef zeroext %179, i32 noundef %181, i64 noundef %188, i64 noundef %190, i8 noundef zeroext %183, i8 noundef zeroext %184, i8 noundef zeroext %185, i8 noundef zeroext 5)
  %191 = load %struct.GemmExecutor_T*, %struct.GemmExecutor_T** %13, align 8
  %192 = load i32, i32* %25, align 4
  %193 = load i32, i32* %26, align 4
  %194 = load i32, i32* %27, align 4
  %195 = load i32, i32* %28, align 4
  %196 = load i32, i32* %29, align 4
  %197 = load i8, i8* %30, align 1
  %198 = load i8, i8* %31, align 1
  %199 = load i8, i8* %32, align 1
  %200 = load i8, i8* %35, align 1
  %201 = load i8, i8* %36, align 1
  %202 = load i8, i8* %37, align 1
  %203 = load i8, i8* %38, align 1
  %204 = load i8, i8* %39, align 1
  %205 = load i8, i8* %40, align 1
  %206 = call i32 @simd_gemm(%struct.GemmExecutor_T* noundef %191, i32 noundef %192, i32 noundef %193, i32 noundef %194, i32 noundef %195, i32 noundef %196, i8 noundef zeroext %197, i8 noundef zeroext %198, i8 noundef zeroext %199, i8 noundef zeroext %200, i8 noundef zeroext %201, i8 noundef zeroext %202, i8 noundef zeroext %203, i8 noundef zeroext %204, i8 noundef zeroext %205, i8 noundef zeroext 4)
  ret i32 %206
}

declare i32 @simd_convert_to_relative_addr(i64 noundef) #1

; Function Attrs: argmemonly nofree nounwind willreturn
declare void @llvm.memcpy.p0i8.p0i8.i64(i8* noalias nocapture writeonly, i8* noalias nocapture readonly, i64, i1 immarg) #2

declare { i64, i64 } @simd_set_update_data(i32* noundef, i32* noundef) #1

declare void @simd_gemm_init(%struct.GemmExecutor_T* noundef, i16 noundef zeroext, i32 noundef, i64 noundef, i64 noundef, i8 noundef zeroext, i8 noundef zeroext, i8 noundef zeroext, i8 noundef zeroext) #1

declare i32 @simd_gemm(%struct.GemmExecutor_T* noundef, i32 noundef, i32 noundef, i32 noundef, i32 noundef, i32 noundef, i8 noundef zeroext, i8 noundef zeroext, i8 noundef zeroext, i8 noundef zeroext, i8 noundef zeroext, i8 noundef zeroext, i8 noundef zeroext, i8 noundef zeroext, i8 noundef zeroext, i8 noundef zeroext) #1

; Function Attrs: mustprogress noinline optnone uwtable
define dso_local void @_Z3fooPdS_S_iii(double* noundef %0, double* noundef %1, double* noundef %2, i32 noundef %3, i32 noundef %4, i32 noundef %5) #3 {
  %7 = alloca %struct.GemmExecutor_T*, align 8
  %8 = alloca double*, align 8
  %9 = alloca double*, align 8
  %10 = alloca double*, align 8
  %11 = alloca i32, align 4
  %12 = alloca i32, align 4
  %13 = alloca i32, align 4
  %14 = alloca i32, align 4
  %15 = alloca i32, align 4
  %16 = alloca i32, align 4
  %17 = alloca double, align 8
  %18 = alloca double, align 8
  %19 = alloca i32, align 4
  %20 = alloca i32, align 4
  %21 = alloca i32, align 4
  %22 = alloca i32, align 4
  %23 = alloca i32, align 4
  %24 = alloca i8, align 1
  %25 = alloca i8, align 1
  %26 = alloca i8, align 1
  %27 = alloca i16, align 2
  %28 = alloca i32, align 4
  %29 = alloca i8, align 1
  %30 = alloca i8, align 1
  %31 = alloca i8, align 1
  %32 = alloca i8, align 1
  %33 = alloca i8, align 1
  %34 = alloca i8, align 1
  %35 = alloca [3 x i32], align 4
  %36 = alloca [3 x i32], align 4
  %37 = alloca i128, align 16
  %38 = alloca i128, align 16
  %39 = alloca [2 x i32], align 4
  %40 = alloca [2 x i32], align 4
  %41 = alloca i128, align 16
  %42 = alloca i128, align 16
  %43 = alloca [2 x i32], align 4
  %44 = alloca [2 x i32], align 4
  %45 = alloca i128, align 16
  %46 = alloca i128, align 16
  %47 = alloca [2 x i32], align 4
  %48 = alloca [2 x i32], align 4
  %49 = alloca i128, align 16
  %50 = alloca i128, align 16
  %51 = alloca i128, align 16
  %52 = alloca i128, align 16
  %53 = alloca i128, align 16
  %54 = alloca i128, align 16
  %55 = alloca %struct.GemmExecutor_T*, align 8
  %56 = alloca double*, align 8
  %57 = alloca double*, align 8
  %58 = alloca double*, align 8
  %59 = alloca i32, align 4
  %60 = alloca i32, align 4
  %61 = alloca i32, align 4
  %62 = alloca i32, align 4
  %63 = alloca i32, align 4
  %64 = alloca i32, align 4
  %65 = alloca double, align 8
  %66 = alloca double, align 8
  %67 = alloca i32, align 4
  %68 = alloca i32, align 4
  %69 = alloca i32, align 4
  %70 = alloca i32, align 4
  %71 = alloca i32, align 4
  %72 = alloca i8, align 1
  %73 = alloca i8, align 1
  %74 = alloca i8, align 1
  %75 = alloca i16, align 2
  %76 = alloca i32, align 4
  %77 = alloca i8, align 1
  %78 = alloca i8, align 1
  %79 = alloca i8, align 1
  %80 = alloca i8, align 1
  %81 = alloca i8, align 1
  %82 = alloca i8, align 1
  %83 = alloca [3 x i32], align 4
  %84 = alloca [3 x i32], align 4
  %85 = alloca i128, align 16
  %86 = alloca i128, align 16
  %87 = alloca [2 x i32], align 4
  %88 = alloca [2 x i32], align 4
  %89 = alloca i128, align 16
  %90 = alloca i128, align 16
  %91 = alloca [2 x i32], align 4
  %92 = alloca [2 x i32], align 4
  %93 = alloca i128, align 16
  %94 = alloca i128, align 16
  %95 = alloca [2 x i32], align 4
  %96 = alloca [2 x i32], align 4
  %97 = alloca i128, align 16
  %98 = alloca i128, align 16
  %99 = alloca i128, align 16
  %100 = alloca i128, align 16
  %101 = alloca i128, align 16
  %102 = alloca i128, align 16
  %103 = alloca double*, align 8
  %104 = alloca double*, align 8
  %105 = alloca double*, align 8
  %106 = alloca i32, align 4
  %107 = alloca i32, align 4
  %108 = alloca i32, align 4
  %109 = alloca %struct.GemmExecutor_T*, align 8
  %110 = alloca %struct.DreExecutor_T*, align 8
  store double* %0, double** %103, align 8
  store double* %1, double** %104, align 8
  store double* %2, double** %105, align 8
  store i32 %3, i32* %106, align 4
  store i32 %4, i32* %107, align 4
  store i32 %5, i32* %108, align 4
  %111 = call %struct.GemmExecutor_T* @simd_gemm_executor_create()
  store %struct.GemmExecutor_T* %111, %struct.GemmExecutor_T** %109, align 8
  %112 = call %struct.DreExecutor_T* @simd_dre_executor_create()
  store %struct.DreExecutor_T* %112, %struct.DreExecutor_T** %110, align 8
  br label %113

113:                                              ; preds = %6
  call void @reg2sch_start_set(i32 noundef 0)
  %114 = load %struct.GemmExecutor_T*, %struct.GemmExecutor_T** %109, align 8
  call void @simd_gemm_executor_initialize(%struct.GemmExecutor_T* noundef %114)
  %115 = load %struct.DreExecutor_T*, %struct.DreExecutor_T** %110, align 8
  call void @simd_dre_executor_initialize(%struct.DreExecutor_T* noundef %115)
  %116 = load %struct.GemmExecutor_T*, %struct.GemmExecutor_T** %109, align 8
  %117 = load double*, double** %103, align 8
  %118 = load double*, double** %104, align 8
  %119 = load double*, double** %105, align 8
  %120 = load i32, i32* %106, align 4
  %121 = load i32, i32* %107, align 4
  %122 = load i32, i32* %108, align 4
  store %struct.GemmExecutor_T* %116, %struct.GemmExecutor_T** %7, align 8
  store double* %117, double** %8, align 8
  store double* %118, double** %9, align 8
  store double* %119, double** %10, align 8
  store i32 %120, i32* %11, align 4
  store i32 %121, i32* %12, align 4
  store i32 %122, i32* %13, align 4
  store i32 0, i32* %14, align 4
  store i32 0, i32* %15, align 4
  store i32 0, i32* %16, align 4
  store double 1.000000e+00, double* %17, align 8
  store double 1.000000e+00, double* %18, align 8
  %123 = load double*, double** %8, align 8
  %124 = bitcast double* %123 to i8*
  %125 = ptrtoint i8* %124 to i64
  %126 = call i32 @simd_convert_to_relative_addr(i64 noundef %125)
  store i32 %126, i32* %19, align 4
  %127 = load double*, double** %9, align 8
  %128 = bitcast double* %127 to i8*
  %129 = ptrtoint i8* %128 to i64
  %130 = call i32 @simd_convert_to_relative_addr(i64 noundef %129)
  store i32 %130, i32* %20, align 4
  store i32 0, i32* %21, align 4
  %131 = load double*, double** %10, align 8
  %132 = bitcast double* %131 to i8*
  %133 = ptrtoint i8* %132 to i64
  %134 = call i32 @simd_convert_to_relative_addr(i64 noundef %133)
  store i32 %134, i32* %22, align 4
  store i32 0, i32* %23, align 4
  store i8 0, i8* %24, align 1
  store i8 0, i8* %25, align 1
  store i8 0, i8* %26, align 1
  store i16 4369, i16* %27, align 2
  store i32 1, i32* %28, align 4
  store i8 1, i8* %29, align 1
  store i8 2, i8* %30, align 1
  store i8 0, i8* %31, align 1
  store i8 3, i8* %32, align 1
  store i8 4, i8* %33, align 1
  store i8 0, i8* %34, align 1
  %135 = bitcast [3 x i32]* %35 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 4 %135, i8* align 4 bitcast ([3 x i32]* @__const.simd_gemm_executor_AB.positions_src0 to i8*), i64 12, i1 false)
  %136 = getelementptr inbounds [3 x i32], [3 x i32]* %36, i64 0, i64 0
  %137 = load i32, i32* %12, align 4
  store i32 %137, i32* %136, align 4
  %138 = getelementptr inbounds i32, i32* %136, i64 1
  %139 = load i32, i32* %11, align 4
  store i32 %139, i32* %138, align 4
  %140 = getelementptr inbounds i32, i32* %138, i64 1
  %141 = load i32, i32* %12, align 4
  %142 = add nsw i32 %141, 16
  %143 = sdiv i32 %142, 16
  %144 = sub nsw i32 %143, 1
  store i32 %144, i32* %140, align 4
  %145 = getelementptr inbounds [3 x i32], [3 x i32]* %35, i64 0, i64 0
  %146 = getelementptr inbounds [3 x i32], [3 x i32]* %36, i64 0, i64 0
  %147 = call { i64, i64 } @simd_set_update_data(i32* noundef %145, i32* noundef %146)
  %148 = bitcast i128* %38 to { i64, i64 }*
  %149 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %148, i32 0, i32 0
  %150 = extractvalue { i64, i64 } %147, 0
  store i64 %150, i64* %149, align 16
  %151 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %148, i32 0, i32 1
  %152 = extractvalue { i64, i64 } %147, 1
  store i64 %152, i64* %151, align 8
  %153 = load i128, i128* %38, align 16
  store i128 %153, i128* %37, align 16
  %154 = bitcast [2 x i32]* %39 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 4 %154, i8* align 4 bitcast ([2 x i32]* @__const.simd_gemm_executor_AB.positions_src1 to i8*), i64 8, i1 false)
  %155 = getelementptr inbounds [2 x i32], [2 x i32]* %40, i64 0, i64 0
  %156 = load i32, i32* %12, align 4
  store i32 %156, i32* %155, align 4
  %157 = getelementptr inbounds i32, i32* %155, i64 1
  %158 = load i32, i32* %13, align 4
  store i32 %158, i32* %157, align 4
  %159 = getelementptr inbounds [2 x i32], [2 x i32]* %39, i64 0, i64 0
  %160 = getelementptr inbounds [2 x i32], [2 x i32]* %40, i64 0, i64 0
  %161 = call { i64, i64 } @simd_set_update_data(i32* noundef %159, i32* noundef %160)
  %162 = bitcast i128* %42 to { i64, i64 }*
  %163 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %162, i32 0, i32 0
  %164 = extractvalue { i64, i64 } %161, 0
  store i64 %164, i64* %163, align 16
  %165 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %162, i32 0, i32 1
  %166 = extractvalue { i64, i64 } %161, 1
  store i64 %166, i64* %165, align 8
  %167 = load i128, i128* %42, align 16
  store i128 %167, i128* %41, align 16
  %168 = bitcast [2 x i32]* %43 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 4 %168, i8* align 4 bitcast ([2 x i32]* @__const.simd_gemm_executor_AB.positions_dst0 to i8*), i64 8, i1 false)
  %169 = getelementptr inbounds [2 x i32], [2 x i32]* %44, i64 0, i64 0
  %170 = load i32, i32* %11, align 4
  store i32 %170, i32* %169, align 4
  %171 = getelementptr inbounds i32, i32* %169, i64 1
  %172 = load i32, i32* %13, align 4
  store i32 %172, i32* %171, align 4
  %173 = getelementptr inbounds [2 x i32], [2 x i32]* %43, i64 0, i64 0
  %174 = getelementptr inbounds [2 x i32], [2 x i32]* %44, i64 0, i64 0
  %175 = call { i64, i64 } @simd_set_update_data(i32* noundef %173, i32* noundef %174)
  %176 = bitcast i128* %46 to { i64, i64 }*
  %177 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %176, i32 0, i32 0
  %178 = extractvalue { i64, i64 } %175, 0
  store i64 %178, i64* %177, align 16
  %179 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %176, i32 0, i32 1
  %180 = extractvalue { i64, i64 } %175, 1
  store i64 %180, i64* %179, align 8
  %181 = load i128, i128* %46, align 16
  store i128 %181, i128* %45, align 16
  %182 = bitcast [2 x i32]* %47 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 4 %182, i8* align 4 bitcast ([2 x i32]* @__const.simd_gemm_executor_AB.positions_func to i8*), i64 8, i1 false)
  %183 = getelementptr inbounds [2 x i32], [2 x i32]* %48, i64 0, i64 0
  %184 = load i32, i32* %12, align 4
  %185 = load i32, i32* %11, align 4
  %186 = mul nsw i32 %184, %185
  %187 = sdiv i32 %186, 128
  store i32 %187, i32* %183, align 4
  %188 = getelementptr inbounds i32, i32* %183, i64 1
  %189 = load i32, i32* %12, align 4
  %190 = load i32, i32* %13, align 4
  %191 = mul nsw i32 %189, %190
  %192 = sdiv i32 %191, 128
  store i32 %192, i32* %188, align 4
  %193 = getelementptr inbounds [2 x i32], [2 x i32]* %47, i64 0, i64 0
  %194 = getelementptr inbounds [2 x i32], [2 x i32]* %48, i64 0, i64 0
  %195 = call { i64, i64 } @simd_set_update_data(i32* noundef %193, i32* noundef %194)
  %196 = bitcast i128* %50 to { i64, i64 }*
  %197 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %196, i32 0, i32 0
  %198 = extractvalue { i64, i64 } %195, 0
  store i64 %198, i64* %197, align 16
  %199 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %196, i32 0, i32 1
  %200 = extractvalue { i64, i64 } %195, 1
  store i64 %200, i64* %199, align 8
  %201 = load i128, i128* %50, align 16
  store i128 %201, i128* %49, align 16
  %202 = load %struct.GemmExecutor_T*, %struct.GemmExecutor_T** %7, align 8
  %203 = load i16, i16* %27, align 2
  %204 = load i32, i32* %28, align 4
  %205 = load i128, i128* %37, align 16
  %206 = load i8, i8* %24, align 1
  %207 = load i8, i8* %25, align 1
  %208 = load i8, i8* %26, align 1
  store i128 %205, i128* %51, align 16
  %209 = bitcast i128* %51 to { i64, i64 }*
  %210 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %209, i32 0, i32 0
  %211 = load i64, i64* %210, align 16
  %212 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %209, i32 0, i32 1
  %213 = load i64, i64* %212, align 8
  call void @simd_gemm_init(%struct.GemmExecutor_T* noundef %202, i16 noundef zeroext %203, i32 noundef %204, i64 noundef %211, i64 noundef %213, i8 noundef zeroext %206, i8 noundef zeroext %207, i8 noundef zeroext %208, i8 noundef zeroext 5)
  %214 = load %struct.GemmExecutor_T*, %struct.GemmExecutor_T** %7, align 8
  %215 = load i16, i16* %27, align 2
  %216 = load i32, i32* %28, align 4
  %217 = add i32 %216, 1
  %218 = load i128, i128* %41, align 16
  %219 = load i8, i8* %24, align 1
  %220 = load i8, i8* %25, align 1
  %221 = load i8, i8* %26, align 1
  store i128 %218, i128* %52, align 16
  %222 = bitcast i128* %52 to { i64, i64 }*
  %223 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %222, i32 0, i32 0
  %224 = load i64, i64* %223, align 16
  %225 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %222, i32 0, i32 1
  %226 = load i64, i64* %225, align 8
  call void @simd_gemm_init(%struct.GemmExecutor_T* noundef %214, i16 noundef zeroext %215, i32 noundef %217, i64 noundef %224, i64 noundef %226, i8 noundef zeroext %219, i8 noundef zeroext %220, i8 noundef zeroext %221, i8 noundef zeroext 5)
  %227 = load %struct.GemmExecutor_T*, %struct.GemmExecutor_T** %7, align 8
  %228 = load i16, i16* %27, align 2
  %229 = load i32, i32* %28, align 4
  %230 = add i32 %229, 2
  %231 = load i128, i128* %45, align 16
  %232 = load i8, i8* %24, align 1
  %233 = load i8, i8* %25, align 1
  %234 = load i8, i8* %26, align 1
  store i128 %231, i128* %53, align 16
  %235 = bitcast i128* %53 to { i64, i64 }*
  %236 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %235, i32 0, i32 0
  %237 = load i64, i64* %236, align 16
  %238 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %235, i32 0, i32 1
  %239 = load i64, i64* %238, align 8
  call void @simd_gemm_init(%struct.GemmExecutor_T* noundef %227, i16 noundef zeroext %228, i32 noundef %230, i64 noundef %237, i64 noundef %239, i8 noundef zeroext %232, i8 noundef zeroext %233, i8 noundef zeroext %234, i8 noundef zeroext 5)
  %240 = load %struct.GemmExecutor_T*, %struct.GemmExecutor_T** %7, align 8
  %241 = load i16, i16* %27, align 2
  %242 = load i32, i32* %28, align 4
  %243 = add i32 %242, 3
  %244 = load i128, i128* %49, align 16
  %245 = load i8, i8* %24, align 1
  %246 = load i8, i8* %25, align 1
  %247 = load i8, i8* %26, align 1
  store i128 %244, i128* %54, align 16
  %248 = bitcast i128* %54 to { i64, i64 }*
  %249 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %248, i32 0, i32 0
  %250 = load i64, i64* %249, align 16
  %251 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %248, i32 0, i32 1
  %252 = load i64, i64* %251, align 8
  call void @simd_gemm_init(%struct.GemmExecutor_T* noundef %240, i16 noundef zeroext %241, i32 noundef %243, i64 noundef %250, i64 noundef %252, i8 noundef zeroext %245, i8 noundef zeroext %246, i8 noundef zeroext %247, i8 noundef zeroext 5)
  %253 = load %struct.GemmExecutor_T*, %struct.GemmExecutor_T** %7, align 8
  %254 = load i32, i32* %19, align 4
  %255 = load i32, i32* %20, align 4
  %256 = load i32, i32* %21, align 4
  %257 = load i32, i32* %22, align 4
  %258 = load i32, i32* %23, align 4
  %259 = load i8, i8* %24, align 1
  %260 = load i8, i8* %25, align 1
  %261 = load i8, i8* %26, align 1
  %262 = load i8, i8* %29, align 1
  %263 = load i8, i8* %30, align 1
  %264 = load i8, i8* %31, align 1
  %265 = load i8, i8* %32, align 1
  %266 = load i8, i8* %33, align 1
  %267 = load i8, i8* %34, align 1
  %268 = call i32 @simd_gemm(%struct.GemmExecutor_T* noundef %253, i32 noundef %254, i32 noundef %255, i32 noundef %256, i32 noundef %257, i32 noundef %258, i8 noundef zeroext %259, i8 noundef zeroext %260, i8 noundef zeroext %261, i8 noundef zeroext %262, i8 noundef zeroext %263, i8 noundef zeroext %264, i8 noundef zeroext %265, i8 noundef zeroext %266, i8 noundef zeroext %267, i8 noundef zeroext 4)
  %269 = load %struct.DreExecutor_T*, %struct.DreExecutor_T** %110, align 8
  %270 = load double*, double** %103, align 8
  %271 = load double*, double** %104, align 8
  %272 = call i32 @simd_dre_reshape(%struct.DreExecutor_T* noundef %269, double* noundef %270, double* noundef %271, i32 noundef 0, i32 noundef 0, i32 noundef 0, i32 noundef 0, i32 noundef 0, i32 noundef 0, i32 noundef 0, i32 noundef 0, i32 noundef 0, i32 noundef 0, i32 noundef 0, i32 noundef 0, i32 noundef 0, i32 noundef 0, i32 noundef 0, i32 noundef 0)
  call void @reg2sch_synchronize(i32 noundef 0)
  call void @reg2sch_start_set(i32 noundef 0)
  %273 = load %struct.GemmExecutor_T*, %struct.GemmExecutor_T** %109, align 8
  %274 = load double*, double** %105, align 8
  %275 = load double*, double** %105, align 8
  %276 = load double*, double** %105, align 8
  %277 = load i32, i32* %106, align 4
  %278 = load i32, i32* %107, align 4
  %279 = load i32, i32* %108, align 4
  store %struct.GemmExecutor_T* %273, %struct.GemmExecutor_T** %55, align 8
  store double* %274, double** %56, align 8
  store double* %275, double** %57, align 8
  store double* %276, double** %58, align 8
  store i32 %277, i32* %59, align 4
  store i32 %278, i32* %60, align 4
  store i32 %279, i32* %61, align 4
  store i32 0, i32* %62, align 4
  store i32 0, i32* %63, align 4
  store i32 0, i32* %64, align 4
  store double 1.000000e+00, double* %65, align 8
  store double 1.000000e+00, double* %66, align 8
  %280 = load double*, double** %56, align 8
  %281 = bitcast double* %280 to i8*
  %282 = ptrtoint i8* %281 to i64
  %283 = call i32 @simd_convert_to_relative_addr(i64 noundef %282)
  store i32 %283, i32* %67, align 4
  %284 = load double*, double** %57, align 8
  %285 = bitcast double* %284 to i8*
  %286 = ptrtoint i8* %285 to i64
  %287 = call i32 @simd_convert_to_relative_addr(i64 noundef %286)
  store i32 %287, i32* %68, align 4
  store i32 0, i32* %69, align 4
  %288 = load double*, double** %58, align 8
  %289 = bitcast double* %288 to i8*
  %290 = ptrtoint i8* %289 to i64
  %291 = call i32 @simd_convert_to_relative_addr(i64 noundef %290)
  store i32 %291, i32* %70, align 4
  store i32 0, i32* %71, align 4
  store i8 0, i8* %72, align 1
  store i8 0, i8* %73, align 1
  store i8 0, i8* %74, align 1
  store i16 4369, i16* %75, align 2
  store i32 1, i32* %76, align 4
  store i8 1, i8* %77, align 1
  store i8 2, i8* %78, align 1
  store i8 0, i8* %79, align 1
  store i8 3, i8* %80, align 1
  store i8 4, i8* %81, align 1
  store i8 0, i8* %82, align 1
  %292 = bitcast [3 x i32]* %83 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 4 %292, i8* align 4 bitcast ([3 x i32]* @__const.simd_gemm_executor_AB.positions_src0 to i8*), i64 12, i1 false)
  %293 = getelementptr inbounds [3 x i32], [3 x i32]* %84, i64 0, i64 0
  %294 = load i32, i32* %60, align 4
  store i32 %294, i32* %293, align 4
  %295 = getelementptr inbounds i32, i32* %293, i64 1
  %296 = load i32, i32* %59, align 4
  store i32 %296, i32* %295, align 4
  %297 = getelementptr inbounds i32, i32* %295, i64 1
  %298 = load i32, i32* %60, align 4
  %299 = add nsw i32 %298, 16
  %300 = sdiv i32 %299, 16
  %301 = sub nsw i32 %300, 1
  store i32 %301, i32* %297, align 4
  %302 = getelementptr inbounds [3 x i32], [3 x i32]* %83, i64 0, i64 0
  %303 = getelementptr inbounds [3 x i32], [3 x i32]* %84, i64 0, i64 0
  %304 = call { i64, i64 } @simd_set_update_data(i32* noundef %302, i32* noundef %303)
  %305 = bitcast i128* %86 to { i64, i64 }*
  %306 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %305, i32 0, i32 0
  %307 = extractvalue { i64, i64 } %304, 0
  store i64 %307, i64* %306, align 16
  %308 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %305, i32 0, i32 1
  %309 = extractvalue { i64, i64 } %304, 1
  store i64 %309, i64* %308, align 8
  %310 = load i128, i128* %86, align 16
  store i128 %310, i128* %85, align 16
  %311 = bitcast [2 x i32]* %87 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 4 %311, i8* align 4 bitcast ([2 x i32]* @__const.simd_gemm_executor_AB.positions_src1 to i8*), i64 8, i1 false)
  %312 = getelementptr inbounds [2 x i32], [2 x i32]* %88, i64 0, i64 0
  %313 = load i32, i32* %60, align 4
  store i32 %313, i32* %312, align 4
  %314 = getelementptr inbounds i32, i32* %312, i64 1
  %315 = load i32, i32* %61, align 4
  store i32 %315, i32* %314, align 4
  %316 = getelementptr inbounds [2 x i32], [2 x i32]* %87, i64 0, i64 0
  %317 = getelementptr inbounds [2 x i32], [2 x i32]* %88, i64 0, i64 0
  %318 = call { i64, i64 } @simd_set_update_data(i32* noundef %316, i32* noundef %317)
  %319 = bitcast i128* %90 to { i64, i64 }*
  %320 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %319, i32 0, i32 0
  %321 = extractvalue { i64, i64 } %318, 0
  store i64 %321, i64* %320, align 16
  %322 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %319, i32 0, i32 1
  %323 = extractvalue { i64, i64 } %318, 1
  store i64 %323, i64* %322, align 8
  %324 = load i128, i128* %90, align 16
  store i128 %324, i128* %89, align 16
  %325 = bitcast [2 x i32]* %91 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 4 %325, i8* align 4 bitcast ([2 x i32]* @__const.simd_gemm_executor_AB.positions_dst0 to i8*), i64 8, i1 false)
  %326 = getelementptr inbounds [2 x i32], [2 x i32]* %92, i64 0, i64 0
  %327 = load i32, i32* %59, align 4
  store i32 %327, i32* %326, align 4
  %328 = getelementptr inbounds i32, i32* %326, i64 1
  %329 = load i32, i32* %61, align 4
  store i32 %329, i32* %328, align 4
  %330 = getelementptr inbounds [2 x i32], [2 x i32]* %91, i64 0, i64 0
  %331 = getelementptr inbounds [2 x i32], [2 x i32]* %92, i64 0, i64 0
  %332 = call { i64, i64 } @simd_set_update_data(i32* noundef %330, i32* noundef %331)
  %333 = bitcast i128* %94 to { i64, i64 }*
  %334 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %333, i32 0, i32 0
  %335 = extractvalue { i64, i64 } %332, 0
  store i64 %335, i64* %334, align 16
  %336 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %333, i32 0, i32 1
  %337 = extractvalue { i64, i64 } %332, 1
  store i64 %337, i64* %336, align 8
  %338 = load i128, i128* %94, align 16
  store i128 %338, i128* %93, align 16
  %339 = bitcast [2 x i32]* %95 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 4 %339, i8* align 4 bitcast ([2 x i32]* @__const.simd_gemm_executor_AB.positions_func to i8*), i64 8, i1 false)
  %340 = getelementptr inbounds [2 x i32], [2 x i32]* %96, i64 0, i64 0
  %341 = load i32, i32* %60, align 4
  %342 = load i32, i32* %59, align 4
  %343 = mul nsw i32 %341, %342
  %344 = sdiv i32 %343, 128
  store i32 %344, i32* %340, align 4
  %345 = getelementptr inbounds i32, i32* %340, i64 1
  %346 = load i32, i32* %60, align 4
  %347 = load i32, i32* %61, align 4
  %348 = mul nsw i32 %346, %347
  %349 = sdiv i32 %348, 128
  store i32 %349, i32* %345, align 4
  %350 = getelementptr inbounds [2 x i32], [2 x i32]* %95, i64 0, i64 0
  %351 = getelementptr inbounds [2 x i32], [2 x i32]* %96, i64 0, i64 0
  %352 = call { i64, i64 } @simd_set_update_data(i32* noundef %350, i32* noundef %351)
  %353 = bitcast i128* %98 to { i64, i64 }*
  %354 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %353, i32 0, i32 0
  %355 = extractvalue { i64, i64 } %352, 0
  store i64 %355, i64* %354, align 16
  %356 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %353, i32 0, i32 1
  %357 = extractvalue { i64, i64 } %352, 1
  store i64 %357, i64* %356, align 8
  %358 = load i128, i128* %98, align 16
  store i128 %358, i128* %97, align 16
  %359 = load %struct.GemmExecutor_T*, %struct.GemmExecutor_T** %55, align 8
  %360 = load i16, i16* %75, align 2
  %361 = load i32, i32* %76, align 4
  %362 = load i128, i128* %85, align 16
  %363 = load i8, i8* %72, align 1
  %364 = load i8, i8* %73, align 1
  %365 = load i8, i8* %74, align 1
  store i128 %362, i128* %99, align 16
  %366 = bitcast i128* %99 to { i64, i64 }*
  %367 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %366, i32 0, i32 0
  %368 = load i64, i64* %367, align 16
  %369 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %366, i32 0, i32 1
  %370 = load i64, i64* %369, align 8
  call void @simd_gemm_init(%struct.GemmExecutor_T* noundef %359, i16 noundef zeroext %360, i32 noundef %361, i64 noundef %368, i64 noundef %370, i8 noundef zeroext %363, i8 noundef zeroext %364, i8 noundef zeroext %365, i8 noundef zeroext 5)
  %371 = load %struct.GemmExecutor_T*, %struct.GemmExecutor_T** %55, align 8
  %372 = load i16, i16* %75, align 2
  %373 = load i32, i32* %76, align 4
  %374 = add i32 %373, 1
  %375 = load i128, i128* %89, align 16
  %376 = load i8, i8* %72, align 1
  %377 = load i8, i8* %73, align 1
  %378 = load i8, i8* %74, align 1
  store i128 %375, i128* %100, align 16
  %379 = bitcast i128* %100 to { i64, i64 }*
  %380 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %379, i32 0, i32 0
  %381 = load i64, i64* %380, align 16
  %382 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %379, i32 0, i32 1
  %383 = load i64, i64* %382, align 8
  call void @simd_gemm_init(%struct.GemmExecutor_T* noundef %371, i16 noundef zeroext %372, i32 noundef %374, i64 noundef %381, i64 noundef %383, i8 noundef zeroext %376, i8 noundef zeroext %377, i8 noundef zeroext %378, i8 noundef zeroext 5)
  %384 = load %struct.GemmExecutor_T*, %struct.GemmExecutor_T** %55, align 8
  %385 = load i16, i16* %75, align 2
  %386 = load i32, i32* %76, align 4
  %387 = add i32 %386, 2
  %388 = load i128, i128* %93, align 16
  %389 = load i8, i8* %72, align 1
  %390 = load i8, i8* %73, align 1
  %391 = load i8, i8* %74, align 1
  store i128 %388, i128* %101, align 16
  %392 = bitcast i128* %101 to { i64, i64 }*
  %393 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %392, i32 0, i32 0
  %394 = load i64, i64* %393, align 16
  %395 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %392, i32 0, i32 1
  %396 = load i64, i64* %395, align 8
  call void @simd_gemm_init(%struct.GemmExecutor_T* noundef %384, i16 noundef zeroext %385, i32 noundef %387, i64 noundef %394, i64 noundef %396, i8 noundef zeroext %389, i8 noundef zeroext %390, i8 noundef zeroext %391, i8 noundef zeroext 5)
  %397 = load %struct.GemmExecutor_T*, %struct.GemmExecutor_T** %55, align 8
  %398 = load i16, i16* %75, align 2
  %399 = load i32, i32* %76, align 4
  %400 = add i32 %399, 3
  %401 = load i128, i128* %97, align 16
  %402 = load i8, i8* %72, align 1
  %403 = load i8, i8* %73, align 1
  %404 = load i8, i8* %74, align 1
  store i128 %401, i128* %102, align 16
  %405 = bitcast i128* %102 to { i64, i64 }*
  %406 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %405, i32 0, i32 0
  %407 = load i64, i64* %406, align 16
  %408 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %405, i32 0, i32 1
  %409 = load i64, i64* %408, align 8
  call void @simd_gemm_init(%struct.GemmExecutor_T* noundef %397, i16 noundef zeroext %398, i32 noundef %400, i64 noundef %407, i64 noundef %409, i8 noundef zeroext %402, i8 noundef zeroext %403, i8 noundef zeroext %404, i8 noundef zeroext 5)
  %410 = load %struct.GemmExecutor_T*, %struct.GemmExecutor_T** %55, align 8
  %411 = load i32, i32* %67, align 4
  %412 = load i32, i32* %68, align 4
  %413 = load i32, i32* %69, align 4
  %414 = load i32, i32* %70, align 4
  %415 = load i32, i32* %71, align 4
  %416 = load i8, i8* %72, align 1
  %417 = load i8, i8* %73, align 1
  %418 = load i8, i8* %74, align 1
  %419 = load i8, i8* %77, align 1
  %420 = load i8, i8* %78, align 1
  %421 = load i8, i8* %79, align 1
  %422 = load i8, i8* %80, align 1
  %423 = load i8, i8* %81, align 1
  %424 = load i8, i8* %82, align 1
  %425 = call i32 @simd_gemm(%struct.GemmExecutor_T* noundef %410, i32 noundef %411, i32 noundef %412, i32 noundef %413, i32 noundef %414, i32 noundef %415, i8 noundef zeroext %416, i8 noundef zeroext %417, i8 noundef zeroext %418, i8 noundef zeroext %419, i8 noundef zeroext %420, i8 noundef zeroext %421, i8 noundef zeroext %422, i8 noundef zeroext %423, i8 noundef zeroext %424, i8 noundef zeroext 4)
  %426 = load %struct.GemmExecutor_T*, %struct.GemmExecutor_T** %109, align 8
  call void @simd_gemm_executor_release(%struct.GemmExecutor_T* noundef %426)
  %427 = load %struct.DreExecutor_T*, %struct.DreExecutor_T** %110, align 8
  call void @simd_dre_executor_release(%struct.DreExecutor_T* noundef %427)
  call void @reg2sch_synchronize(i32 noundef 0)
  br label %428

428:                                              ; preds = %113
  %429 = load %struct.DreExecutor_T*, %struct.DreExecutor_T** %110, align 8
  %430 = bitcast %struct.DreExecutor_T* %429 to i8*
  call void @free(i8* noundef %430) #5
  %431 = load %struct.GemmExecutor_T*, %struct.GemmExecutor_T** %109, align 8
  %432 = bitcast %struct.GemmExecutor_T* %431 to i8*
  call void @free(i8* noundef %432) #5
  ret void
}

declare %struct.GemmExecutor_T* @simd_gemm_executor_create() #1

declare %struct.DreExecutor_T* @simd_dre_executor_create() #1

declare void @reg2sch_start_set(i32 noundef) #1

declare void @simd_gemm_executor_initialize(%struct.GemmExecutor_T* noundef) #1

declare void @simd_dre_executor_initialize(%struct.DreExecutor_T* noundef) #1

declare i32 @simd_dre_reshape(%struct.DreExecutor_T* noundef, double* noundef, double* noundef, i32 noundef, i32 noundef, i32 noundef, i32 noundef, i32 noundef, i32 noundef, i32 noundef, i32 noundef, i32 noundef, i32 noundef, i32 noundef, i32 noundef, i32 noundef, i32 noundef, i32 noundef, i32 noundef) #1

declare void @reg2sch_synchronize(i32 noundef) #1

declare void @simd_gemm_executor_release(%struct.GemmExecutor_T* noundef) #1

declare void @simd_dre_executor_release(%struct.DreExecutor_T* noundef) #1

; Function Attrs: nounwind
declare void @free(i8* noundef) #4

attributes #0 = { alwaysinline mustprogress uwtable "frame-pointer"="all" "min-legal-vector-width"="0" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #1 = { "frame-pointer"="all" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #2 = { argmemonly nofree nounwind willreturn }
attributes #3 = { mustprogress noinline optnone uwtable "frame-pointer"="all" "min-legal-vector-width"="0" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #4 = { nounwind "frame-pointer"="all" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #5 = { nounwind }

!llvm.module.flags = !{!0, !1, !2, !3, !4}
!llvm.ident = !{!5}

!0 = !{i32 1, !"wchar_size", i32 4}
!1 = !{i32 7, !"PIC Level", i32 2}
!2 = !{i32 7, !"PIE Level", i32 2}
!3 = !{i32 7, !"uwtable", i32 1}
!4 = !{i32 7, !"frame-pointer", i32 2}
!5 = !{!"Ubuntu clang version 14.0.6"}
