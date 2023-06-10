/// @file   insane/__configuration/platform.hpp
/// @brief  Platform detection and conditional compilation macros
#ifndef INSANE_CONFIGURATION_PLATFORM_HPP_INCLUDED
#define INSANE_CONFIGURATION_PLATFORM_HPP_INCLUDED

/// @defgroup INSANE_CONFIGURATION_OS Insane.Configuration.Platform.OS
/// @brief    Platform OS enumeration
/// @{

#define INSANE_OS_UNKNOWN        0x00
#define INSANE_OS_WINDOWS_NATIVE 0x01
#define INSANE_OS_WINDOWS_CYGWIN 0x02
#define INSANE_OS_LINUX          0x04
#define INSANE_OS_MACOS          0x08
#define INSANE_OS_FREEBSD        0x10
#define INSANE_OS_OPENBSD        0x20
#define INSANE_OS_NETBSD         0x40
#define INSANE_OS_DRAGONFLYBSD   0x80

/// @}

/// @brief      Operating system detection.
/// @details    The operating system is automatically detected based on predefined macros.
///             If no matching macro is found, the operating system is set to INSANE_OS_UNKNOWN.
///
///             The detection priority is as follows:
///               - If INSANE_FORCE_UNKNOWN_PLATFORM is defined, set to INSANE_OS_UNKNOWN.
///               - If __CYGWIN__ or INSANE_FORCE_WINDOWS_CYGWIN is defined, set to INSANE_OS_WINDOWS_CYGWIN.
///               - If _WIN32, __WIN32, __WIN32__, or INSANE_FORCE_WINDOWS_NATIVE is defined, set to INSANE_OS_WINDOWS_NATIVE.
///               - If linux, __linux, __linux__, or INSANE_FORCE_LINUX is defined, set to INSANE_OS_LINUX.
///               - If __APPLE__, __MACH__, or INSANE_FORCE_MACOS is defined, set to INSANE_OS_MACOS.
///               - If __FreeBSD__ or INSANE_FORCE_FREEBSD is defined, set to INSANE_OS_FREEBSD.
///               - If __OpenBSD__ or INSANE_FORCE_OPENBSD is defined, set to INSANE_OS_OPENBSD.
///               - If __NetBSD__ or INSANE_FORCE_NETBSD is defined, set to INSANE_OS_NETBSD.
///               - If __DragonFlyBSD__ or INSANE_FORCE_DRAGONFLY is defined, set to INSANE_OS_DRAGONFLYBSD.
///               - If no matching macro is found, set to INSANE_OS_UNKNOWN.
#ifndef INSANE_OS
#	if defined(INSANE_FORCE_UNKNOWN_PLATFORM)
#		define INSANE_OS INSANE_OS_UNKNOWN
#	elif defined(__CYGWIN__) || defined(INSANE_FORCE_WINDOWS_CYGWIN)
#		define INSANE_OS INSANE_OS_WINDOWS_CYGWIN
#	elif defined(_WIN32) || defined(__WIN32) || defined(__WIN32__) || defined(INSANE_FORCE_WINDOWS_NATIVE)
#		define INSANE_OS INSANE_OS_WINDOWS_NATIVE
#	elif defined(linux) || defined(__linux) || defined(__linux__) || defined(INSANE_FORCE_LINUX)
#		define INSANE_OS INSANE_OS_LINUX
#	elif defined(__APPLE__) || defined(__MACH__) || defined(INSANE_FORCE_MACOS)
#		define INSANE_OS INSANE_OS_MACOS
#	elif defined(__FreeBSD__) || defined(INSANE_FORCE_FREEBSD)
#		define INSANE_OS INSANE_OS_FREEBSD
#	elif defined(__OpenBSD__) || defined(INSANE_FORCE_OPENBSD)
#		define INSANE_OS INSANE_OS_OPENBSD
#	elif defnied(__NetBSD__) || defined(INSANE_FORCE_NETBSD)
#		define INSANE_OS INSANE_OS_NETBSD
#	elif defined(__DragonFlyBSD__) || defined(INSANE_FORCE_DRAGONFLY)
#		define INSANE_OS INSANE_OS_DRAGONFLYBSD
#	else
#		define INSANE_OS INSANE_OS_UNKNOWN
#	endif
#endif

#endif