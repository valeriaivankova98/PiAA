#include <iostream>
#include <vector>
#include "Kmp_functions.h"
using namespace std;

int main()
{
    string pattern, text;
    cin>>text>>pattern;
    vector<int> pi=prefix(text);
    vector<int> index=kmp(pattern,text,pi);
    if(index.size())
	{
        print(index);
    }
    else
        cout<<"-1";
    return 0;
}