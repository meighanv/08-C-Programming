#include<stdlib.h>
#include<stdio.h>
int main(int argc, char **argv){
	double a, b, c;
	a = atof(argv[1]);
	b = atof(argv[2]);
	c = atof(argv[3]);
	double average = (a + b + c) / 3.0;
	printf("The Average of %f, %f, and %f is %f\n", a, b, c, average);
	return 0;
}