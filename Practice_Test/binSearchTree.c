#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "TestCode.h"
#define size(x) sizeof(x)/sizeof(x[0])
/*

A Binary Search Tree (BST) is a tree in which all the nodes follow the below-mentioned properties:
        The left sub-tree of a node has a value less than its parent node's value.
        The right sub-tree of a node has a value greater than to its parent node's value.
        In this scenario, no duplicate values are allowed.
        
Task #1

Write the fucntion buildBST that receives an array of integers (nums) and an int representing the size
of the array. The function will build The BST by:

    1. Iterating the array
    2. Using the provided numNode struct defined in TestCode.h and creating Nodes for each value
       in the array.
    3. Inserting each Node into the BST.

If a value in the array is already in the BST, ignore the value and continue processing the rest of 
the array.

When complete, the function will return a pointer to the root node of the BST.

Task #2

Write the function destroyBST that receives a pointer to the root of a BST (root).
The function will visit each node in the BST and free each node essentially
deleting all nodes in the BST. The function will return a count of the total
number of nodes freed.

*/
struct numNode* create(int data) // Function to create a node
{
    struct numNode *temp; //declaring a numNode ptr
    temp = (struct numNode*)malloc(sizeof(struct numNode)); // allocating memory for the node
    temp->val = data; //setting val attribute to value of data
    temp->left=temp->right=NULL; //setting the left and right pointers to NULL
    return temp; //returning to calling function
}

void insert(struct numNode *root,struct numNode *temp) //Function to insert a node we assume exists
{
	if(temp->val < root->val)// checking new node value to determine left or right of current node 
	{
		if(root->left!=NULL) //check if left is not NULL recursive call to left node
			insert(root->left,temp);
		else
			root->left=temp; // if left is null then set left pointer to temp (new node)
	}
	
	if(temp->val > root->val) // If the value is greater than current node value go right
	{
		if(root->right!=NULL) //check if current right ptr is null
			insert(root->right,temp); //if it isn't , recursive call to look right
		else
			root->right=temp; // otherwise set right ptr to temp
	}
}

struct numNode* buildBST(int nums[], int size) // Function to build out BST
{
    struct numNode* root; // create the root node ptr
    root = (struct numNode*)malloc(sizeof(struct numNode)); //allocate space for root node
    root->val = nums[0]; // Set the val attribute of root node
    root->left = root->right = NULL; // Set the left and right numNode pointers to NULL  
    for (int i = 1; i < size; i++) // loop through the rest of the elements in nums
    {
        struct numNode* temp = create(nums[i]); //Create a temp numNode
        insert(root, temp); //insert temp numNode
    }
    return root; //return root numNode ptr to calling function
}


static int count = 0; //Init static count variable to count destroyed nodes
int destroyBST(struct numNode *node) //Function for tree destruction
{
    if (node == NULL) // if the node passed as arg is NULL
    {
        return 0; 
    }
    else //if the node passed as arg is not NULL
    {
        destroyBST(node->left); recursive call to destroy left node
        destroyBST(node->right); recursive call to destroy right node
        free(node); //once the left and right nodes have been destroyed free current node
        count++; //increment the static count variable
    }
    return count; //return the value of static count variable to calling function
}

void preorder(struct numNode *root) // Function for preorder printing of BST
{
	if(root!=NULL) //if root is not NULL
	{
		printf("%d ",root->val); // ... print the value
		preorder(root->left); //recursive call on left ptr
		preorder(root->right); //recursive call on right ptr
	}
}

void postorder(struct numNode *root) // Similar to above except in post order
{
	if(root!=NULL) 
	{
		postorder(root->left);
		postorder(root->right);
		printf("%d ",root->val);
	}
}

void inorder(struct numNode *root) // Similar to above except in order
{
	if(root!=NULL)
	{
		inorder(root->left);
		printf("%d ",root->val);
		inorder(root->right);
	}  
}
