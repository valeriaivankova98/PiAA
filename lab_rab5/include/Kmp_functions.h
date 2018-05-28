#include <iostream>
#include <vector>
using namespace std;

void print(const vector<int>& index);

vector<int> prefix(string str);

vector<int> kmp(string str, string obr, const vector<int>& pi);