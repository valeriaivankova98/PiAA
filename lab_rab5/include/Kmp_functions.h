#pragma once

#include <iostream>
#include <vector>
#include <string>

void print(const std::vector<int>& index);

std::vector<int> prefix(std::string str);

std::vector<int> kmp(std::string str, std::string obr, const std::vector<int>& pi);

int shift(std::string str, std::string obr, const std::vector<int>& pi);
