|[Table of Contents](/00-Table-of-Contents.md)|
|---|

---

## C Programming Specifics

### Pointers

Pointer variables often called pointers, are variables which contain the address of another variable in memory. Pointers can point to any variable type.

### Dereferencing Pointer

The data contained at the address in which a pointer is pointing to. Simply put, when you dereference a pointer, you are using the pointer to get to the other variable.

### Dynamic Storage

C gives you the power to use a variety of memory allocation types:

**Static Memory Allocation:** Memory for variables is allocated on program started. This applies to global variables, static and file scope variables. 

**Automatic Memory Allocation:** Variables defined within functions and generally stored on the stack. 

```c
void someFunc() 
{
    int x; // created via auto memory allocation
}
```

**Dynamic Memory Allocation:** Programmer controls the exact size and lifetime of these memory locations. Therefore, you must free it in order to prevent memory leaks which can cause the program to crash. 

```c
int* func()
{
    int* x = malloc(1024);
    return x;
}

int* x = func(); // still allocated and useable even after function end

free(x); // free to prevent crash
```

### Blocks/Functions Book -- ended with {}

someFunc and func\(\) above both utilize {}. This is useful because it prevents type errors and looks clean. Say for instance alignment or whitespace is incorrect... contents within function will still run correctly. 

### Filenames

* **Header Files -** .h - not exactly libraries
  * Used to define C functions to be shared between several source files. These can include system headers \(interfaces to the operating system\) and personal headers. 
* **Object Files -** .o
  * The result of a compilation of source file\(s\). 
* **Source Code -** .c
  * The file containing the source code from the programmer. This is the bulk of what we will be using. 

### Comments

Comments are ignored by the compiler. This enables the programmer to leave documentation, mental notes, how-tos, etc. within their code without effecting the code. It's an insanely good practice to use comments in your code. 

```c
#include <stdio.h>

/***********************
*** Written for P-IQT***
***********************/

int main()
{
    printf("Hello World"); // Prints Hello World to screen
    return 0; //ends main()
}
```

---

|[Next Topic](/01_Introduction/04_gcc.md)|
|---|
