/// @file insane/__configuration/macros.hpp
/// @brief This file defines various utility macros that are (hopefully) used throughout the source code
#ifndef INSANE_CONFIGURATION_MACROS_HPP_INCLUDED
#define INSANE_CONFIGURATION_MACROS_HPP_INCLUDED

/// @brief      Converts the given argument into a string literal.
///
/// @param      ARG The argument to be converted into a string.
/// @return     The string literal representation of the argument.
#ifndef INSANE_MAKE_STRING
#	define INSANE_MAKE_STRING(ARG) #ARG
#endif

/// @brief      Converts the given argument into a string literal.
/// @details    This macro is a wrapper around INSANE_MAKE_STRING to provide consistency with other macros that have a similar
///             functionality.
///
/// @param      ARG The argument to be converted into a string.
/// @return     The string literal representation of the argument.
#ifndef INSANE_STRINGIFY
#	define INSANE_STRINGIFY(ARG) INSANE_MAKE_STRING(ARG)
#endif

/// @brief      Concatenates two preprocessor tokens.
/// @details    This macro concatenates the given preprocessor tokens together.
///
/// @param      ARG0 The first token.
/// @param      ARG1 The second token.
/// @return     The concatenated tokens.
#ifndef INSANE_CONCAT
#	define INSANE_CONCAT(ARG0, ARG1) ARG0##ARG1
#endif

/// @brief      Joins two preprocessor tokens into a single token.
/// @details    This macro joins the given preprocessor tokens together into a single token.
///
/// @param      ARG0 The first token.
/// @param      ARG1 The second token.
/// @return     The joined token.
#ifndef INSANE_JOIN
#	define INSANE_JOIN(ARG0, ARG1) INSANE_CONCAT(ARG0, ARG1)
#endif

/// @brief      Constructs a version number using the major, minor, and patchlevel components.
/// @details    This macro constructs a version number using the major, minor, and patchlevel components provided as
///             arguments. The resulting version number is represented as a 32-bit integer, with the major number in the most
///             significant 8 bits, the minor number in the next 8 bits, and the patchlevel in the least significant 16 bits.
///
/// @param      MAJOR The major version number.
/// @param      MINOR The minor version number.
/// @param      PATCHLEVEL The patchlevel version number.
/// @return     The version number as a 32-bit integer.
#ifndef INSANE_MAKE_VERSION
#	define INSANE_MAKE_VERSION(MAJOR, MINOR, PATCHLEVEL) (((MAJOR) << 24) | ((MINOR) << 16) | (PATCHLEVEL))
#endif

#define INSANE_ENABLE  1
#define INSANE_DISABLE 0

#endif