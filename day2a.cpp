#include "utils.hpp"

int main(int argc, char *argv[])
{
    auto input = read_input("day2_input");

    int horizontal = 0;
    int depth = 0;

    for (auto &&x : input)
    {
        if (x.rfind("up", 0) == 0)
        {
            depth -= std::stoi(x.substr(3));
        }
        else if (x.rfind("down", 0) == 0)
        {
            depth += std::stoi(x.substr(5));
        }
        else if (x.rfind("forward", 0) == 0)
        {
            horizontal += std::stoi(x.substr(8));
        }
    }
    std::cout << "depth: " << depth << "\n";
    std::cout << "horizontal: " << horizontal << "\n";
    std::cout << "answer: " << (depth * horizontal) << "\n";
}