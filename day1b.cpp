#include "utils.hpp"

int main(int argc, char *argv[])
{
    auto input = read_input("day1_input");

    int increase_count = 0;
    std::vector<int> v_a;

    for (auto &&x : input)
    {
        v_a.push_back(std::stoi(x));
    }
    for (int i = 0; i < 1997; i++)
    {
        int val_a = v_a[i] + v_a[i + 1] + v_a[i + 2];
        int val_b = v_a[i + 1] + v_a[i + 2] + v_a[i + 3];
        if (val_b > val_a)
        {
            increase_count++;
        }
    }
    std::cout << increase_count << "\n";
}