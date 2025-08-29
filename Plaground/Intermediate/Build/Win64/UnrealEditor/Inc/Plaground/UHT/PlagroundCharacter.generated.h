// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "PlagroundCharacter.h"

#ifdef PLAGROUND_PlagroundCharacter_generated_h
#error "PlagroundCharacter.generated.h already included, missing '#pragma once' in PlagroundCharacter.h"
#endif
#define PLAGROUND_PlagroundCharacter_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class APlagroundCharacter ******************************************************
PLAGROUND_API UClass* Z_Construct_UClass_APlagroundCharacter_NoRegister();

#define FID_Dev_Playground_Plaground_Source_Plaground_PlagroundCharacter_h_21_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAPlagroundCharacter(); \
	friend struct Z_Construct_UClass_APlagroundCharacter_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend PLAGROUND_API UClass* Z_Construct_UClass_APlagroundCharacter_NoRegister(); \
public: \
	DECLARE_CLASS2(APlagroundCharacter, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Plaground"), Z_Construct_UClass_APlagroundCharacter_NoRegister) \
	DECLARE_SERIALIZER(APlagroundCharacter)


#define FID_Dev_Playground_Plaground_Source_Plaground_PlagroundCharacter_h_21_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	APlagroundCharacter(APlagroundCharacter&&) = delete; \
	APlagroundCharacter(const APlagroundCharacter&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, APlagroundCharacter); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(APlagroundCharacter); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(APlagroundCharacter) \
	NO_API virtual ~APlagroundCharacter();


#define FID_Dev_Playground_Plaground_Source_Plaground_PlagroundCharacter_h_18_PROLOG
#define FID_Dev_Playground_Plaground_Source_Plaground_PlagroundCharacter_h_21_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Dev_Playground_Plaground_Source_Plaground_PlagroundCharacter_h_21_INCLASS_NO_PURE_DECLS \
	FID_Dev_Playground_Plaground_Source_Plaground_PlagroundCharacter_h_21_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class APlagroundCharacter;

// ********** End Class APlagroundCharacter ********************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Dev_Playground_Plaground_Source_Plaground_PlagroundCharacter_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
