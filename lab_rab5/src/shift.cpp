#include <iostream>
#include <vector>
#include "Kmp_functions.h"
using namespace std;


int main()
{
	string str1, str2;
	cin >> str1 >> str2;
	int index = shift(str1, str2, prefix(str2));

	cout << index;

	return 0;
}
