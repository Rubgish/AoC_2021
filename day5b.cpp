#include "utils.hpp"

std::pair<int, int> get_coords(std::string input_coords)
{
    std::vector<std::string> coords_str_list;
    std::stringstream ss(input_coords);

    while (ss.good())
    {
        std::string sub;
        getline(ss, sub, ',');
        coords_str_list.push_back(sub);
    }

    return std::make_pair(std::stoi(coords_str_list[0]), std::stoi(coords_str_list[1]));
}

void draw_diagonal_line(std::pair<int, int> a, std::pair<int, int> b, int (*coords)[1000])
{
    if ((a.first > b.first) && (a.second > b.second))
    {
        for (int i = b.second; i <= a.second; i++)
        {
            coords[b.first + i - b.second][i] += 1;
        }
    }
    else if ((a.first > b.first) && (a.second < b.second))
    {
        for (int i = a.second; i <= b.second; i++)
        {
            coords[a.first - i + a.second][i] += 1;
        }
    }
    else if ((a.first < b.first) && (a.second > b.second))
    {
        for (int i = b.second; i <= a.second; i++)
        {
            coords[b.first - i + b.second][i] += 1;
        }
    }
    else
    {
        for (int i = a.second; i <= b.second; i++)
        {
            coords[a.first + i - a.second][i] += 1;
        }
    }
};

void draw_straight_line(std::pair<int, int> a, std::pair<int, int> b, int (*coords)[1000])
{
    if (a.first == b.first)
    {
        if (a.second > b.second)
        {
            for (int i = b.second; i <= a.second; i++)
            {
                coords[a.first][i] += 1;
            }
        }
        else
        {
            for (int i = a.second; i <= b.second; i++)
            {
                coords[a.first][i] += 1;
            }
        }
    }
    else
    {
        if (a.first > b.first)
        {
            for (int i = b.first; i <= a.first; i++)
            {
                coords[i][a.second] += 1;
            }
        }
        else
        {
            for (int i = a.first; i <= b.first; i++)
            {
                coords[i][a.second] += 1;
            }
        }
    }
};

bool straight_line_check(std::pair<int, int> a, std::pair<int, int> b)
{
    if (a.first == b.first || a.second == b.second)
    {
        return true;
    }
    return false;
};

int main(int argc, char *argv[])
{
    auto input = read_input("day5_input");
    int coords[1000][1000] = {0};

    for (auto &&x : input)
    {
        auto dash = x.find(" -> ");
        auto start = x.substr(0, dash);
        auto end = x.substr(dash + 4);

        auto start_c = get_coords(start);
        auto end_c = get_coords(end);

        if (straight_line_check(start_c, end_c))
        {
            draw_straight_line(start_c, end_c, coords);
        }
        else
        {
            draw_diagonal_line(start_c, end_c, coords);
        }
    }

    int overlap_count = 0;
    for (int i = 0; i < 1000; i++)
    {
        for (int j = 0; j < 1000; j++)
        {
            if (coords[i][j] >= 2)
            {
                overlap_count += 1;
            }
        }
    }
    std::cout << overlap_count << "\n";
}