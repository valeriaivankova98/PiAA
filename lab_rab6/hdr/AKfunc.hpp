#ifndef AKfunc_hpp
#define AKfunc_hpp

#include <iostream>
#include <vector>
#include <map>
#include <sstream>
#include <string>
#include <algorithm>
#include <cstring>

using namespace std;

struct Bohr{
    map<char,int> nextV; 
    vector<int> pat_num; 
    int suff_link; 
    map<char,int> auto_move; 
    int parent;
    int suff_flink; 
    bool flag; 
    char symb; 
};

Bohr makeBohr(int p, char c);
void initBohr();
void addstrBohr(const string& s, vector<string>& pattern);
int getAuto_move(int v, char ch);
int getSuff_link(int v);
int getSuff_flink(int v);
void checkForStandart(int v,int i,const vector<string>& pattern, map<int,vector<int>>& answ);
void checkForDjoker(int v,int i,vector<int>& count, const vector<int>& lenght);
void findAllPosForStandart(const string& s,const vector<string>& pattern, map<int,vector<int>>& answ);
void findAllPosForDjoker(const string& s,vector<int>& count, const vector<int>& lenght);
vector<int> spliter(stringstream& str_pat, char razd, vector<string>& pattern);
void printDj(const vector<int>& count, int stopper, int pattern_size);
void printSt(map<int, vector<int>>& answ);

#endif //AKfunc_hpp