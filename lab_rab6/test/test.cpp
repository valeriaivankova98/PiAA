#include <gtest/gtest.h>
#include "../hdr/AKfunc.hpp"

using ::testing::TestWithParam;
using ::testing::Values;

map<int, vector<int>> resStandart(const string& text,const vector<string>& pattern) {
    initBohr();
    map<int, vector<int>> answ;
    answ.clear();
    vector<string> dop;
    for(const auto& patt : pattern) {
       addstrBohr(patt, dop);
   }
   findAllPosForStandart(text, pattern, answ);
   for(auto& it: answ)
        sort(it.second.begin(),it.second.end());
   return answ;
}

vector<int> getPosfromCount(const vector<int>& count, int stopper, int pattern_size){
    vector<int> pos;
    for(int i=0;i<stopper;i++){
        if(count[i]==pattern_size)
            pos.push_back(i+1);
    }
    return pos;
}

vector<int> resDjoker(const string& text, const string& temp, char razd) {
    initBohr();
    stringstream str_pat(temp);
    vector<int> count(text.size(),0);
    vector<string> pattern;
    vector<int> lenght = spliter(str_pat, razd, pattern);
    findAllPosForDjoker(text, count, lenght);
    return getPosfromCount(count,text.size()-temp.size()+1,pattern.size());
}

struct StandartTest
{
    string text;
	vector<string> pattern;
	map<int, vector<int>> expected_answ;
};

class StandartFixture : public TestWithParam<StandartTest>
{
public:
	virtual void SetUp() {
	    answ = resStandart(GetParam().text, GetParam().pattern);
	}
    virtual void TearDown() { }

protected:
    map<int, vector<int>> answ;
};

INSTANTIATE_TEST_CASE_P(StandartInstantiate, StandartFixture,
Values(
    StandartTest{"CCCA", {"CC"}, {{1,{1}},{2,{1}}}},
    StandartTest{"CCCA", {"CC", "C","CCC"}, {{1,{1,2,3}},{2,{1,2}},{3,{2}}}},
    StandartTest{"AHFSHRSJER", {"SH", "FSH", "M", "R","HFSHR"}, {{2,{5}},{3,{2}},{4,{1}},{6,{4}},{10,{4}}}},
    StandartTest{"KORASIK", {"NE", "NET"}, {}}
));

TEST_P(StandartFixture, StandartTest) {
    ASSERT_EQ(GetParam().expected_answ, answ);
}

struct DjokerTest
{
    string text;
	string temp;
	char razd;
	vector<int> expected_poss;
};

class DjokerFixture : public TestWithParam<DjokerTest>
{
public:
	virtual void SetUp() {
	    poss = resDjoker(GetParam().text, GetParam().temp, GetParam().razd);
	}
    virtual void TearDown() { }

protected:
	vector<int> poss;
};

INSTANTIATE_TEST_CASE_P(DjokerInstantiate, DjokerFixture,
Values(
	DjokerTest{"ACT", "A$", '$', {1}},
	DjokerTest{"AAA", "A*", '*', {1, 2}},
	DjokerTest{"AAAAA", "A***", '*', {1, 2}},
	DjokerTest{"AAAAAA", "***A", '*', {1, 2, 3}},
	DjokerTest{"AAAAA", "**A**", '*', {1}},
	DjokerTest{"AAAA", "A*A", '*', {1, 2}},
	DjokerTest{"ASDAVDAGD", "A+D", '+', {1,4,7}},
	DjokerTest{"AHOCORASICK", "AH***R*SI*K", '*', {1}},
	DjokerTest{"QWERTYUIOP", "F/D/S", '/', {}}
));

TEST_P(DjokerFixture, DjokerTest) {
    ASSERT_EQ(GetParam().expected_poss, poss);
}


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}