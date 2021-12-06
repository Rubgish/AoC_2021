#include "utils.hpp"

int main(int argc, char *argv[])
{
    auto input = read_input("day6_input");
    std::vector<uint64_t> fish{};
    std::map<uint64_t, uint64_t> fish_map{};
    for (auto &&x : input)
    {
        fish.push_back(std::stoi(x));
    }
    for (auto &&x : fish)
    {
        if (fish_map.find(x) == fish_map.end())
        {
            fish_map.insert(std::make_pair(x, 1));
        }
        else
        {
            auto y = fish_map.find(x);
            y->second += 1;
        }
    }

    for (uint64_t i = 0; i < 256; i++)
    {
        uint64_t new_fish = 0;
        std::map<uint64_t, uint64_t> temp_map{};
        for (auto &&x : fish_map)
        {
            if (x.first == 0)
            {
                uint64_t new_value = 0;
                if (fish_map.find(7) != fish_map.end())
                {
                    new_value = fish_map.find(7)->second + x.second;
                }
                else
                {
                    new_value = x.second;
                }
                temp_map.insert(std::make_pair(6, new_value));
                new_fish = x.second;
            }
            else
            {
                temp_map.insert(std::make_pair(x.first - 1, x.second));
            }
        }
        if (new_fish != 0)
        {
            temp_map.insert(std::make_pair(8, new_fish));
        }
        fish_map = temp_map;
    }
    uint64_t total_fish = 0;
    for (auto &&x : fish_map)
    {
        total_fish += x.second;
    }
    std::cout << total_fish << "\n";
}