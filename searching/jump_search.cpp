#include<iostream>
#include<string>
#include<cmath>

using namespace std;

int doJumpSearch(int arr[], int x, int n) 
{ 
	// Finding block size to be jumped 
	int step = sqrt(n); 

	// Finding the block where element is 
	// present (if it is present) 
	int prev = 0; 
	while (arr[min(step, n)-1] < x) 
	{ 
		prev = step; 
		step += sqrt(n); 
		cout << "step = " << step << endl;
		if (prev >= n) 
			return -1; 
	} 

	// Doing a linear search for x in block 
	// beginning with prev. 
	while (arr[prev] < x) 
	{ 
		prev++; 

		// If we reached next block or end of 
		// array, element is not present. 
		if (prev == min(step, n)) 
			return -1; 
	} 
	// If element is found 
	if (arr[prev] == x) 
		return prev; 

	return -1; 
} 

int main(int argc, char* argv[])
{

	int arr[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610 };
	size_t size = sizeof(arr)/sizeof(arr[0]);
	int itemToBeFound = 21;
	int idxPos = doJumpSearch(arr, itemToBeFound, size);
	if(idxPos<0)
		cout << "not found" << endl;
	else
		cout << "found at index = " << idxPos << endl;
	return(0);
}
