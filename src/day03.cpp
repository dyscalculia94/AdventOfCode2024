#include "day03.h"

#include <fstream>
#include <vector>
#include <string>
#include "util.h"

#include <regex>

#include <iostream>

using Input = std::vector<std::string>;

Input readInput(std::string file)
{
    std::ifstream in(file);

    Input res;
	std::string line;
    while (std::getline(in, line)) {
		res.push_back(line);
	}

    return res;
}

int process(std::string input)
{
	int res = 0;
	
	std::regex expressionRegex("mul\\([0-9]{1,3},[0-9]{1,3}\\)");
	auto begin = std::sregex_iterator(input.begin(), input.end(), expressionRegex);
    auto end = std::sregex_iterator();

	for (auto i = begin; i != end; i++) {
		auto match = i->str();
		std::regex numbersRegex("[0-9]{1,3}");
		auto numsBegin = std::sregex_iterator(match.begin(), match.end(), numbersRegex);
    	auto numsEnd = std::sregex_iterator();
		int prod = 1;
		for (auto j = numsBegin; j != numsEnd; j++) {
			prod *= std::stoi(j->str());
		}

		res += prod;
	}
	
	return res;
}

int process1(Input input)
{
	std::string modified = "";
	for (const auto& line : input) {
		modified += line;
	}

    return process(modified);
}

int process2(Input input)
{
	int res = 0;

	std::string modified = "";
	for (const auto& line : input) {
		modified += line;
	}

	auto parts = split(modified, "don't()");
	modified = parts[0];
	for (int i = 1; i < parts.size(); i++) {
		auto pos = parts[i].find("do()");
		if (pos != std::string::npos) {
			modified += parts[i].substr(pos + 4);
		}
	}
	
	return process(modified);
}

std::pair<int, int> day03()
{
    auto input = readInput("inputs/day03.txt");
	
    return {process1(input), process2(input)};
}