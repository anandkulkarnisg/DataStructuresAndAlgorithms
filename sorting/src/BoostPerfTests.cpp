#define BOOST_TEST_MODULE SortUtilsTest

#include <vector>
#include <boost/test/unit_test.hpp>
#include <SortUtils.h>
#include <fstream>
#include <chrono>
#include <utility>
#include <functional>
#include <boost/test/unit_test_parameters.hpp>
#include <stdlib.h>

using namespace std;
using namespace std::chrono;

struct UnitTestConfig
{
	UnitTestConfig() : test_log( "PerfTestResults.log" )
	{
		boost::unit_test::unit_test_log.set_stream( test_log );
	}
	~UnitTestConfig()
	{
		test_log.close();
		boost::unit_test::unit_test_log.set_stream( std::cout );
	}
	std::ofstream test_log;
};

template<typename F, typename... Args> long MeasureRunTime(F func, Args&&... args)
{ 
	auto startPoint =  high_resolution_clock::now(); 
	func(std::forward<Args>(args)...);
	auto endPoint = high_resolution_clock::now();
	return(duration_cast<std::chrono::milliseconds>(endPoint-startPoint).count());
}

constexpr long int testLimit = 100000;
vector<int> testCaseVector; 

BOOST_GLOBAL_FIXTURE(UnitTestConfig);

BOOST_AUTO_TEST_CASE(prePareTestData) 
{
	testCaseVector.reserve(testLimit);		
	for(long int i=0; i<testLimit; ++i)
		testCaseVector.emplace_back(i);
	BOOST_CHECK(testCaseVector.size() == testLimit);
}

BOOST_AUTO_TEST_CASE(testInsertionSortPerf)
{
	auto callableFunc=std::bind(&SortUtils<int>::runInsertionSort, testCaseVector, SortOrder::desc);
	BOOST_TEST_MESSAGE("Initializing the InsertionSort Test for size of :" + to_string(testLimit));
	BOOST_TEST_MESSAGE("The InsertionSort took time of : " + to_string(MeasureRunTime(callableFunc)) + " Milli Seconds.");
	BOOST_CHECK(true);
}




