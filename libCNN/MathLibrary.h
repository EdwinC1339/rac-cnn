// MathLibrary.h - Contains declarations of math functions
#pragma once
#include <complex>

#ifdef MATHLIBRARY_EXPORTS
#define MATHLIBRARY_API __declspec(dllimport)
#else
#define MATHLIBRARY_API __declspec(dllexport)
#endif

// The Fibonacci recurrence relation describes a sequence F
// where F(n) is { n = 0, a
//               { n = 1, b
//               { n > 1, F(n-2) + F(n-1)
// for some initial integral values a and b.
// If the sequence is initialized F(0) = 1, F(1) = 1,
// then this relation produces the well-known Fibonacci
// sequence: 1, 1, 2, 3, 5, 8, 13, 21, 34, ...

// Initialize a Fibonacci relation sequence
// such that F(0) = a, F(1) = b.
// This function must be called before any other function.
extern "C" MATHLIBRARY_API void fibonacci_init(
    const unsigned long long a, const unsigned long long b);

// Produce the next value in the sequence.
// Returns true on success and updates current value and index;
// false on overflow, leaves current value and index unchanged.
extern "C" MATHLIBRARY_API bool fibonacci_next();

// Get the current value in the sequence.
extern "C" MATHLIBRARY_API unsigned long long fibonacci_current();

// Get the position of the current value in the sequence.
extern "C" MATHLIBRARY_API unsigned fibonacci_index();

// Return Fibonacci Sequence in array up to n
extern "C" MATHLIBRARY_API bool fibonacci_sequence(int n, unsigned long long target[]);

// Return elementwise sum of arrayA and arrayB in arrayC, all being arrays of equal sizes.
extern "C" MATHLIBRARY_API bool add_arrs(int n, double arrayA[], double arrayB[], double arrayC[]);

extern "C" MATHLIBRARY_API bool fft(int n, std::complex<double> in[], std::complex<double> out[]);

// Convolve a * b in o
extern "C" MATHLIBRARY_API bool convolve(double a[], double b[], double o[], size_t n);
// Convolve a * b in o using plan
extern "C" MATHLIBRARY_API bool convolve(double a[], double b[], double o[], size_t n, fftw_plan plan);