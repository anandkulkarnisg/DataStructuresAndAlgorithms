#define BOOST_TEST_MODULE const_string test
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

