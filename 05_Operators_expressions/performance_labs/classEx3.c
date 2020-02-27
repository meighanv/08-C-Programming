// Calculate mileage reimbursment

#include <stdio.h>
#include <stdlib.h>
#include <math.h> // must be compiled with the '-lm- switch for gcc

int main(int argc, char **argv)
{
    double startMi, endMi, ratePerMi, reimbursement;

    printf("Enter the starting milage:\n");
    scanf("%lf", &startMi);

    printf("Enter the ending milage:\n");
    scanf("%lf", &endMi);

    printf("Enter the rate per mile:\n");
    scanf("%lf", &ratePerMi);

    reimbursement = (endMi - startMi)*ratePerMi;
    reimbursement = round(reimbursement); //compiles fine with '-lm'

    printf("Your reimburstment for %.2f miles is $%.2f.\n", (endMi - startMi),reimbursement);

    return 0;

}