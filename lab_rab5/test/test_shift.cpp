#include "Kmp_functions.h"
#include <gtest/gtest.h>
using namespace std;

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
		resultShift = shift(text, pattern , prefix(pattern));
				
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