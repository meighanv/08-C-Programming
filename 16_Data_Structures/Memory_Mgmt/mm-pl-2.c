#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    //TODO: Create a string containing your first name
    char name [] = {"Vernon\0"};

    //TODO: Get the size of this string
    int length = strlen(name);
    //TODO: Declare a char pointer *str
    char * out_ptr;


    //TODO: Allocate a section of memory of type char
    //TODO: Set the size of this allocated space to 40 bytes
    //TODO: Asign the address of this allocated space to the pointer value
    out_ptr = (char *)malloc(40);

    //TODO: Copy your name into the allocated space using strcpy()
    strcpy(out_ptr,name);
    //TODO: Print out your name that is stored in the allocated memory space
    fputs(out_ptr, stdout);
    //TODO: Reallocate the memory space using the size of the string rather than 40 bytes
    //TODO: Print out the string again
    out_ptr = realloc(out_ptr,length);
    fputs(out_ptr, stdout);
    free(out_ptr);
}