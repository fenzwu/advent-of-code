// https://adventofcode.com/2023/day/2

#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <fstream>
#include <cctype>
#include <climits>
#include <unordered_map>
#include <fmt/core.h>
#include <boost/algorithm/string.hpp>

int part1(std::vector<std::string> lines)
{
    // Game 1: 3 blue, 4 red; 1 red, 2 green, 6 blue; 2 green
    int res = 0, n = lines.size();
    for (int i = 0; i < n; i++)
    {
        std::vector<std::string> tokens;
        boost::split(tokens, lines[i], boost::is_any_of(":"));
        std::vector<std::string> games;
        boost::algorithm::trim_left(tokens[1]);
        // std::cout << tokens[1] << std::endl;
        boost::split(games, tokens[1], boost::is_any_of(";"));
        // std::unordered_map<std::string, int> m;
        bool is_valid_game = true;
        for (auto game : games)
        {
            // std::cout << game << std::endl;
            boost::algorithm::trim_left(game);
            std::vector<std::string> colors;
            boost::split(colors, game, boost::is_any_of(","));
            for (auto color : colors)
            {
                boost::algorithm::trim_left(color);
                std::vector<std::string> count_color;
                boost::split(count_color, color, boost::is_any_of(" "));
                int count = stoi(count_color[0]);
                std::string c = count_color[1];
                // m[c] += count;
                bool cond1 = c == "red" && count > 12;
                bool cond2 = c == "green" && count > 13;
                bool cond3 = c == "blue" && count > 14;
                if (cond1 || cond2 || cond3)
                {
                    is_valid_game = false;
                }
            }
        }

        // for (auto [color, count] : m)
        // {
        //     bool cond1 = color == "red" && count > 12;
        //     bool cond2 = color == "green" && count > 13;
        //     bool cond3 = color == "blue" && count > 14;
        //     if (cond1 || cond2 || cond3)
        //     {
        //         is_valid_game = false;
        //     }
        // }
        if (is_valid_game)
            res += i + 1;
    }
    // 2317
    return res;
}

int part2(std::vector<std::string> lines)
{
    // Game 1: 3 blue, 4 red; 1 red, 2 green, 6 blue; 2 green
    int res = 0, n = lines.size();
    for (int i = 0; i < n; i++)
    {
        std::vector<std::string> tokens;
        boost::split(tokens, lines[i], boost::is_any_of(":"));
        std::vector<std::string> games;
        boost::algorithm::trim_left(tokens[1]);
        // std::cout << tokens[1] << std::endl;
        boost::split(games, tokens[1], boost::is_any_of(";"));
        std::unordered_map<std::string, int> m(
            {{"red", -1},
             {"green", -1},
             {"blue", -1}});
        for (auto game : games)
        {
            boost::algorithm::trim_left(game);
            std::vector<std::string> colors;
            boost::split(colors, game, boost::is_any_of(","));
            for (auto color : colors)
            {
                boost::algorithm::trim_left(color);
                std::vector<std::string> count_color;
                boost::split(count_color, color, boost::is_any_of(" "));
                int count = stoi(count_color[0]);
                std::string c = count_color[1];
                m[c] = std::max(m[c], count);
            }
        }

        int num = 1;
        for (auto [color, count] : m)
        {
            if (count != INT_MAX)
                num *= count;
        }
        res += num;
    }
    return res;
}

int main()
{
    std::fstream file("input.txt");
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
    std::cout << part2(lines) << std::endl;

    return EXIT_SUCCESS;
}