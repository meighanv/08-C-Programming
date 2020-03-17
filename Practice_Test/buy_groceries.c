/* Write a function buyGroceries that accepts and int array and an int representing the size
of the array. Every two (2) indicies in the array represents an item number and quantity to purchase groceries.
The function will iterate the array and determine the total cost of groceries as a floating point number
based on the item number, quantity of each item, and cost of each item. There are four valid items.

item #  item   Cost
1       eggs   3.50
2       milk   2.25
3       bread  1.99
4       sugar  4.15

For example, the function may receive an array with the following:   1 5 2 3 4 4

resulting in 5 eggs at $3.50, 3 milks at $2.25 each, and 4 sugars at $4.15 each.

Compute a grand total based on quantity and cost of each item. If there is a quantity
of 5 or more for an item, a 5% discount is applied on those items. So, for the above
example there would be a 5% discount applied to the eggs.

Once the total is computed, round the value to an integer and return it.

The size passed for the array should always be an even number > 0, if it is not, the function
should return 0.

If any item number is not a 1, 2, 3, or 4, the function should return 0.

If any quantity is 0 or less, the function should return 0.

If a valid size is passed (even number) assume array is of that size.

Assume there will be no duplicate entries for an item number.

*/



#include <stdio.h>
#include <math.h>


int buyGroceries(int stuff[], int size)
{
	float cost [] = {3.5, 2.25, 1.99, 4.15};
	float total = 0.00;
	float subtotal;
	int quantity;
	int item;
	if (size % 2 != 0 || size <= 0)
	{
		return 0;
	}

	for(int i = 0; i < size; i++)
	{
		subtotal = 0.00;
		quantity = stuff[i+1];
		item = stuff[i];
		if (quantity <= 0)
		{
			return 0;
		}
		if (item > 4 || item < 1)
		{
			return 0;
		}
		
		subtotal += cost[item-1] * (float)quantity;
		if (stuff[i+1] >= 5)
		{
			total += subtotal * 0.95;
		}
		else
		{
			total += subtotal;
		}
		i++;
	}
	
	return round(total); //make sure you compile with the -lm switch
}

void main(void)
{
	int stuff[] = { 1, 3, 2, 5, 4, 4 };

	printf("%d\n", buyGroceries(stuff, 6));

	int stuff2[] = { 1, 5, 2, 5, 4, 5, 3, 5 };

	printf("%d\n", buyGroceries(stuff2, 8));

	int stuff3[] = { 1, 1, 2, 1, 3, 1, 4, 1 };

	printf("%d\n", buyGroceries(stuff3, 8));

	int stuff4[] = { 1, 6, 2, 7, 3, 8, 4, 15 };

	printf("%d\n", buyGroceries(stuff4, 8));
}
