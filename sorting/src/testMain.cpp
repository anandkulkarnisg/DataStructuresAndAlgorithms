#include<iostream>
#include<string>

#include "SortUtils.h"

using namespace std;

int main(int argc, char* argv[])
{
	vector<int> inputArray = { 12, 10, 5, 9 , 3, 7, 11, 8 };

	SortUtils<int>::runInsertionSort(inputArray, SortOrder::asc);
	SortUtils<int>::showItems(inputArray);

	SortUtils<int>::runBubbleSort(inputArray, SortOrder::desc);
	SortUtils<int>::showItems(inputArray);
	
	SortUtils<int>::runSelectionSort(inputArray, SortOrder::asc);
	SortUtils<int>::showItems(inputArray);

	SortUtils<int>::runQuickSort(inputArray, SortOrder::desc);
	SortUtils<int>::showItems(inputArray);

	SortUtils<int>::runHeapSort(inputArray, SortOrder::asc);
	SortUtils<int>::showItems(inputArray);

	SortUtils<int>::runMergeSort(inputArray, SortOrder::desc);
	SortUtils<int>::showItems(inputArray);

	SortUtils<int>::runShellSort(inputArray, SortOrder::asc);
	SortUtils<int>::showItems(inputArray);
	
    SortUtils<int>::runTimSort(inputArray, SortOrder::desc);
    SortUtils<int>::showItems(inputArray);

	return(0);
}
