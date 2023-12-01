// https://adventofcode.com/2023/day/1

#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <fstream>
#include <cctype>
#include <unordered_map>
#include <boost/algorithm/string.hpp>

int part1(std::vector<std::string> lines)
{
    int res = 0;
    for (auto line : lines)
    {
        int l = 0, r = line.size() - 1;
        std::string digit;
        while (l <= r)
        {
            if (std::isdigit(line[l]))
            {
                digit += line[l];
                break;
            }
            l++;
        }

        while (r >= 0)
        {
            if (std::isdigit(line[r]))
            {
                digit += line[r];
                break;
            }
            r--;
        }
        if (!digit.empty())
            res += stoi(digit);
    }
    return res;
}

int part2(std::vector<std::string> lines)
{
    // preprocess string to get vector of ints, then get leftmost and rightmost
    std::unordered_map<std::string, int> num_map({{"one", 1},
                                                  {"two", 2},
                                                  {"three", 3},
                                                  {"four", 4},
                                                  {"five", 5},
                                                  {"six", 6},
                                                  {"seven", 7},
                                                  {"eight", 8},
                                                  {"nine", 9}});
    int res = 0;
    for (auto line : lines)
    {
        int n = line.size();
        std::vector<int> nums;
        for (int i = 0; i < n; i++)
        {
            if (std::isdigit(line[i]))
            {
                nums.push_back(line[i] - '0');
            }
            else
            // probably a smarter way of doing this :)
            {
                if (i + 2 < n)
                {
                    std::string substring = line.substr(i, 3);
                    if (num_map.find(substring) != num_map.end())
                        nums.push_back(num_map[substring]);
                }

                if (i + 3 < n)
                {
                    std::string substring = line.substr(i, 4);
                    if (num_map.find(substring) != num_map.end())
                        nums.push_back(num_map[substring]);
                }

                if (i + 4 < n)
                {
                    std::string substring = line.substr(i, 5);
                    if (num_map.find(substring) != num_map.end())
                        nums.push_back(num_map[substring]);
                }
            }
        }
        res += nums.front() * 10 + nums.back();
    }
    return res;
}
int main(int argc, char *argv[])
{
    if (argc == 2)
    {
        std::fstream file(argv[1]);
        if (!file)
        {
            std::cerr << "Cannot open file!" << std::endl;
            return EXIT_FAILURE;
        }

        std::string line;
        std::vector<std::string> lines;
        while (std::getline(file, line))
        {
            lines.push_back(line);
        }

        std::cout << part1(lines) << std::endl;
        std::cout << part2(lines) << std::endl;
    }
    return EXIT_SUCCESS;
}