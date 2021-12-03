#include "utils.hpp"

int main(int argc, char *argv[])
{
    auto input = read_input("day3_input");
    int ones[12]{0};
    int zeros[12]{0};

    for (auto &&x : input)
    {
        int pos = 0;
        for (auto &&y : x)
        {
            if (y == '1')
            {
                ones[pos] += 1;
            }
            else
            {
                zeros[pos] += 1;
            }
            pos++;
        }
    }

    std::string gamma = "";
    std::string epsilon = "";

    for (int i = 0; i < 12; i++)
    {
        if (ones[i] > zeros[i])
        {
            gamma.push_back('1');
            epsilon.push_back('0');
        }
        else
        {
            gamma.push_back('0');
            epsilon.push_back('1');
        }
    }
    auto result = (std::stoi(gamma, nullptr, 2)) * (std::stoi(epsilon, nullptr, 2));
    std::cout << result << "\n";
}