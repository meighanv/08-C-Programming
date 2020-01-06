#include <stdio.h>

/* 'void' declaration for the function is the reason why we do not
have to return at the end of our main function.

Return may not be necessary to compile, but it is totally necessary
to ensure the memory for your program is freed up.
*/
void main ()
{
    printf("hello\n");
}