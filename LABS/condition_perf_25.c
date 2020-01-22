/*
PERFORMANCE LAB 25
CONDITONAL COMPILATION
    Redefine EOF as 66 (without compiler warnings)
    Use preprocessor directive(s) to:
        Only compile in "release" and only compile if _INC_STDIO is defined
        Prints the name of a MACRO and also print the integer value of that MACRO
        Use a #else 'fall through' for ease of use and safety
    Use your preprocessor directives on FOPEN_MAX, FILENAME_MAX, and EOF
*/

#include <stdio.h>

#ifdef EOF
#undef EOF
#define EOF 66
#endif

#define PRINTM(x) printf(#x " is %d\n", x)
#define PRINTMAC(x) PRINTM(x)

#ifndef FOPEN_MAX
#define FOPEN_MAX 20
#endif
#ifndef FILENAME_MAX
#define FILENAME_MAX 30
#endif

#define release 1.0
#define _INC_STDIO

#if defined(release) && defined(_INC_STDIO)
int main()
{
    PRINTMAC(FOPEN_MAX);
    PRINTMAC(FILENAME_MAX);
    PRINTMAC(release);
}
#endif

#if !defined(_INC_STDIO)
int main()
{
    printf("This is not ready yet.\n");
}
#endif
