// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Plaground/PlagroundGameMode.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePlagroundGameMode() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	PLAGROUND_API UClass* Z_Construct_UClass_APlagroundGameMode();
	PLAGROUND_API UClass* Z_Construct_UClass_APlagroundGameMode_NoRegister();
	UPackage* Z_Construct_UPackage__Script_Plaground();
// End Cross Module References
	void APlagroundGameMode::StaticRegisterNativesAPlagroundGameMode()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(APlagroundGameMode);
	UClass* Z_Construct_UClass_APlagroundGameMode_NoRegister()
	{
		return APlagroundGameMode::StaticClass();
	}
	struct Z_Construct_UClass_APlagroundGameMode_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_APlagroundGameMode_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_Plaground,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_APlagroundGameMode_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APlagroundGameMode_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "PlagroundGameMode.h" },
		{ "ModuleRelativePath", "PlagroundGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_APlagroundGameMode_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<APlagroundGameMode>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_APlagroundGameMode_Statics::ClassParams = {
		&APlagroundGameMode::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x008802ACu,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_APlagroundGameMode_Statics::Class_MetaDataParams), Z_Construct_UClass_APlagroundGameMode_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_APlagroundGameMode()
	{
		if (!Z_Registration_Info_UClass_APlagroundGameMode.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_APlagroundGameMode.OuterSingleton, Z_Construct_UClass_APlagroundGameMode_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_APlagroundGameMode.OuterSingleton;
	}
	template<> PLAGROUND_API UClass* StaticClass<APlagroundGameMode>()
	{
		return APlagroundGameMode::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(APlagroundGameMode);
	APlagroundGameMode::~APlagroundGameMode() {}
	struct Z_CompiledInDeferFile_FID_Dev_Playground_Plaground_Source_Plaground_PlagroundGameMode_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Dev_Playground_Plaground_Source_Plaground_PlagroundGameMode_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_APlagroundGameMode, APlagroundGameMode::StaticClass, TEXT("APlagroundGameMode"), &Z_Registration_Info_UClass_APlagroundGameMode, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(APlagroundGameMode), 3608926147U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Dev_Playground_Plaground_Source_Plaground_PlagroundGameMode_h_784602824(TEXT("/Script/Plaground"),
		Z_CompiledInDeferFile_FID_Dev_Playground_Plaground_Source_Plaground_PlagroundGameMode_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Dev_Playground_Plaground_Source_Plaground_PlagroundGameMode_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
