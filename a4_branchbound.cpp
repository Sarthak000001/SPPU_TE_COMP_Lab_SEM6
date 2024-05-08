#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;

void printSol(const vector<int> &board)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (j == board[i])
            {
                cout << "Q ";
            }
            else
            {
                cout << ". ";
            }
        }
        cout << endl;
    }
}

bool isSafe(int row, int col, const vector<int> &board, const vector<bool> &rowCheck,
            const vector<bool> &upperDiagonal, const vector<bool> &lowerDiagonal)
{
    return !rowCheck[row] && !upperDiagonal[row + col] && !lowerDiagonal[N - 1 + col - row];
}

void solve(vector<int> &board, int col, vector<bool> &rowCheck,
           vector<bool> &upperDiagonal, vector<bool> &lowerDiagonal, int &solutions)
{
    if (col == N)
    {
        solutions++;
        cout << "Solution " << solutions << ":\n";
        printSol(board);
        cout << endl;
        return;
    }

    for (int row = 0; row < N; row++)
    {
        if (isSafe(row, col, board, rowCheck, upperDiagonal, lowerDiagonal))
        {
            board[col] = row;
            rowCheck[row] = true;
            upperDiagonal[row + col] = true;
            lowerDiagonal[N - 1 + col - row] = true;

            solve(board, col + 1, rowCheck, upperDiagonal, lowerDiagonal, solutions);

            board[col] = -1;
            rowCheck[row] = false;
            upperDiagonal[row + col] = false;
            lowerDiagonal[N - 1 + col - row] = false;
        }
    }
}

void nQueens()
{
    cout << "Enter the number of queens (N): ";
    cin >> N;

    vector<int> board(N, -1);
    vector<bool> rowCheck(N, false);
    vector<bool> upperDiagonal(2 * N - 1, false);
    vector<bool> lowerDiagonal(2 * N - 1, false);

    int solutions = 0;

    solve(board, 0, rowCheck, upperDiagonal, lowerDiagonal, solutions);

    if (solutions == 0)
    {
        cout << "No solution exists.\n";
    }
}

int main()
{
    nQueens();
    return 0;
}
