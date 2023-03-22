// https://adventofcode.com/2022/day/1

#include <vector>
#include <string>
#include <fstream>
#include <iostream>

uint64_t part1(std::vector<std::string> lines)
{
    uint64_t max = 0;
    uint64_t sum = 0;
    for (const auto &line : lines)
    {
        if (!line.empty())
        {
            sum += std::stoull(line);
        }
        else
        {
            if (sum > max)
            {
                max = sum;
            }
            sum = 0;
        }
    }
    return max;
}

uint64_t part2(std::vector<std::string> lines)
{
    // assume sum1 >= sum2 >= sum3
    uint64_t sum1 = 0, sum2 = 0, sum3 = 0;
    uint64_t sum = 0;
    for (const auto &line : lines)
    {
        if (!line.empty())
        {
            sum += std::stoull(line);
        }
        else
        {
            if (sum >= sum1)
            {
                sum3 = sum2;
                sum2 = sum1;
                sum1 = sum;
            }
            else if (sum > sum2)
            {
                sum3 = sum2;
                sum2 = sum;
            }
            else if (sum > sum3)
            {
                sum3 = sum;
            }
            sum = 0;
        }
    }
    return sum1 + sum2 + sum3;
}

int main(int argc, char *argv[])
{
    std::vector<std::string> data;
    if (argc == 2)
    {
        std::fstream file(argv[1]);
        if (!file)
        {
            std::cerr << "Cannot open file!" << std::endl;
            return EXIT_FAILURE;
        }
        std::string line;
        while (std::getline(file, line))
        {
            data.push_back(line);
        }
        std::cout << "Solution for part1: " << part1(data) << std::endl;
        std::cout << "Solution for part2: " << part2(data) << std::endl;
    }
    else
    {
        std::cerr << "Please provide path to file" << std::endl;
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}