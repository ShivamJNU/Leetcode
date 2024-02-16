class Solution
{
public:
    int check_sector(int row, int column)
    {
        if (column >= 0 && column <= 2)
        {
            if (row >= 0 && row <= 2)
            {
                return 0;
            }

            if (row >= 3 && row <= 5)
            {
                return 3;
            }

            if (row >= 6 && row <= 8)
            {
                return 6;
            }
        }

        if (column >= 3 && column <= 5)
        {
            if (row >= 0 && row <= 2)
            {
                return 1;
            }

            if (row >= 3 && row <= 5)
            {
                return 4;
            }

            if (row >= 6 && row <= 8)
            {
                return 7;
            }
        }

        if (column >= 6 && column <= 8)
        {
            if (row >= 0 && row <= 2)
            {
                return 2;
            }

            if (row >= 3 && row <= 5)
            {
                return 5;
            }

            if (row >= 6 && row <= 8)
            {
                return 8;
            }
        }
        
        return INT_MAX;
    }

    vector<vector<int>> vec1; // To keep the count of each 3*3 maze

    vector<vector<int>> check_column;
    vector<vector<int>> check_row;

    vector<vector<char>> Final;

    void func(int row, int column, vector<vector<char>> &board)
    {
        if (row == 9)
        {
            Final = board;
            return;
        }

        // Fill the current row

        if (board[row][column] == '.')
        {
            for (int n = 1; n <= 9; n++)
            {
                int sect = check_sector(row, column);

                int num = (int)(n);

                if (vec1[sect][num - 1] == 0 && check_column[column][num - 1] == 0 && check_row[row][num - 1] == 0)
                {
                    vec1[sect][num - 1] = 1;
                    check_column[column][num - 1] = 1;
                    check_row[row][num - 1] = 1;

                    board[row][column] = (char)('0' + num);

                    if (column == 8)
                    {
                        func(row + 1, 0, board);
                    }
                    else
                    {
                        func(row, column + 1, board);
                    }

                    vec1[sect][num - 1] = 0;
                    check_column[column][num - 1] = 0;
                    check_row[row][num - 1] = 0;

                    board[row][column] = '.';
                }
            }
        }
        else
        {
            if (column == 8)
            {
                func(row + 1, 0, board);
            }
            else
            {
                func(row, column + 1, board);
            }
        }
    }

    void solveSudoku(vector<vector<char>> &board)
    {
        vector<int> Temp(9, 0);

        for (int i = 0; i < 9; i++)
        {
            vec1.push_back(Temp);
            check_column.push_back(Temp);
            check_row.push_back(Temp);
        }

        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] != '.')
                {
                    int num = (int)(board[i][j] - '0');

                    int sector = check_sector(i, j);
                    vec1[sector][num - 1] = 1;

                    check_column[j][num - 1] = 1;
                    check_row[i][num - 1] = 1;
                }
            }
        }

        func(0, 0, board);

        board = Final;
    }
};
