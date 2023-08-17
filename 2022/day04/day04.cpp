
// https://adventofcode.com/2022/day/4

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <boost/algorithm/string.hpp>

int part1(std::vector<std::string> lines)
{
    int output = 0;
    for (std::string line : lines)
    {
        std::vector<std::string> assignments;
        boost::split(assignments, line, boost::is_any_of(","));

        std::vector<std::string> pair1;
        std::vector<std::string> pair2;

        boost::split(pair1, assignments[0], boost::is_any_of("-"));
        boost::split(pair2, assignments[1], boost::is_any_of("-"));
        int pair1_1 = std::stoi(pair1[0]), pair1_2 = std::stoi(pair1[1]), pair2_1 = std::stoi(pair2[0]), pair2_2 = std::stoi(pair2[1]);
        bool cond1 = (pair1_1 <= pair2_1) && (pair1_2 >= pair2_2);
        bool cond2 = (pair2_1 <= pair1_1) && (pair2_2 >= pair1_2);

        if (cond1 || cond2)
            output++;
    }

    return output;
}

int part2(std::vector<std::string> lines)
{
    int output = 0;
    for (std::string line : lines)
    {
        std::vector<std::string> assignments;
        boost::split(assignments, line, boost::is_any_of(","));

        std::vector<std::string> pair1;
        std::vector<std::string> pair2;

        boost::split(pair1, assignments[0], boost::is_any_of("-"));
        boost::split(pair2, assignments[1], boost::is_any_of("-"));
        int pair1_1 = std::stoi(pair1[0]), pair1_2 = std::stoi(pair1[1]), pair2_1 = std::stoi(pair2[0]), pair2_2 = std::stoi(pair2[1]);
        bool cond1 = (pair1_1 <= pair2_1) && (pair1_2 >= pair2_1);
        bool cond2 = (pair2_1 <= pair1_1) && (pair2_2 >= pair1_1);
        if (cond1 || cond2)
            output++;
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
}