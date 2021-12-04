#include "utils.hpp"

class Board
{
private:
    std::vector<int> data{};
    void add_value(int val_to_add);
    std::vector<bool> data_truth{};

public:
    void add_line(std::string line);
    bool game_won();
    void add_match(int matched_val);
    int game_total();
    Board();
};

Board::Board()
{
    for (int i = 0; i < 25; i++)
    {
        data_truth.push_back(false);
    }
}

int Board::game_total()
{
    int retval = 0;
    for (int i = 0; i < 25; i++)
    {
        if (!data_truth[i])
        {
            retval += data[i];
        }
    }
    std::cout << retval << "\n";
    return retval;
}

void Board::add_value(int val_to_add)
{
    data.push_back(val_to_add);
}

void Board::add_line(std::string line)
{
    std::vector<std::string> line_nums{};
    std::istringstream iss(line);
    copy(std::istream_iterator<std::string>(iss),
         std::istream_iterator<std::string>(),
         std::back_inserter(line_nums));
    for (auto &&x : line_nums)
    {
        add_value(std::stoi(x));
    }
}

void Board::add_match(int matched_val)
{
    for (int i = 0; i < data.size(); i++)
    {
        if (data[i] == matched_val)
        {
            data_truth[i] = true;
            break;
        }
    }
}

bool Board::game_won()
{
    for (int j = 0; j < 5; j++)
    {
        auto i = 5 * j;
        if (data_truth[i] && data_truth[i + 1] && data_truth[i + 2] && data_truth[i + 3] && data_truth[i + 4])
        {
            std::cout << "game won leftright\n";
            return true;
        }
        if (data_truth[j] && data_truth[j + 5] && data_truth[j + 10] && data_truth[j + 15] && data_truth[j + 20])
        {

            std::cout << "game won updown\n";
            return true;
        }
    }
    return false;
}

int main(int argc, char *argv[])
{
    auto input = read_input("day4_input");
    bool got_numbers = false;
    std::vector<std::string> number_list{};
    std::vector<Board> board_list{};

    for (auto &&x : input)
    {
        if (!got_numbers)
        {
            std::istringstream iss(x);
            copy(std::istream_iterator<std::string>(iss),
                 std::istream_iterator<std::string>(),
                 std::back_inserter(number_list));
            got_numbers = true;
            continue;
        }

        if (x.empty())
        {
            // Blank line, create a new Board and go to the next line.
            board_list.push_back(Board());
            continue;
        }
        else
        {
            board_list.back().add_line(x);
        }
    }
    // We have all our boards and our numbers, now play the game.
    int board_value = 0;
    int winning_number = 0;
    bool result = false;

    for (auto &&x : number_list)
    {
        auto num = std::stoi(x);
        for (auto &&y : board_list)
        {
            y.add_match(num);
            result = y.game_won();
            if (result)
            {
                board_value = y.game_total();
                break;
            }
        }
        if (result)
        {
            winning_number = num;
            break;
        }
    }
    std::cout << winning_number << "\n";
    std::cout << board_value << "\n";
    std::cout << winning_number * board_value << "\n";
}