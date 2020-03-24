#include <string.h>
#include <stdio.h>
#include <stdlib.h>
//#include "bubble.c"
#define handsize 5


/*
Write the function checkHand that receives a 5-element integer array that represents a
fictitious poker hand. The valid values for this array are the numbers 1 through 13. 
For this game of poker there are only three types of hands worth noting:  
three of a kind, four of a kind, or a straight.  A straight involves all 5 cards being 
in a sequence such as 3, 4, 5, 6, 7 etc.

The function will evaluate the array to determine the best hand.  The precedence of 
hands is:

1. straight (best)
2. four of a kind
3. three of a kind
4  nothing (worst)

The function will return one of the following strings based on analysis: 
    "straight", "four", "three", "nothing", or "invalid"

The function will return "invalid" if any of the values are < 1 or > 13.


*/

// Defining swap function used for bubbleSort()
void swap (int * a, int * b)
{
    // performs xor swap on the dereferenced pointers passed into swap()
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
}

// defining bubbleSort function; 'last' arg is array size
void bubbleSort(int * list, int last)
{
    //while True 
    while (1==1)
    {
        // set swapped tracker to 0; if any element is swapped this flag is turned on
        int swapped = 0;
        // Loop through each element in the array
        for (int i = 0;i < last -1; i++)
        {
            // if current element is greater than next element
            if (list[i] > list[i+1])
            {
                // Call swap() to exchange the elements at those locations
                swap(&list[i],&list[i+1]); // since pointers are expected, addresses (&) must be passed as args
                // turn swapped flag on 
                swapped = 1;
            }
        }
        // inside of the while loop sort is complete if no items were swapped (i.e. swapped == 0)
        if (swapped == 0)
        {
            break;
        }
    }
}


char* checkHand(int hand[])
{    
    bubbleSort(hand, handsize ); // sort hand in ascending order
        
    // build example of straight hand based on first card 
    int straightEx [handsize] = {hand[0], hand[0]+1, hand[0]+2, hand[0]+3, hand[0]+4 };
    int straight = 1; //assuming straight hand exists until proven otherwise below
    for(int i = 0; i < handsize; i++) // iterating through each card in hand and example
    {
        if (hand[i] != straightEx[i]) // comparing the card values
        {
            straight = 0;//set straigh to 0 if the cards mismatch
            break;
        }
    }
    if (straight == 1) //check if straight condition is still true after loop
    {
        return "straight"; // if true return straight
    }
    
    int ofKind = 0; // this is the integer counter of successive cards with same value
    for (int i = 0; i < handsize-1; i++) //iterating hand
    {
        int card = hand[i]; //setting current card in hand to card 
        int j = 0; //loop counter for while loop
        while (j < handsize) //looping through the indicies a second time with j
        {
            if (hand[j]>13) // condition to check for invalid card value
            {
                return "invalid";
            }
            
            if (card == hand[j]) //checking if card matches the current position
            {
                ofKind++; // if it does then increment the ofKind counter
            }
            else // if next card doesn't match then ...
            {
                if (ofKind == 3) //check for 3 of a kind 
                {
                    return "three";
                }
                else if (ofKind == 4) // check for four of a kind
                {
                    return "four";
                }
                else
                {
                    ofKind = 0; //otherwise reset ofKind to 0 to start counting the next value
                }
            }            
        j++; // increment inner loop counter   
        }
    }
    
    return "nothing"; // if nothing above has been returned already we assume this hand has no value
}


