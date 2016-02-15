#include <iostream>
#include <string>
#include <climits>
#include <cstdio>
using namespace std;
/*
Meta Templates
The problem: create a typedef for a signed integral type that is at least nbits
in size. 
The C++ Way
This example is simplified and adapted from one written by Dr. Carlo Pescio in
Template Metaprogramming: Make parameterized integers portable with this novel
technique.

There is no way in C++ to do conditional compilation based on the result of an
expression based on template parameters, so all control flow follows from
pattern matching of the template argument against various explicit template
specializations. Even worse, there is no way to do template specializations
based on relationships like "less than or equal to", so the example uses a
clever technique where the template is recursively expanded, incrementing the
template value argument by one each time, until a specialization matches. If
there is no match, the result is an unhelpful recursive compiler stack overflow
or internal error, or at best a strange syntax error.

A preprocessor macro is also needed to make up for the lack of template typedefs. 
#include <limits.h>

template< int nbits > struct Integer
{
    typedef Integer< nbits + 1 > :: int_type int_type ;
};

struct Integer< 8 >
{
    typedef signed char int_type ;
};

struct Integer< 16 >
{
    typedef short int_type ;
};

struct Integer< 32 >
{
    typedef int int_type ;
};

struct Integer< 64 >
{
    typedef long long int_type ;
};

// If the required size is not supported, the metaprogram
// will increase the counter until an internal error is
// signaled, or INT_MAX is reached. The INT_MAX
// specialization does not define a int_type, so a
// compiling error is always generated
struct Integer< INT_MAX >
{
};

// A bit of syntactic sugar
#define Integer( nbits ) Integer< nbits > :: int_type

#include <stdio.h>

int main()
{
    Integer( 8 ) i ;
    Integer( 16 ) j ;
    Integer( 29 ) k ;
    Integer( 64 ) l ;
    printf("%d %d %d %d\n",
	sizeof(i), sizeof(j), sizeof(k), sizeof(l));
    return 0 ;
}
 * 
 */

template< int  nbits > struct Integer
{
    typedef typename Integer< nbits + 1 >::int_type int_type;
};

template<>
struct Integer< 8 >
{
    typedef signed char int_type;
};

template<>
struct Integer< 16 >
{
    typedef short int_type;
};

template<>
struct Integer< 32 >
{
    typedef int int_type;
};

template<>
struct Integer< 64 >
{
    typedef long long int_type;
};

// If the required size is not supported, the metaprogram
// will increase the counter until an internal error is
// signaled, or INT_MAX is reached. The INT_MAX
// specialization does not define a int_type, so a
// compiling error is always generated
template<>
struct Integer< INT_MAX >
{
};

// A bit of syntactic sugar
#define Integer( nbits ) Integer< nbits > :: int_type


int main(int argc, char **argv){
    
        Integer( 8 ) i ;
        Integer( 16 ) j ;
        Integer( 29 ) k ;
        Integer( 64 ) l ;
        printf("%d %d %d %d\n",
                sizeof(i), sizeof(j), sizeof(k), sizeof(l));


        return 0;

}
