// https://adventofcode.com/2023/day/3

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
    /*
    when we iterate through a line, we can encounter 3 things
    num, ., or symbol
    have a is_part_number flag = false
    if num add to our running sum,
    check neighbors for symbol and set flag = true if found
    when checking neighbors, ensure neighbors are within bounds
    if nondigit set flag to false and running sum to 0
    */
    int directions[8][2] = {
        {-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
    int n = lines.size(), m = lines[0].size(), res = 0, running_sum = 0;
    bool is_part_number = false;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char c = lines[i][j];
            if (std::isdigit(c))
            {
                running_sum = running_sum * 10 + (c - '0');
                // fmt::print("running_sum: {}\n", running_sum);
                for (int k = 0; k < 8 && !is_part_number; k++)
                {
                    int ii = i + directions[k][0];
                    int jj = j + directions[k][1];

                    if (ii >= 0 && ii < n && jj >= 0 && jj < m)
                    {
                        char n_c = lines[ii][jj];
                        bool is_symbol = !std::isdigit(n_c) && n_c != '.';
                        if (is_symbol)
                        {
                            is_part_number = true;
                        }
                    }
                }
            }
            else
            {
                if (is_part_number)
                {
                    res += running_sum;
                }
                running_sum = 0;
                is_part_number = false;
            }
        }
        running_sum = 0;
        is_part_number = false;
    }
    return res;
}

int part2(std::vector<std::string> lines)
{
    /*
    when we iterate through a line, we can encounter 3 things
    num, a gear, or some other symbol (ignore)
    have a is_part_number flag = false

    check neighbors for gear and set flag = true if found
    when checking neighbors, ensure neighbors are within bounds
    if nondigit set flag to false
    */
    int directions[8][2] = {
        {-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
    int n = lines.size(), m = lines[0].size(), res = 0, num = 0;
    std::string gear_id = "";
    std::unordered_map<std::string, std::vector<int>> map;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char c = lines[i][j];
            if (std::isdigit(c))
            {
                num = num * 10 + (c - '0');
                for (int k = 0; k < 8 && gear_id.empty(); k++)
                {
                    int ii = i + directions[k][0];
                    int jj = j + directions[k][1];
                    if (ii >= 0 && ii < n && jj >= 0 && jj < m)
                    {
                        char n_c = lines[ii][jj];
                        bool is_gear = n_c == '*';
                        if (is_gear)
                        {
                            gear_id = std::to_string(ii) + "," + std::to_string(jj);
                        }
                    }
                }
            }
            else
            {
                // fmt::print("gear_id: {}\n", gear_id);
                if (!gear_id.empty())
                    map[gear_id].push_back(num);
                num = 0;
                gear_id = "";
            }
        }
        if (!gear_id.empty())
            map[gear_id].push_back(num);
        num = 0;
        gear_id = "";
    }

    for (auto [gear_id, v] : map)
    {
        if (v.size() == 2)
            res += v[0] * v[1];
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