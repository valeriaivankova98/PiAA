#include "Kmp_functions.h"

void print(const std::vector<int>& index) //печать результата
{
	for (const auto& it : index)
	{
		std::cout << it;
		if (it != index[index.size() - 1])
			std::cout << ",";
	}
}

std::vector<int> prefix(std::string str) //нахождение префикса
{
	size_t n = str.size();
	std::vector<int> pi(n);
	for (size_t i = 1; i < n; ++i)
	{
		size_t j = pi[i - 1];
		while ((j > 0) && (str[i] != str[j]))
			j = pi[j - 1];
		if (str[i] == str[j])
			++j;
		pi[i] = j;
	}
	return pi;
}

std::vector<int> kmp(std::string str, std::string obr, const std::vector<int>& pi)
{
	std::vector<int> index;
	size_t j = 0;
	for (size_t i = 0; i<str.size(); ++i)
	{
		while ((j > 0) && str[i] != obr[j])
			j = pi[j - 1];
		if (str[i] == obr[j])
			++j;
		if (j == obr.size())
			index.push_back(i - j + 1);
	}

	if (index.empty())
		index.resize(1, -1);
	
	return index;
}


int shift(std::string str, std::string obr, const std::vector<int>& pi)
{
	if (str.size() != obr.size())
		return -1;
	std::vector<int> index = kmp(str + str, obr, pi);

	if (index.empty())
		return -1;

	return index[0];
}