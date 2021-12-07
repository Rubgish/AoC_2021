#include "utils.hpp"

int main(int argc, char *argv[])
{
    auto input = read_ints("day7_input");
    int lowest_cost = 0;
    for (int i = 0; i < 1000; i++)
    {
        int fuel_cost = 0;
        for (auto &&x : input)
        {
            int dist = abs(x - i);
            fuel_cost += dist * (dist + 1) / 2;
        }
        if (lowest_cost == 0)
        {
            lowest_cost = fuel_cost;
        }
        if (fuel_cost < lowest_cost)
        {
            lowest_cost = fuel_cost;
        }
    }
    std::cout << lowest_cost << "\n";
}