#include <stdio.h>

int main()

{
    int i, sum;
    sum = 0;
    for (i=0;i<10; i++)
        if (i<5)
            sum = sum+i;
        else
            sum=+((i-3)/2+(i/3));
    printf("sum=%d\n",sum);
            
}

// step or s ( moves to next line of code, but if it's a function it goes into the function)
// next or n ( moves to the next like of code; if it's a function it just executes the function)
// layout next ( displays the source code as you run in gdb )