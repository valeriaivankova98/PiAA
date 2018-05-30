#include "Kmp_functions.h"
#include <gtest/gtest.h>
using namespace std;

struct allExpectedKMP
{
	string text;
	string pattern;
	vector<int> expectKMP;
};

struct allKMPResultData : testing::Test, testing::WithParamInterface<allExpectedKMP>
{
	vector<int> resultKMP;

	void SetUp() override
	{
		string text = GetParam().text;
		string pattern = GetParam().pattern;
		resultKMP = kmp(text,pattern, prefix(pattern));
	}
};

TEST_P(allKMPResultData, KMPTest)
{
	EXPECT_EQ(resultKMP, GetParam().expectKMP);
	
}

INSTANTIATE_TEST_CASE_P(KMPTests, allKMPResultData,
testing::Values
(
	allExpectedKMP{"TESTSTRING", "A", {-1}},
	allExpectedKMP{"TESTSTRING", "E", {1}},
	allExpectedKMP{"1212121212", "2", {1,3,5,7,9}},
	allExpectedKMP{"ABCDEFGHIJKLMNOPQRSTUVWXYZ", "1", {-1}},
	allExpectedKMP{"HELLO", "HELLO", {0}},
	allExpectedKMP{"AAAAAAAAAAAAAAAAAAAAAAAAAAAA", "A", {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27}}
));


int main(int argc, char* argv[]){
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}