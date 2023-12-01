// https://adventofcode.com/2022/day/5

#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <fstream>
#include <boost/algorithm/string.hpp>

// int part1(std::vector<std::stack<char>> stacks, std::vector<std::string> &lines)
// {
//     return 1;
// }

int main(int argc, char *argv[])
{

    // input remains the same, so skip 10 lines
    // need to parse the inputw
    // find the row
    std::vector<std::stack<char>> stacks = {
        std::stack<char>({'G', 'T', 'R', 'W'}),
        std::stack<char>({'G', 'C', 'H', 'P', 'M', 'S', 'V', 'W'}),
        std::stack<char>({'C', 'L', 'T', 'S', 'G', 'M'}),
        std::stack<char>({'J', 'H', 'D', 'M', 'W', 'R', 'F'}),
        std::stack<char>({'P', 'Q', 'L', 'H', 'S', 'W', 'F', 'J'}),
        std::stack<char>({'P', 'J', 'D', 'N', 'F', 'M', 'S'}),
        std::stack<char>({'Z', 'B', 'D', 'F', 'G', 'C', 'S', 'J'}),
        std::stack<char>({'R', 'T', 'B'}),
        std::stack<char>({'H', 'N', 'W', 'L', 'C'})};

    for (auto s : stacks)
    {
        std::cout << s.size() << std::endl;
    }
    std::vector<char> lines;
    if (argc == 2)
    {
        std::fstream file(argv[1]);
        if (!file)
        {
            std::cerr << "Cannot open file!" << std::endl;
            return EXIT_FAILURE;
        }

        // skip the first 9 lines
        std::string line;
        for (int i = 0; i < 10; ++i)
        {
            std::getline(file, line);
        }

        while (std::getline(file, line))
        {
            std::vector<std::string> tokens;
            boost::split(tokens, line, boost::is_any_of(" "));
            int num_move = stoi(tokens[1]);
            int stack1_index = stoi(tokens[3]) - 1;
            int stack2_index = stoi(tokens[5]) - 1;
            // std::cout << num_move << " " << stack1_index << " " << stack2_index << std::endl;
            std::stack<char> &s1 = stacks[stack1_index];
            std::stack<char> &s2 = stacks[stack2_index];

            while (num_move > 0 && !s1.empty())
            {
                char c = s1.top();
                s1.pop();
                s2.push(c);
                num_move--;
            }
        }

        for (auto s : stacks)
        {
            if (!s.empty())
                std::cout << s.top() << std::endl;
        }
    }

    return EXIT_SUCCESS;
}