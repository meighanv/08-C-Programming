
/*
Name: Vernon Meighan
Date: 20200108
Project: This program experiments with string formatting using printf()
*/

#include <stdio.h>

void main(void)
{
    float someNum = 12.3456;                    // Var used as comparison

    printf("%f\n", someNum);                     // 12.345600
    printf("%f\n", someNum * -1.0);              // -12.345600
    printf("%+f\n", someNum);                    // +12.345600
    printf("%+f\n", someNum * -1.0);             // -12.346000
    printf("% f\n", someNum);                    //  12.345600
    printf("% f\n", someNum * -1.0);             // -12.345600    
    printf("%-f\n", someNum);                    // 12.345600  
    printf("%-f\n", someNum * -1.0);             // -12.345600  
    printf("%0f\n", someNum);                    // 12.345600  
    printf("%016f\n", someNum);                  // 000000012.345600
    
    char myStr[] = {"Hello world!"};            // Nul terminated string

    printf("%s\n", myStr);                        // Hello world!
    printf("%0s\n", myStr);                       // Hello world! (This generates a warning at compile time.)
    printf("%2s\n", myStr);                       // Hello world!
    printf("%4s\n", myStr);                       // Hello world!
    printf("%8s\n", myStr);                       // Hello world!
    printf("%16s\n", myStr);                      //      Hello World!            (5 positions)
    printf("%26s\n", myStr);                      //                Hello world!  (15 positions)
}