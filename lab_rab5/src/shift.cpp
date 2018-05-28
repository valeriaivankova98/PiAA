#include <iostream>
#include <vector>
#include "Kmp_functions.h"
using namespace std;


int main()
{
    string str1, str2;
    cin>>str1>>str2;
    vector<int> pi=prefix(str2);
    vector<int> index=kmp(str1+str1,str2,pi);
    if(index.size())
	{
        cout<<index[0];
    }
    else
        cout<<"-1";
    return 0;
}
