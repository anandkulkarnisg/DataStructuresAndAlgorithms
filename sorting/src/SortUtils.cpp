#include<iostream>
#include<string>

#include "SortUtils.h"
#include "SortUtilsImpl.h"

using namespace std;

template<typename T> void SortUtils<T>::showItems(const vector<T>& input)
{
	size_t size = input.size();
	for(unsigned int i=0; i<size-1; ++i)
		cout << input[i] << " , ";
	cout << input[size-1] << '\n';	
}

template<typename T> void SortUtils<T>::swapPtr(T* item1, T* item2)
{
	T temp = *item1;
	*item1 = *item2;
	*item2 = temp;
}

template<typename T> bool SortUtils<T>::sortOrder(const T& item1, const T& item2, const SortOrder& sortOrder)
{
	if(sortOrder==SortOrder::asc)
		return(item1>=item2);
	else
		return(item1<item2);
}

template<typename T> void SortUtils<T>::runInsertionSort(vector<T>& input, const SortOrder& sortOrder)
{
	size_t size = input.size();
	for(unsigned int i=1; i<size; ++i)
	{
		T key=input[i];
		int j=i-1;
		while(j>=0 && SortUtils<T>::sortOrder(input[j], key, sortOrder))
		{
			input[j+1]=input[j];
			--j;
		}			
		input[j+1]=key;
	}	
}

template<typename T> void SortUtils<T>::runBubbleSort(vector<T>& input, const SortOrder& sortOrder)
{
	size_t size = input.size();
	for(unsigned int i=0 ; i<size; ++i)
	{
		for(unsigned int j=i+1; j<size; ++j)
		{
			if(SortUtils<T>::sortOrder(input[i], input[j], sortOrder))
			{
				swapPtr(&input[i], &input[j]);
			}
		}
	}
}

template<typename T> void SortUtils<T>::runSelectionSort(vector<T>& input, const SortOrder& sortOrder)
{
	size_t size = input.size();
	for(unsigned int i=0; i<size; ++i)
	{
		unsigned int min = i;
		for(unsigned int j=i+1; j<size; ++j)
		{
			if(SortUtils<T>::sortOrder(input[min], input[j], sortOrder))
				min = j;
		}
		if( min != i)
			SortUtils<T>::swapPtr(&input[min], &input[i]);
	}
}

template<typename T> int SortUtils<T>::doPartition(vector<T>& input, const int& low, const int& high, const SortOrder& sortOrder)
{
	T pivot=input[high];
	int i = low - 1;

	for(int j=low; j<high; ++j)
	{
		if(SortUtils<T>::sortOrder(pivot, input[j], sortOrder))
		{
			++i;
			SortUtils<T>::swapPtr(&input[i], &input[j]);			
		}
	}
	SortUtils<T>::swapPtr(&input[i+1], &input[high]);
	return(i+1);
}

template<typename T> void SortUtils<T>::doQuickSort(vector<T>& input, const int& low, const int& high, const SortOrder& sortOrder)
{
	if(low<high)
	{
		int partitionIdx=doPartition(input, low, high, sortOrder);
		doQuickSort(input, low, partitionIdx-1, sortOrder);
		doQuickSort(input, partitionIdx+1, high, sortOrder);
	}
}

template<typename T> void SortUtils<T>::runQuickSort(vector<T>& input, const SortOrder& sortOrder)
{
	doQuickSort(input, 0, input.size()-1, sortOrder);
}

template<typename T> void SortUtils<T>::doHeapify(vector<T>& input, const int& size, const int& i, const SortOrder& sortOrder)
{
	int largest=i;
	int leftChildIdx= 2*i+1;
	int rightChildIdx=2*i+2;

	if(leftChildIdx < size && SortUtils<T>::sortOrder(input[leftChildIdx], input[largest], sortOrder))
		largest = leftChildIdx;

	if(rightChildIdx < size && SortUtils<T>::sortOrder(input[rightChildIdx], input[largest], sortOrder))
		largest = rightChildIdx;

	if(largest != i)
	{
		SortUtils<T>::swapPtr(&input[i], &input[largest]);
		doHeapify(input, size, largest, sortOrder);
	}
}

template<typename T> void SortUtils<T>::runHeapSort(vector<T>& input, const SortOrder& sortOrder)
{
	int size = input.size();
	for(int i=(size/2)-1; i>=0; --i)
	{
		doHeapify(input, size, i, sortOrder);
	}

	for(int i=size-1; i>=0; --i)
	{
		SortUtils<T>::swapPtr(&input[i], &input[0]);
		doHeapify(input, i, 0, sortOrder);
	}
}

template<typename T> void SortUtils<T>::mergeArrays(vector<T>& input, const int& low, const int& mid, const int& high, const SortOrder& sortOrder)
{
	// First we need to allocate two arrays for left and right portion of the input array.	
	int leftArraySize = mid - low + 1;
	int rightArraySize = high - mid;
	int leftArray[leftArraySize], rightArray[rightArraySize];

	// We now need to populate the arrays from the input array.
	for(int i=0; i<leftArraySize; ++i)
		leftArray[i] = input[low+i];

	for(int j=0; j<rightArraySize; ++j)
		rightArray[j]= input[mid+j+1];

	// Now that the arrays are ready we compare and sort them and write them into input back.
	int i , j, k;
	i = j = 0;
	k = low;

	while(i<leftArraySize && j<rightArraySize)
	{
		if(SortUtils<T>::sortOrder(rightArray[j], leftArray[i], sortOrder))
		{
			input[k]=leftArray[i];
			++i;
		}
		else
		{
			input[k]=rightArray[j];
			++j;
		}	
		++k;
	}

	// Now since both left and right arrays are not of the same size then need to exhausted. Only one of the below loops actually completes.
	while(i<leftArraySize)
	{
		input[k]=leftArray[i];
		++i;++k;
	}
	while(j<rightArraySize)
	{
		input[k]=rightArray[j];
		++j;++k;
	}
}

template<typename T> void SortUtils<T>::doMergeSort(vector<T>& input, const int& low, const int& high, const SortOrder& sortOrder)
{
	if(low<high)
	{
		int mid = (low+high)/2;
		doMergeSort(input, low, mid, sortOrder);
		doMergeSort(input, mid+1, high, sortOrder);
		mergeArrays(input, low, mid, high, sortOrder);
	}	
}

template<typename T> void SortUtils<T>::runMergeSort(vector<T>& input, const SortOrder& sortOrder)
{
	doMergeSort(input, 0, input.size()-1, sortOrder);
}

template<typename T> void SortUtils<T>::runShellSort(vector<T>& input, const SortOrder& sortOrder)
{
	size_t size = input.size();
	for(int gap=(size/2); gap>0; gap/=2)
	{
		for(unsigned int j=gap; j<size; ++j)
		{
			for(int k=(j-gap); k>=0; k-=gap)
			{
				if(SortUtils<T>::sortOrder(input[k], input[k+gap], sortOrder))
					SortUtils<T>::swapPtr(&input[k+gap], &input[k]);
			}
		}
	}
}

template<typename T> bool SortUtils<T>::arrayCompare(const vector<T>& vec1, const vector<T>& vec2)
{
	if(vec1.size() != vec2.size())
		return(false);
	size_t size = vec1.size();
	for(unsigned int i=0; i<size; ++i)
	{
		if(vec1[i] != vec2[i])
			return(false);
	} 
	return(true);
}

