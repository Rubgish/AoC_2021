#include "utils.hpp"

int main(int argc, char *argv[])
{
    auto input = read_input("day1_input");

    int previous_depth = 0;
    int increase_count = 0;
    for (auto &&x : input)
    {
        if (previous_depth == 0)
        {
            previous_depth = std::stoi(x);
        }
        else
        {
            if (std::stoi(x) > previous_depth)
            {
                increase_count++;
            }
            previous_depth = std::stoi(x);
        }
    }
    std::cout << increase_count << "\n";
}