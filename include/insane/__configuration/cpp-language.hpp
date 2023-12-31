#ifndef INSANE_CONFIGURATION_CPP_LANGUAGE_HPP_INCLUDE
#define INSANE_CONFIGURATION_CPP_LANGUAGE_HPP_INCLUDE

#include "macros.hpp"

#define INSANE_CPP_COMPILER_UNKNOWN     0x00
#define INSANE_CPP_COMPILER_LLVM_CLANG  0x01
#define INSANE_CPP_COMPILER_APPLE_CLANG 0x02
#define INSANE_CPP_COMPILER_GNU         0x04
#define INSANE_CPP_COMPILER_MSVC        0x08

#ifndef INSANE_CPP_COMPILER
#	if defined(INSANE_FORCE_UNKNOWN_CPP_COMPILER)
#		define INSANE_CPP_COMPILER INSANE_CPP_COMPILER_UNKNOWN
#	elif defined(__clang__) && !defined(__apple_build_version__)
#		define INSANE_CPP_COMPILER INSANE_CPP_COMPILER_LLVM_CLANG
#	elif defined(__clang__) && defined(__apple_build_version__)
#		define INSANE_CPP_COMPILER INSANE_CPP_COMPILER_LLVM_CLANG
#	elif defined(__GNUC__)
#		define INSANE_CPP_COMPILER INSANE_CPP_COMPILER_GNU
#	elif defined(_MSC_VER)
#		define INSANE_CPP_COMPILER INSANE_CPP_COMPILER_MSVC
#	else
#		define INSANE_CPP_COMPILER INSANE_CPP_COMPILER_UNKNOWN
#	endif
#endif

#ifndef INSANE_CPP_COMPILER_VERSION
#	if(INSANE_CPP_COMPILER & (INSANE_CPP_COMPILER_LLVM_CLANG | INSANE_CPP_COMPILER_APPLE_CLANG))
#		define INSANE_CPP_COMPILER_VERSION INSANE_MAKE_VERSION(__clang_major__, __clang_minor__, __clang_patchlevel__)
#	elif(INSANE_CPP_COMPILER & INSANE_CPP_COMPILER_GNU)
#		if defined(__GNUC_PATCHLEVEL__)
#			define INSANE_CPP_COMPILER_VERSION INSANE_MAKE_VERSION(__GNUC__, __GNUC_MINOR__, 0)
#		else
#			define INSANE_CPP_COMPILER_VERSION INSANE_MAKE_VERSION(__GNUC__, __GNUC_MINOR__, __GNUC_PATCHLEVEL__)
#		endif
#	elif defined(_MSC_VER)
#		if defined(_MSC_FULL_VER)
#			define INSANE_CPP_COMPILER_VERSION                                                                               \
				INSANE_MAKE_VERSION(_MSC_FULL_VER / 1000000, (_MSC_FULL_VER % 1000000) / 10000, _MSC_FULL_VER % 10000)
#		else
#			define INSANE_CPP_COMPILER_VERSION INSANE_MAKE_VERSION(_MSC_VER / 10, (_MSC_VER % 10) * 10, 0)
#		endif
#	else
#		define INSANE_CPP_COMPILER_VERSION 0
#	endif
#endif

#define INSANE_CPP_NO_STANDARD_COMPLIANT 0x00
#define INSANE_CPP_11_STANDARD_COMPLIANT 0x01
#define INSANE_CPP_14_STANDARD_COMPLIANT 0x02
#define INSANE_CPP_17_STANDARD_COMPLIANT 0x04
#define INSANE_CPP_2X_STANDARD_COMPLIANT 0x08

#define INSANE_CPP_NO_STANDARD (INSANE_CPP_NO_STANDARD_COMPLIANT)
#define INSANE_CPP_11_STANDARD (INSANE_CPP_NO_STANDARD | INSANE_CPP_11_STANDARD_COMPLIANT)
#define INSANE_CPP_14_STANDARD (INSANE_CPP_11_STANDARD | INSANE_CPP_14_STANDARD_COMPLIANT)
#define INSANE_CPP_17_STANDARD (INSANE_CPP_14_STANDARD | INSANE_CPP_17_STANDARD_COMPLIANT)
#define INSANE_CPP_2X_STANDARD (INSANE_CPP_17_STANDARD | INSANE_CPP_2X_STANDARD_COMPLIANT)

#ifndef INSANE_CPP_STANDARD
#	if defined(INSANE_FORCE_UNKNOWN_CPP_STANDARD)
#		define INSANE_CPP_STANDARD INSANE_CPP_NO_STANDARD
#	elif !defined(__cplusplus)
#		define INSANE_CPP_STANDARD INSANE_CPP_NO_STANDARD
#	elif(__cplusplus > 201703L) || defined(INSANE_FORCE_CPP_2X_STANDARD)
#		define INSANE_CPP_STANDARD INSANE_CPP_2X_STANDARD
#	elif(__cplusplus >= 201703L) || defined(INSANE_FORCE_CPP_17_STANDARD)
#		define INSANE_CPP_STANDARD INSANE_CPP_17_STANDARD
#	elif(__cplusplus >= 201402L) || defined(INSANE_FORCE_CPP_14_STANDARD)
#		define INSANE_CPP_STANDARD INSANE_CPP_14_STANDARD
#	elif(__cplusplus >= 201103L) || defined(INSANE_FORCE_CPP_11_STANDARD)
#		define INSANE_CPP_STANDARD INSANE_CPP_11_STANDARD
#	else
#		define INSANE_CPP_STANDARD INSANE_CPP_NO_STANDARD
#	endif
#endif

#ifndef INSANE_CPP_HAS_FEATURE
#	if defined(__has_feature)
#		define INSANE_CPP_HAS_FEATURE(FEATURE) __has_feature(FEATURE)
#	else
#		define INSANE_CPP_HAS_FEATURE(FEATURE) 0
#	endif
#endif

#ifndef INSANE_HAS_CPP11_CONSTEXPR
#	if INSANE_CPP_HAS_FEATURE(cxx_constexpr)
#		define INSANE_HAS_CPP11_CONSTEXPR INSANE_ENABLE
#	elif(INSANE_CPP_STANDARD & INSANE_CPP_11_STANDARD_COMPLIANT)
#		define ISSANE_HAS_CPP11_CONSTEXPR INSANE_ENABLE
#	elif(INSANE_CPP_COMPILER & INSANE_CPP_COMPILER_GNU) && (INSANE_CPP_COMPILER_VERSION >= INSANE_MAKE_VERSION(4, 6, 0))
#		define INSANE_HAS_CPP11_CONSTEXPR INSANE_ENABLE
#	elif(INSANE_CPP_COMPILER & INSANE_CPP_COMPILER_MSVC) && (INSANE_CPP_COMPILER_VERSION >= INSANE_MAKE_VERSION(190, 0, 0))
#		define INSANE_HAS_CPP11_CONSTEXPR INSANE_ENABLE
#	else
#		define INSANE_HAS_CPP11_CONSTEXPR INSANE_DISABLE
#	endif
#endif

#ifndef INSANE_HAS_CPP11_TEMPLATE_ALIASES
#	if INSANE_CPP_HAS_FEATURE(cxx_alias_templates)
#		define INSANE_HAS_CPP11_TEMPLATE_ALIASES INSANE_ENABLE
#	elif(INSANE_CPP_STANDARD & INSANE_CPP_11_STANDARD_COMPLIANT)
#		define INSANE_HAS_CPP11_TEMPLATE_ALIASES INSANE_ENABLE
#	elif(INSANE_CPP_COMPILER & INSANE_CPP_COMPILER_LLVM_CLANG)                                                               \
	  && (INSANE_CPP_COMPILER_VERSION >= INSANE_MAKE_VERSION(3, 0, 0))
#		define INSANE_HAS_CPP11_TEMPLATE_ALIASES INSANE_ENABLE
#	elif(INSANE_CPP_COMPILER & INSANE_CPP_COMPILER_APPLE_CLANG)                                                              \
	  && (INSANE_CPP_COMPILER_VERSION >= INSANE_MAKE_VERSION(4, 0, 1))
#		define INSANE_HAS_CPP11_TEMPLATE_ALIASES INSANE_ENABLE
#	elif(INSANE_CPP_COMPILER & INSANE_CPP_COMPILER_GNU) && (INSANE_CPP_COMPILER_VERSION >= INSANE_MAKE_VERSION(4, 7, 0))
#		define INSANE_HAS_CPP11_TEMPLATE_ALIASES INSANE_ENABLE
#	elif(INSANE_CPP_COMPILER & INSANE_CPP_COMPILER_MSVC) && (INSANE_CPP_COMPILER_VERSION >= INSANE_MAKE_VERSION(180, 0, 0))
#		define INSANE_HAS_CPP11_TEMPLATE_ALIASES INSANE_ENABLE
#	else
#		define INSANE_HAS_CPP11_TEMPLATE_ALIASES INSANE_DISABLE
#	endif
#endif

#ifndef CPP11_CONSTEXPR
#	if INSANE_HAS_CPP11_CONSTEXPR
#		define CPP11_CONSTEXPR constexpr
#	else
#		define CPP11_CONSTEXPR
#	endif
#endif

#endif