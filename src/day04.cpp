#include "day04.h"

#include <fstream>
#include <vector>
#include <string>
#include "util.h"

using Input = std::vector<std::string>;

namespace
{
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

	bool matches(const Input& input, const Input& target, int x, int y)
	{
		for (int i = 0; i < target.size(); i++) {
			for (int j = 0; j < target[i].size(); j++) {
				if (target[i][j] != input[x + i][y + j] && target[i][j] != '.') {
					return false;
				}
			}
		}

		return true;
	}

	int countKernel(const Input& input, const Input& target)
	{
		int res = 0;

		for (int i = 0; i < input.size() - target.size() + 1; i++) {
			for (int j = 0; j < input[i].size() - target[0].size() + 1; j++) {
				if (matches(input, target, i, j)) {
					res++;
				}
			}
		}

		return res;
	}


	int process1(Input input)
	{
		int res = 0;

		res += countKernel(input, {"XMAS"}) + countKernel(input, {"SAMX"});
		res += countKernel(input, {"X", "M", "A", "S"}) + countKernel(input, {"S", "A", "M", "X"});
		res += countKernel(input, {"X...", ".M..", "..A.", "...S"}) + countKernel(input, {"S...", ".A..", "..M.", "...X"});
		res += countKernel(input, {"...S", "..A.", ".M..", "X..."}) + countKernel(input, {"...X", "..M.", ".A..", "S..."});

		return res;
	}

	int process2(Input input)
	{
		int res = 0;

		res += countKernel(input, {"M.S", ".A.", "M.S"});
		res += countKernel(input, {"M.M", ".A.", "S.S"});
		res += countKernel(input, {"S.M", ".A.", "S.M"});
		res += countKernel(input, {"S.S", ".A.", "M.M"});

		return res;
	}
}

std::pair<int, int> day04()
{
    auto input = readInput("inputs/day04.txt");
	
    return {process1(input), process2(input)};
}