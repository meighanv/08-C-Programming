#include <stdio.h>

void main()
{
    long double realPi = 3.1415926535897932;//3846;
    long double counter = 1;
    long double pi = 0;
    long double divisor = 1;
    long double cycles = 0;
    while(1==1)
    {
        if ((int)counter%2 == 1)
        {
            pi = pi + ((long double)4/divisor);
            //printf("%.16lf\n", pi);
        }
        else
        {
            pi = pi - ((long double)4/divisor);
            //printf("%.16lf\n", pi);
        }
        counter += 1;
        divisor += 2;
        cycles += 1;
        //printf("%.15lf\n", pi);
        if (pi == realPi)
        {
            break;
        }
        else if ((int)counter % 1000000000 == 0)
        {
            printf("%.16Lf\t%.2Lf\n", pi, cycles);
            counter = 1;
        }
    }
    printf("%.16Lf\n", pi);
    printf("It took %Lf cycles to reach 20 digits of fidelity with pi\n",cycles);
} // for 15 digits of fidelity it took 1.611+ billion cycles