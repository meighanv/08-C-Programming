#include<stdio.h>
#include<stdlib.h>
#define size(x) sizeof(x)/sizeof(x[0])

int flushIn()
{
    char c;
    while ((c = fgetc(stdin)) != '\n' && c != EOF);
}

int binarySearch(const int *arr, int l, int r, int k){
	if(l >r){
		return -1;
	} else{
		int m = (l + r) / 2;

	if(arr[m] == k){
		return m;
	}else if (k < arr[m]){
		return binarySearch(arr, l , m-1, k);
	} else if(arr[m] < k) {
		return binarySearch(arr, m+1, r, k);
	}
    }
}

int main(int argc, char **argv){

	int find;
    int arr[] = { 5, 10, 15, 20, 25, 26, 34, 56, 77};
    printf("Please provide the element to find:");
    scanf("%d", &find);
    flushIn();
	int indexOf = binarySearch(arr, 0, size(arr)-1, find);
	printf("found the element at index %d\n", indexOf);

	return 0;
}