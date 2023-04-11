// https://adventofcode.com/2022/day/2

#include <vector>
#include <string>
#include <fstream>
#include <iostream>

int part1(std::vector<std::pair<char, char>> lines)
{
    const std::vector<std::vector<int>> scoreMatrix = {
        {4, 8, 3},
        {1, 5, 9},
        {7, 2, 6}};
    int score = 0;
    for (std::pair<char, char> line : lines)
    {
        score += scoreMatrix[line.first - 'A'][line.second - 'X'];
    }
    return score;
}

int part2(std::vector<std::pair<char, char>> lines)
{
    const std::vector<std::vector<int>> scoreMatrix = {
        {3, 4, 8},
        {1, 5, 9},
        {2, 6, 7}};
    int score = 0;
    for (std::pair<char, char> line : lines)
    {
        score += scoreMatrix[line.first - 'A'][line.second - 'X'];
    }
    return score;
}

int main(int argc, char *argv[])
{

    std::vector<std::pair<char, char>> lines;

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
            lines.push_back(std::make_pair(line[0], line[2]));
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