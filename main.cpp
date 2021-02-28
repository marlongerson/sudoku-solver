#include <vector>
#include <iostream>

class Solution
{
public:
    void solveSudoku(std::vector<std::vector<char>> &board)
    {
        int m = board.size();
        solveSudoku(board, 0, 0, m);
    }

    void print_board(const std::vector<std::vector<char>> &board)
    {
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board.size(); j++)
            {
                std::cout << board[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }

    bool solveSudoku(std::vector<std::vector<char>> &board, int row, int col, int m)
    {
        if (col == m)
        {
            col = 0;
            row++;
        }

        if (row == m)
        {
            // The puzzle is solved because we have looked at all cells.
            return true;
        }

        if (!requires_solution(board, row, col))
        {
            return solveSudoku(board, row, col + 1, m);
        }

        for (int n = 1; n <= m; n++)
        {
            if (is_possible(board, row, col, n, m))
            {
                board[row][col] = n + '0';
                if (solveSudoku(board, row, col + 1, m))
                {
                    return true;
                }
            }
        }

        board[row][col] = '.';
        return false;
    }

    bool is_possible(const std::vector<std::vector<char>> &board, int row, int col, int n, int m)
    {
        int z = std::sqrt(m);

        for (int c = 0; c < m; c++)
        {
            if (board[row][c] == n + '0')
            {
                return false;
            }
        }

        for (int r = 0; r < m; r++)
        {
            if (board[r][col] == n + '0')
            {
                return false;
            }
        }

        for (int r = 0; r < z; r++)
        {
            for (int c = 0; c < z; c++)
            {
                if (board[r + row - row % z][c + col - col % z] == n + '0')
                {
                    return false;
                }
            }
        }
        return true;
    }

    bool requires_solution(const std::vector<std::vector<char>> &board, int row, int col)
    {
        return board[row][col] == '.';
    }
};

int main()
{
    std::vector<std::vector<char>> board;
    board.push_back({'5', '3', '.', '.', '7', '.', '.', '.', '.'});
    board.push_back({'6', '.', '.', '1', '9', '5', '.', '.', '.'});
    board.push_back({'.', '9', '8', '.', '.', '.', '.', '6', '.'});
    board.push_back({'8', '.', '.', '.', '6', '.', '.', '.', '3'});
    board.push_back({'4', '.', '.', '8', '.', '3', '.', '.', '1'});
    board.push_back({'7', '.', '.', '.', '2', '.', '.', '.', '6'});
    board.push_back({'.', '6', '.', '.', '.', '.', '2', '8', '.'});
    board.push_back({'.', '.', '.', '4', '1', '9', '.', '.', '5'});
    board.push_back({'.', '.', '.', '.', '8', '.', '.', '7', '9'});

    Solution solution;
    solution.solveSudoku(board);
    solution.print_board(board);
}
