#include "day02.h"

#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

#include <iostream>

std::vector<std::vector<int>> readInput(std::string file)
{
    std::ifstream in(file);

    std::vector<std::vector<int>> res;
    std::string line;
    while (std::getline(in, line)) {
		std::vector<int> temp;
		std::stringstream ss(line);
		int num;
		while (ss >> num) {
			temp.push_back(num);
		}
        res.push_back(temp);
    }

    return res;
}

bool isSafe(const std::vector<int>& line)
{
	int ascending = 0;
	int descending = 0;
	for (int i = 0; i < line.size() - 1; i++) {
		ascending += (line[i] > line[i + 1] && abs(line[i] - line[i + 1]) <= 3);
		descending += (line[i] < line[i + 1] && abs(line[i] - line[i + 1]) <= 3);
	}

	return (ascending == line.size() - 1 || descending == line.size() - 1);
}

int process1(std::vector<std::vector<int>> input)
{
    int res = 0;
	for (const auto& line : input) {
		res += isSafe(line);
	}

	return res;
}

int process2(std::vector<std::vector<int>> input)
{
	int res = 0;
	for (const auto& line : input) {
		for (int i = 0; i < line.size(); i++) {
			auto temp = line;
			temp.erase(temp.begin() + i);
			if (isSafe(temp)) {
				res++;
				break;
			}
		}
	}

	return res;
}

std::pair<int, int> day02()
{
    auto input = readInput("inputs/day02.txt");
	
    return {process1(input), process2(input)};
}