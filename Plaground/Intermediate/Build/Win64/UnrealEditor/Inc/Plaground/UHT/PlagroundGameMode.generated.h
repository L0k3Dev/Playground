// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "PlagroundGameMode.h"

#ifdef PLAGROUND_PlagroundGameMode_generated_h
#error "PlagroundGameMode.generated.h already included, missing '#pragma once' in PlagroundGameMode.h"
#endif
#define PLAGROUND_PlagroundGameMode_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class APlagroundGameMode *******************************************************
PLAGROUND_API UClass* Z_Construct_UClass_APlagroundGameMode_NoRegister();

#define FID_Dev_Playground_Plaground_Source_Plaground_PlagroundGameMode_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAPlagroundGameMode(); \
	friend struct Z_Construct_UClass_APlagroundGameMode_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend PLAGROUND_API UClass* Z_Construct_UClass_APlagroundGameMode_NoRegister(); \
public: \
	DECLARE_CLASS2(APlagroundGameMode, AGameModeBase, COMPILED_IN_FLAGS(0 | CLASS_Transient | CLASS_Config), CASTCLASS_None, TEXT("/Script/Plaground"), Z_Construct_UClass_APlagroundGameMode_NoRegister) \
	DECLARE_SERIALIZER(APlagroundGameMode)


#define FID_Dev_Playground_Plaground_Source_Plaground_PlagroundGameMode_h_12_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	APlagroundGameMode(APlagroundGameMode&&) = delete; \
	APlagroundGameMode(const APlagroundGameMode&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(PLAGROUND_API, APlagroundGameMode); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(APlagroundGameMode); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(APlagroundGameMode) \
	PLAGROUND_API virtual ~APlagroundGameMode();


#define FID_Dev_Playground_Plaground_Source_Plaground_PlagroundGameMode_h_9_PROLOG
#define FID_Dev_Playground_Plaground_Source_Plaground_PlagroundGameMode_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Dev_Playground_Plaground_Source_Plaground_PlagroundGameMode_h_12_INCLASS_NO_PURE_DECLS \
	FID_Dev_Playground_Plaground_Source_Plaground_PlagroundGameMode_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class APlagroundGameMode;

// ********** End Class APlagroundGameMode *********************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Dev_Playground_Plaground_Source_Plaground_PlagroundGameMode_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
