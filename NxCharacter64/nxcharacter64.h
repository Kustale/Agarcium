#pragma once
#define WIN32_LEAN_AND_MEAN

#include <Windows.h>

// Forward declarations for our proxy functions
extern "C" { // Use C linkage for the non-mangled functions
	void* __cdecl ProxyNxCreateControllerManager(void* param_1);
	void __cdecl ProxyNxReleaseControllerManager(void* param_1);
}

// Deduced signatures for the mangled member functions
// Note: __thiscall is often implicitly handled by the compiler for member functions
// but explicitly defining it can sometimes help with clarity or if using certain tools.
// The first parameter 'void* This' represents the 'this' pointer.

typedef void* (__thiscall* OriginalNxControllerManagerConstructor0_t)(void* This);
typedef void* (__thiscall* OriginalNxControllerManagerConstructor1_t)(void* This, const void* other);
typedef void(__thiscall* OriginalNxControllerManagerDestructor_t)(void* This);
typedef void* (__thiscall* OriginalNxControllerManagerAssignmentOperator_t)(void* This, const void* other);

// Define a type for the vftable (simply a pointer to an array of function pointers)
typedef void** OriginalNxControllerManagerVTable_t;

// Function pointers to the original functions
extern OriginalNxControllerManagerConstructor0_t OriginalNxControllerManagerConstructor0;
extern OriginalNxControllerManagerConstructor1_t OriginalNxControllerManagerConstructor1;
extern OriginalNxControllerManagerDestructor_t OriginalNxControllerManagerDestructor;
extern OriginalNxControllerManagerAssignmentOperator_t OriginalNxControllerManagerAssignmentOperator;
extern OriginalNxControllerManagerVTable_t OriginalNxControllerManagerVTable; // Pointer to the original vftable

// Function pointers to the original non-mangled functions
extern void* (__cdecl* OriginalNxCreateControllerManager)(void* param_1);
extern void(__cdecl* OriginalNxReleaseControllerManager)(void* param_1);

// Our proxy wrapper functions (matching the deduced signatures)
// The mangled names will be mapped to these in the .def file
void* ProxyNxControllerManagerConstructor0(void* This);
void* ProxyNxControllerManagerConstructor1(void* This, const void* other);
void ProxyNxControllerManagerDestructor(void* This);
void* ProxyNxControllerManagerAssignmentOperator(void* This, const void* other);
