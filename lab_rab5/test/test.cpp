#include "Kmp_functions.h"
#include <gtest/gtest.h>


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
		if(!resultKMP.size())
			resultKMP = {-1};
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



struct allExpectedShift
{
	string text;
	string pattern;
	int expectShift;
};

struct allShiftResultData : testing::Test, testing::WithParamInterface<allExpectedShift>
{
	int resultShift;

	void SetUp() override
	{
		string text = GetParam().text;
		string pattern = GetParam().pattern;
		vector<int> index = kmp(text+text,pattern , prefix(pattern));
		if(index.size())
			resultShift = index[0];
		else
			resultShift = -1;
			
	}
};

TEST_P(allShiftResultData, ShiftTest)
{
	EXPECT_EQ(resultShift, GetParam().expectShift);
	
}

INSTANTIATE_TEST_CASE_P(ShiftTests, allShiftResultData,
testing::Values
(
	allExpectedShift{"ABCDEF", "DEFABC", 3},
	allExpectedShift{"12345", "67890", -1},
	allExpectedShift{"xxx", "xxx", 0},
	allExpectedShift{"zXz", "Xzz", 1},
	allExpectedShift{"test", "teststring", -1}
	
	
	
	
));



int main(int argc, char* argv[]){
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}