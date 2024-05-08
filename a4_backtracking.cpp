#include <bits/stdc++.h>
using namespace std;

void printSolution(vector<vector<int>> &board, int N)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            if (board[i][j] == 1)
                cout << "Q ";
            else
                cout << ". ";
        cout << endl;
    }
}
bool isSafe(vector<vector<int>> &board, int row, int col, int N)
{
    int i, j;
    for (i = col; i >= 0; i--)
        if (board[row][i])
            return false;

    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;
    for (i = row, j = col; j >= 0 && i < N; i++, j--)
        if (board[i][j])
            return false;

    return true;
}
int sol = 0;
void solve(vector<vector<int>> &board, int col, int N)
{
    if (col >= N)
    {
        sol++;
        cout << "Solution : " << sol << endl;
        printSolution(board, N);
        cout << endl;
        return;
    }

    // checking each row
    for (int i = 0; i < N; i++)
    {

        if (isSafe(board, i, col, N))
        {
            board[i][col] = 1;
            solve(board, col + 1, N);
            board[i][col] = 0;
        }
    }
}

bool solveNQ(int N)
{
    vector<vector<int>> board(N, vector<int>(N, 0));

    if (N == 2 || N == 3)
    {
        cout << "Solution does not exist";
        return false;
    }
    solve(board, 0, N);
    return true;
}

int main()
{
    int N;
    while (true)
    {
        cout << "\nN = ";
        cin >> N;
        sol = 0;
        solveNQ(N);
    }

    return 0;
}
