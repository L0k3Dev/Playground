// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Plaground/PlagroundGameMode.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodePlagroundGameMode() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
PLAGROUND_API UClass* Z_Construct_UClass_APlagroundGameMode();
PLAGROUND_API UClass* Z_Construct_UClass_APlagroundGameMode_NoRegister();
UPackage* Z_Construct_UPackage__Script_Plaground();
// ********** End Cross Module References **********************************************************

// ********** Begin Class APlagroundGameMode *******************************************************
void APlagroundGameMode::StaticRegisterNativesAPlagroundGameMode()
{
}
FClassRegistrationInfo Z_Registration_Info_UClass_APlagroundGameMode;
UClass* APlagroundGameMode::GetPrivateStaticClass()
{
	using TClass = APlagroundGameMode;
	if (!Z_Registration_Info_UClass_APlagroundGameMode.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("PlagroundGameMode"),
			Z_Registration_Info_UClass_APlagroundGameMode.InnerSingleton,
			StaticRegisterNativesAPlagroundGameMode,
			sizeof(TClass),
			alignof(TClass),
			TClass::StaticClassFlags,
			TClass::StaticClassCastFlags(),
			TClass::StaticConfigName(),
			(UClass::ClassConstructorType)InternalConstructor<TClass>,
			(UClass::ClassVTableHelperCtorCallerType)InternalVTableHelperCtorCaller<TClass>,
			UOBJECT_CPPCLASS_STATICFUNCTIONS_FORCLASS(TClass),
			&TClass::Super::StaticClass,
			&TClass::WithinClass::StaticClass
		);
	}
	return Z_Registration_Info_UClass_APlagroundGameMode.InnerSingleton;
}
UClass* Z_Construct_UClass_APlagroundGameMode_NoRegister()
{
	return APlagroundGameMode::GetPrivateStaticClass();
}
struct Z_Construct_UClass_APlagroundGameMode_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "PlagroundGameMode.h" },
		{ "ModuleRelativePath", "PlagroundGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<APlagroundGameMode>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_APlagroundGameMode_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AGameModeBase,
	(UObject* (*)())Z_Construct_UPackage__Script_Plaground,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_APlagroundGameMode_Statics::DependentSingletons) < 16);
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
	0x008803ACu,
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
DEFINE_VTABLE_PTR_HELPER_CTOR(APlagroundGameMode);
APlagroundGameMode::~APlagroundGameMode() {}
// ********** End Class APlagroundGameMode *********************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Dev_Playground_Plaground_Source_Plaground_PlagroundGameMode_h__Script_Plaground_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_APlagroundGameMode, APlagroundGameMode::StaticClass, TEXT("APlagroundGameMode"), &Z_Registration_Info_UClass_APlagroundGameMode, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(APlagroundGameMode), 2138071016U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Dev_Playground_Plaground_Source_Plaground_PlagroundGameMode_h__Script_Plaground_1439828022(TEXT("/Script/Plaground"),
	Z_CompiledInDeferFile_FID_Dev_Playground_Plaground_Source_Plaground_PlagroundGameMode_h__Script_Plaground_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Dev_Playground_Plaground_Source_Plaground_PlagroundGameMode_h__Script_Plaground_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
