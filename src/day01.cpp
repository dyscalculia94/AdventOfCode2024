#include "day01.h"

#include <fstream>
#include <vector>
#include <unordered_map>
#include <algorithm>

std::pair<std::vector<int>, std::vector<int>> readInput(std::string file)
{
    std::ifstream in(file);

    std::pair<std::vector<int>, std::vector<int>> res;
    int a, b;
    while (in >> a >> b) {
        res.first.push_back(a);
		res.second.push_back(b);
    }

    return res;
}

int process1(std::pair<std::vector<int>, std::vector<int>> input)
{
    std::sort(input.first.begin(), input.first.end());
	std::sort(input.second.begin(), input.second.end());

	int res = 0;
	for (int i = 0; i < input.first.size(); i++) {
		res += std::abs(input.first[i] - input.second[i]);
	}

	return res;
}

int process2(std::pair<std::vector<int>, std::vector<int>> input)
{
	std::unordered_map<int, int> freq;
	for (int i : input.second) {
		freq[i]++;
	}

    int res = 0;
	for (int i : input.first) {
		res += (i * freq[i]);
	}

	return res;
}

std::pair<int, int> day01()
{
    auto input = readInput("inputs/day01.txt");
	
    return {process1(input), process2(input)};
}