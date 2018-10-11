#include<iostream>
#include<string>

using namespace std;

int doInterpolationSearch(const int arr[], const int& itemToBeFound, const size_t& size)
{
	int low=0;
	int high=size-1;
	int idxPos=-1;
	int pos;

	while(low<=high && low>=0 && high<=size-1)
	{
		// Linear interpolation formula.
		// (arr[0],low) is lower bound , (arr[size-1], high) is upper bound , itemto be found is (itemToBeFound, idxPos).
		// We know itemToBeFound just need to calculate the idxPos.

		pos = low + (((double)(high-low)/(arr[high]-arr[low]))*(itemToBeFound - arr[low])); 
		if(arr[pos]<itemToBeFound)
			low=pos+1;		
		else if(arr[pos]>itemToBeFound)
			high=pos-1;
		else
		{
			idxPos=pos;
			break;
		}
	}
	return(idxPos);
}

int main(int argc, char* argv[])
{
	int arr[] =  {10, 12, 13, 16, 18, 19, 20, 21, 22, 23, 24, 33, 35, 42, 47}; 
	size_t size = sizeof(arr)/sizeof(arr[0]);
	for(unsigned int i=0; i<size-1; ++i)
	{
		int idxPos=doInterpolationSearch(arr, arr[i], size);
		cout << "The item = " << arr[i] << " is found at index = " << idxPos << endl;
	}
	cout << "The item = " << -5 << " is found at index = " << doInterpolationSearch(arr, -5, size) << endl;
	cout << "The item = " << 100 << " is found at index = " << doInterpolationSearch(arr, 100, size) << endl;
	return(0);
}
