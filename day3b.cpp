#include "utils.hpp"

std::vector<std::string> recurse(std::vector<std::string> &input, int bit, int mode)
{
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

    // the value to keep
    char kv;

    // mode 0 == oxygen, keep highest.
    if (mode == 0)
    {
        if (ones[bit] >= zeros[bit])
        {
            kv = '1';
        }
        else
        {
            kv = '0';
        }
    }
    else
    {
        if (ones[bit] >= zeros[bit])
        {
            kv = '0';
        }
        else
        {
            kv = '1';
        }
    }

    std::vector<std::string> result{};
    for (auto &&x : input)
    {
        if (x[bit] == kv)
        {
            result.push_back(x);
        }
    }
    return result;
}

int main(int argc, char *argv[])
{
    auto input = read_input("day3_input");
    auto copy_o = input;
    auto copy_co2 = input;

    for (int i = 0; i < 12; i++)
    {
        copy_o = recurse(copy_o, i, 0);
        if (copy_o.size() == 1)
        {
            break;
        }
    }
    for (int i = 0; i < 12; i++)
    {
        copy_co2 = recurse(copy_co2, i, 1);
        if (copy_co2.size() == 1)
        {
            break;
        }
    }

    auto result = (std::stoi(copy_o[0], nullptr, 2)) * (std::stoi(copy_co2[0], nullptr, 2));
    std::cout << result << "\n";
}