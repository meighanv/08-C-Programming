#include <stdio.h>
unsigned int mystery(unsigned int a, unsigned int b); //prototype

int main(void)
{
    printf("%s", "Enter two positive integers: ");
    unsigned int x;
    unsigned int y;
    scanf("%u%u", &x,&y);
    printf("The result is %u\n", mystery(x,y));
    
}

// this is doing multiplcation by recursively adding a to itself b amount of times
unsigned int mystery(unsigned int a, unsigned int b) 
{
    //base case
    if (1 == b)
    {
        return a; //basically a*1
    }
    else if (b == 0)// added this to handle an input of 0
    {
        return 0;
    }
    
    else 
    {
        return a + mystery(a,b-1);
    }
} 