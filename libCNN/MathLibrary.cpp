// MathLibrary.cpp : Defines the exported functions for the DLL.
#include "pch.h" // use stdafx.h in Visual Studio 2017 and earlier
#include <utility>
#include <limits.h>
#include "MathLibrary.h"
#include <fftw3.h>

// DLL internal state variables:
static unsigned long long previous_;  // Previous value, if any
static unsigned long long current_;   // Current sequence value
static unsigned index_;               // Current seq. position

// Initialize a Fibonacci relation sequence
// such that F(0) = a, F(1) = b.
// This function must be called before any other function.
void fibonacci_init(
    const unsigned long long a,
    const unsigned long long b)
{
    index_ = 0;
    current_ = a;
    previous_ = b; // see special case when initialized
}

// Produce the next value in the sequence.
// Returns true on success, false on overflow.
bool fibonacci_next()
{
    // check to see if we'd overflow result or position
    if ((ULLONG_MAX - previous_ < current_) ||
        (UINT_MAX == index_))
    {
        return false;
    }

    // Special case when index == 0, just return b value
    if (index_ > 0)
    {
        // otherwise, calculate next sequence value
        previous_ += current_;
    }
    std::swap(current_, previous_);
    ++index_;
    return true;
}

// Get the current value in the sequence.
unsigned long long fibonacci_current()
{
    return current_;
}

// Get the current index position in the sequence.
unsigned fibonacci_index()
{
    return index_;
}

// Store Fibonacci Sequence in array sequence up to n
bool fibonacci_sequence(int n, unsigned long long target[])
{
    target[0] = 1;
    target[1] = 1;
    fibonacci_init(1, 1);
    while (fibonacci_index() < n && fibonacci_next())
    {
        target[fibonacci_index()] = fibonacci_current();
    }
    return fibonacci_index() == n;
}

MATHLIBRARY_API bool add_arrs(int n, double arrayA[], double arrayB[], double arrayC[])
{
    for (int i = 0; i < n; i++) {
        arrayC[i] = arrayA[i] + arrayB[i];
    }
    return true;
}

MATHLIBRARY_API bool fft(int n, std::complex<double> in[], std::complex<double> out[])
{
    fftw_plan p;

    auto in_space = new fftw_complex[n];
    p = fftw_plan_dft_1d(n, in_space, reinterpret_cast<fftw_complex*>(out), FFTW_FORWARD, FFTW_ESTIMATE);
    memcpy(in_space, in, n * sizeof(fftw_complex));
    fftw_execute(p);
    delete[] in_space;
    
    return true;
}

MATHLIBRARY_API bool convolve(double a[], double b[], double o[], size_t n)
{
    auto in_space = new double[n];

    delete[] in_space;
    return true;
}

MATHLIBRARY_API bool convolve(double a[], double b[], double o[], size_t n, fftw_plan plan)
{
    return true;
}
