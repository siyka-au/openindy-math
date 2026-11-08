#ifndef OI_MATH_GLOBAL_H_
#define OI_MATH_GLOBAL_H_

// Symbol visibility for the shared library, with no dependency on Qt.
#if defined(_WIN32) || defined(__CYGWIN__)
#define OI_MATH_DECL_EXPORT __declspec(dllexport)
#define OI_MATH_DECL_IMPORT __declspec(dllimport)
#else
#define OI_MATH_DECL_EXPORT __attribute__((visibility("default")))
#define OI_MATH_DECL_IMPORT __attribute__((visibility("default")))
#endif

#if defined(OI_MATH_LIB)
#define OI_MATH_EXPORT OI_MATH_DECL_EXPORT
#else
#define OI_MATH_EXPORT OI_MATH_DECL_IMPORT
#endif

#endif  // OI_MATH_GLOBAL_H_
