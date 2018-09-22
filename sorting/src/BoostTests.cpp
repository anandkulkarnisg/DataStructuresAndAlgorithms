#define BOOST_TEST_MODULE SortUtilsTest
#include <vector>
#include <boost/test/unit_test.hpp>
#include <SortUtils.h>

using namespace std;

vector<int> testCaseVector = { 12, 10, 5, 9 , 3, 7, 11, 8 };
vector<int> ascending = { 3 , 5 , 7 , 8 , 9 , 10 , 11 , 12 };
vector<int> descending = { 12 , 11 , 10 , 9 , 8 , 7 , 5 , 3 };

BOOST_AUTO_TEST_CASE(AscendingInsertionSortTest) 
{
	vector<int> unitTestVec = testCaseVector; 
	SortUtils<int>::runInsertionSort(unitTestVec, SortOrder::asc);
	bool testCaseResultStatus = SortUtils<int>::arrayCompare(unitTestVec, ascending);
	BOOST_CHECK(testCaseResultStatus == true);
}

BOOST_AUTO_TEST_CASE(DescendingInsertionSortTest)
{
	vector<int> unitTestVec = testCaseVector;
	SortUtils<int>::runInsertionSort(unitTestVec, SortOrder::desc);
	bool testCaseResultStatus = SortUtils<int>::arrayCompare(unitTestVec, descending);
	BOOST_CHECK(testCaseResultStatus == true);
}

BOOST_AUTO_TEST_CASE(AscendingBubbleSortTest)
{
    vector<int> unitTestVec = testCaseVector;
    SortUtils<int>::runBubbleSort(unitTestVec, SortOrder::asc);
    bool testCaseResultStatus = SortUtils<int>::arrayCompare(unitTestVec, ascending);
    BOOST_CHECK(testCaseResultStatus == true);
}

BOOST_AUTO_TEST_CASE(DescendingBubbleSortTest)
{
    vector<int> unitTestVec = testCaseVector;
    SortUtils<int>::runBubbleSort(unitTestVec, SortOrder::desc);
    bool testCaseResultStatus = SortUtils<int>::arrayCompare(unitTestVec, descending);
    BOOST_CHECK(testCaseResultStatus == true);
}

BOOST_AUTO_TEST_CASE(AscendingSelectionSortTest)
{
    vector<int> unitTestVec = testCaseVector;
    SortUtils<int>::runSelectionSort(unitTestVec, SortOrder::asc);
    bool testCaseResultStatus = SortUtils<int>::arrayCompare(unitTestVec, ascending);
    BOOST_CHECK(testCaseResultStatus == true);
}

BOOST_AUTO_TEST_CASE(DescendingSelectionSortTest)
{
    vector<int> unitTestVec = testCaseVector;
    SortUtils<int>::runSelectionSort(unitTestVec, SortOrder::desc);
    bool testCaseResultStatus = SortUtils<int>::arrayCompare(unitTestVec, descending);
    BOOST_CHECK(testCaseResultStatus == true);
}

BOOST_AUTO_TEST_CASE(AscendingQuickSortTest)
{
    vector<int> unitTestVec = testCaseVector;
    SortUtils<int>::runQuickSort(unitTestVec, SortOrder::asc);
    bool testCaseResultStatus = SortUtils<int>::arrayCompare(unitTestVec, ascending);
    BOOST_CHECK(testCaseResultStatus == true);
}

BOOST_AUTO_TEST_CASE(DescendingQuickSortTest)
{
    vector<int> unitTestVec = testCaseVector;
    SortUtils<int>::runQuickSort(unitTestVec, SortOrder::desc);
    bool testCaseResultStatus = SortUtils<int>::arrayCompare(unitTestVec, descending);
    BOOST_CHECK(testCaseResultStatus == true);
}

BOOST_AUTO_TEST_CASE(AscendingHeapSortTest)
{
    vector<int> unitTestVec = testCaseVector;
    SortUtils<int>::runHeapSort(unitTestVec, SortOrder::asc);
    bool testCaseResultStatus = SortUtils<int>::arrayCompare(unitTestVec, ascending);
    BOOST_CHECK(testCaseResultStatus == true);
}

BOOST_AUTO_TEST_CASE(DescendingHeapSortTest)
{
    vector<int> unitTestVec = testCaseVector;
    SortUtils<int>::runHeapSort(unitTestVec, SortOrder::desc);
    bool testCaseResultStatus = SortUtils<int>::arrayCompare(unitTestVec, descending);
    BOOST_CHECK(testCaseResultStatus == true);
}

BOOST_AUTO_TEST_CASE(AscendingMergeSortTest)
{
    vector<int> unitTestVec = testCaseVector;
    SortUtils<int>::runMergeSort(unitTestVec, SortOrder::asc);
    bool testCaseResultStatus = SortUtils<int>::arrayCompare(unitTestVec, ascending);
    BOOST_CHECK(testCaseResultStatus == true);
}

BOOST_AUTO_TEST_CASE(DescendingMergeSortTest)
{
    vector<int> unitTestVec = testCaseVector;
    SortUtils<int>::runMergeSort(unitTestVec, SortOrder::desc);
    bool testCaseResultStatus = SortUtils<int>::arrayCompare(unitTestVec, descending);
    BOOST_CHECK(testCaseResultStatus == true);
}




