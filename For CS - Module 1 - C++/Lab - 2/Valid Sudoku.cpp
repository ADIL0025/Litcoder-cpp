#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

bool isValidRow(const vector<vector<int>> &board, int row)
{
    unordered_set<int> seen;
    for (int num : board[row])
    {
        if (num != 0 && !seen.insert(num).second)
        {
            return false;
        }
    }

    return true;
}

bool isValidColumn(const vector<vector<int>> &board, int col)
{
    unordered_set<int> seen;
    for (int i = 0; i < board.size(); i++)
    {
        int num = board[i][col];
        if (num != 0 && !seen.insert(num).second)
        {
            return false;
        }
    }

    return true;
}

bool isValidSubBox(const vector<vector<int>> &board, int startRow, int startCol)
{
    unordered_set<int> seen;
    for (int i = startRow; i < startRow + 3; i++)
    {
        for (int j = startCol; j < startCol + 3; j++)
        {
            int num = board[i][j];
            if (num != 0 && !seen.insert(num).second)
            {
                return false;
            }
        }
    }

    return true;
}

bool validateSudoku(const vector<vector<int>> &board)
{
    for (int i = 0; i < board.size(); i++)
    {
        if (!isValidRow(board, i) || !isValidColumn(board, i) || !isValidSubBox(board, i / 3 * 3, i % 3 * 3))
        {
            return false;
        }
    }

    return true;
}

vector<vector<int>> parseInputBoard(const string &inputBoard, int size)
{
    vector<vector<int>> board(size, vector<int>(size, 0));
    int index = 0;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            char cellChar = inputBoard[index++];
            if (cellChar != '.')
            {
                board[i][j] = cellChar - '0';
            }
        }
    }

    return board;
}

int main()
{
    int size;
    cin >> size;
    cin.ignore();
    string inputBoard = "";
    for (int i = 0; i < size; i++)
    {
        string line;
        getline(cin, line);
        inputBoard += line;
    }

    vector<vector<int>> board = parseInputBoard(inputBoard, size);

    cout << (validateSudoku(board) ? "YES" : "NO") << endl;

    return 0;
}
