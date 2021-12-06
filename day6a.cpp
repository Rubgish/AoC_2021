#include "utils.hpp"

int main(int argc, char *argv[])
{
    auto input = read_input("day6_input");
    std::vector<int> fish{};
    for (auto &&x : input)
    {
        fish.push_back(std::stoi(x));
    }

    for (int i = 0; i < 80; i++)
    {
        int new_fish = 0;
        for (auto &&x : fish)
        {
            x = x - 1;
            if (x < 0)
            {
                x = 6;
                new_fish += 1;
            }
        }
        for (int j = 0; j < new_fish; j++)
        {
            fish.push_back(8);
        }
    }
    std::cout << fish.size() << "\n";
}