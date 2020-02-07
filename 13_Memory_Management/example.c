#include <stdio.h>

int global = 10; //stored in BSS
int main()
{
    static int i = 100; //stored in BSS
    static int y; // stored in data section
}