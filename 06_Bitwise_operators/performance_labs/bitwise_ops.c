/*

*/
#include <stdio.h>
#include <stdint.h>

void basicOps(void)
{
    int x, y;
    x = 20;
    y = 8;
    // Bitwise AND
    printf("%d\n", x & y);         // 1 if 1 in both x and y

    // Bitwise OR
    printf("%d\n",x | y);         // 1 if 1 in either x or y, or both

    // Bitwise XOR
    printf("%d\n",x ^ y);         // 1, if 1 in either x or y, but not both

    // Bitwise NOT
    printf("%d\n",~x);            // 1, if 0 in x

    // Shift Left
    printf("%d\n",x << y);        // Each bit in x is shifted y positions left

    // Shift Right
    printf("%d\n",x >> y);        // Each bit in x is shifted y positions right

}

void bwResults(void)
{
    //////// BITWISE OR USES ////////
    uint16_t bwResult = 0;                // 0000 0000 0000 0000
    uint16_t num1 = 12;                     // 0000 0000 0000 1100
    uint16_t num2 = 3;                      // 0000 0000 0000 0011
    bwResult = num1 | num2;                 // 0000 0000 0000 1111
    printf("%d\n", bwResult);

    uint16_t num3 = 240;                    // 0000 0000 1111 0000
    bwResult = bwResult | num3;             // 0000 0000 1111 1111
    printf("%d\n", bwResult);

    uint16_t num4 = 768;                    // 0000 0011 0000 0000
    bwResult = bwResult | num4;             // 0000 0011 1111 1111
    printf("%d\n", bwResult);

    uint16_t turnOn = 65280;                // 1111 1111 0000 0000
    bwResult = bwResult | turnOn;           // 1111 1111 1111 1111
    printf("%d\n", bwResult);
}

void xOrResults(void)
{

    /* SWAP TWO VARIABLES WITH XOR (^) WITHOUT USING A TEMP VARIABLE */
    //////// SAMPLE EXECUTION OF BITWISE XOR SWAP ////////
    uint8_t x = 1;                  // 0000 0001
    uint8_t y = 254;                // 1111 1110
    x = x ^ y;                      // x = 1111 1111 == (x)0000 0001 ^ (y)1111 1110
    printf("x is %d\n", x);
    y = x ^ y;                      // y = 0000 0001 == (x)1111 1111 ^ (y)1111 1110
    printf("y is %d\n", y);
    x = x ^ y;                      // x = 1111 1110 == 1111 1111 ^ 0000 0001
    printf("x is now %d\n", x);
    //////// SAMPLE EXECUTION OF BITWISE XOR SWAP ////////
    uint8_t p = 42;                 // 0010 1010
    uint8_t q = 11;                 // 0000 1011
    p = p ^ q;                      // p = 0010 0001 = (p)0010 1010 ^ (q)0000 1011
    printf("p is %d\n", p);
    q = p ^ q;                      // q = 0010 1010 = (p)0010 0001 ^ (q)0000 1011
    printf("q is %d\n", q);
    p = p ^ q;                      // p = 0000 1011 = (p)0010 0001 ^ (q)0010 1010
    printf("p is %d\n", p);

}

void printBin(uint32_t userInput)
{
    /*Lab 10: Bitwise Shift Right
    Input a uint32_t userInput from stdin utilizing fscanf()
    Initialize another uint32_t bitChecker to 0x01
    Use a Bitwise Shift Left on bitChecker to ensure only the left most bit is turned on
    Print the binary representation of userInput to stdout using only the following:
        fprintf()
        Bitwise Shift Right >>
        Bitwise AND &
        Relational Operator (e.g., >)
    */
    //uint32_t userInput = 0; // init user input var
    //printf("Please provide an integer:\n"); //
    //fscanf(stdin, "%d", &userInput); // read in user's number
    uint32_t bitChecker = 0x01; // init bitChecker to 1
    bitChecker = bitChecker << 31; //bit shift to the left-most point of the 32-bit integer
    for (int i = 31; i >= 0; i--) 
    {
        fprintf(stdout, "%d", (userInput & bitChecker) ? 1 : 0); //Prints 1 if the result of anding is not 0, otherwise it prints 0
        bitChecker >>= 1 ; //bit shift right
    }
    printf("\n"); // readability
    //return 0;
}

void threeLeft(void)
{
    /*
    take in number
    shift three bits left
    print result
    */
    uint32_t userInput = 0; // init user input var
    printf("Please provide an integer:\n"); //
    fscanf(stdin, "%d", &userInput); // read in user's number
    printf("Your input was %d:\n", userInput);
    printBin(userInput);
    printf("Your input bit shifted left 3 times is %d:\n", userInput << 3);
    printBin(userInput << 3);
}


void fiveRight(void)
{
    /*
    take in number
    shift three bits left
    print result
    */
    uint32_t userInput = 0; // init user input var
    printf("Please provide an integer:\n"); //
    fscanf(stdin, "%d", &userInput); // read in user's number
    printf("Your input was %d:\n", userInput);
    printBin(userInput);
    printf("Your input bit shifted right 5 times is %d:\n", userInput >> 5);
    printBin(userInput >> 5);
}



void main(void)
{
    //basicOps();
    //bwResults();
    //xOrResults();
    //lab10();
    threeLeft();
    fiveRight();
}


