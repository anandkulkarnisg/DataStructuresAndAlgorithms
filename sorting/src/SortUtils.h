#include<iostream>
#include<string>
#include<vector>

#ifndef SortUtils_H
#define SortUtils_H

enum class SortType { insertion , bubble, selection, quick, heap, merge };
enum class SortOrder { asc , desc };

template<typename T> class SortUtils
{
	private:
		static bool sortOrder(const T&, const T&, const SortOrder&);
		static void doSwap(T&,T&);
		static void swapPtr(T*,T*);
		static void doQuickSort(std::vector<T>&, const int&, const int&, const SortOrder&);
		static int doPartition(std::vector<T>&, const int&, const int&, const SortOrder&);
		static void doHeapify(std::vector<T>&, const int&, const int&, const SortOrder&);
		static void doMergeSort(std::vector<T>&, const int&, const int&, const SortOrder&);
		static void mergeArrays(std::vector<T>&, const int&, const int&, const int&, const SortOrder&);

	public:
		static void runInsertionSort(std::vector<T>&, const SortOrder& = SortOrder::asc);
		static void runBubbleSort(std::vector<T>&, const SortOrder& = SortOrder::asc);
		static void runSelectionSort(std::vector<T>&, const SortOrder& = SortOrder::asc);
		static void runQuickSort(std::vector<T>&, const SortOrder& = SortOrder::asc);
		static void runHeapSort(std::vector<T>&, const SortOrder& = SortOrder::asc);
		static void runMergeSort(std::vector<T>&, const SortOrder& = SortOrder::asc);
		static void runSort(std::vector<T>&, const SortType&, const SortOrder& = SortOrder::asc);
		static void runShellSort(std::vector<T>&, const SortOrder& = SortOrder::asc);
		static bool isSorted(std::vector<T>&);
		static void showItems(const std::vector<T>&);
};

#endif
