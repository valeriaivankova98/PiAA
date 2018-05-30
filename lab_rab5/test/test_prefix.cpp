#include "Kmp_functions.h"
#include <gtest/gtest.h>
using namespace std;

struct allExpectedPrefix
{
	string text;
	vector<int> expectPrefix;
};

struct allPrefixResultData : testing::Test, testing::WithParamInterface<allExpectedPrefix>
{
	vector<int> resultKMP;

	void SetUp() override
	{
		string text = GetParam().text;
		resultKMP = prefix(text);
	}
};

TEST_P(allPrefixResultData, PrefixTest)
{
	EXPECT_EQ(resultKMP, GetParam().expectPrefix);
	
}

INSTANTIATE_TEST_CASE_P(PrefixTests, allPrefixResultData,
testing::Values
(
	allExpectedPrefix{"1234123412341234", {0,0,0,0,1,2,3,4,5,6,7,8,9,10,11,12}},
	allExpectedPrefix{"ABCDEFGHIJKLMNOPQRSTUVWXYZ", {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}},
	allExpectedPrefix{"AAAAAAAAAAAAAAAAAAAAAAAAA",{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24}},
	allExpectedPrefix{"x", {0}},
	allExpectedPrefix{"xx", {0,1}},
	allExpectedPrefix{"xxx", {0,1,2}}
	
));

int main(int argc, char* argv[]){
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}