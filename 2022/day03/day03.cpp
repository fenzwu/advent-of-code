// https://adventofcode.com/2022/day/3

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <unordered_set>

int getPriority(char c)
{
    if (islower(c))
    {
        return (c - 'a' + 1);
    }
    else if (isupper(c))
    {
        return (c - 'A' + 27);
    }
    return 0;
}

int part1(std::vector<std::string> lines)
{
    int output = 0;
    for (std::string line : lines)
    {
        std::string::iterator mid = line.begin() + line.size() / 2;
        std::unordered_set<char> seen(line.begin(), mid);
        for (auto iter = mid; iter != line.end(); ++iter)
        {
            char c = *iter;
            if (seen.count(c) == 1)
            {
                output += getPriority(c);
                break;
            }
        }
    }
    return output;
}

int part2(std::vector<std::string> lines)
{
    int output = 0;
    for (int i = 0; i < lines.size(); i += 3)
    {
        std::unordered_set<char> seen1(lines[i].begin(), lines[i].end());
        std::unordered_set<char> seen2(lines[i + 1].begin(), lines[i + 1].end());
        for (char c : lines[i + 2])
        {
            if (seen1.count(c) && seen2.count(c))
            {
                output += getPriority(c);
                break;
            }
        }
    }
    return output;
}

int main(int argc, char *argv[])
{
    std::vector<std::string> lines;
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
            lines.push_back(line);
        }

        std::cout << "Solution for part1: " << part1(lines) << std::endl;
        std::cout << "Solution for part2: " << part2(lines) << std::endl;
    }
    else
    {
        std::cerr << "Please provide path to file" << std::endl;
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}