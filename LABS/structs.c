#include <stdio.h>

// Normal declaration of a structure (kind of like a class in python)
struct Student
{
    //Essentially creating attributes for the structure
    char student_name[256];
    int age;
};

// implementation of the structure called student
struct Student guy1 = { "Someone", 32 };
struct Student guy2 = { "Someone Else", 24 };


// With typedef, which alleviates the necessity to call "struct" when using the structure
typedef struct
{
    // Same deal setting up attributes for the structure
    char student_name[256];
    int age;
} Student;

// Then init using the type rather than the struct name
Student guy1 = { "Someone", 32 };
Student guy2 = { "Someone Else", 24 };

struct lotForSale
{
    int lot_number;
    float lot_cost;
    float square_footage;
};

int main()
{
    
    //Declare a struct variable
    struct lotForSale elmStreet;

    //Define the first member
    elmStreet.lot_number = 8755;
    
    //Define the second member
    elmStreet.lot_cost = 25000;
    
    //Define the third member
    elmStreet.square_footage = 6534;


    Student * guy1 = (Student*)malloc(sizeof(Student));

    strcpy(guy1->student_name, "Someone");
    guy1->age = 32;
}
