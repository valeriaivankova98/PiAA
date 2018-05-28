#include "Kmp_functions.h"

void print(const vector<int>& index) //печать результата
{ 
    for(const auto& it: index)
	{
        cout<<it;
        if(it!=index[index.size()-1])
            cout<<",";
    }
}

vector<int> prefix(string str) //нахождение префикса
{ 
    int n = str.size();
    vector<int> pi(n);
    for (size_t i=1; i<n; ++i)
	{
        size_t j = pi[i-1];
        while ((j > 0) && (str[i] != str[j]))
            j = pi[j-1];
        if (str[i] == str[j])
            ++j;
        pi[i] = j;
    }
     return pi;
}

vector<int> kmp(string str, string obr, const vector<int>& pi)
{
    vector<int> index;
    int j=0;
    for (size_t i=0; i<str.size(); ++i)
	{
        while ((j > 0) && str[i] != obr[j])
            j = pi[j-1];
        if (str[i] == obr[j])
            ++j;
        if (j==obr.size())
            index.push_back(i-j+1);
    }
    return index;
}