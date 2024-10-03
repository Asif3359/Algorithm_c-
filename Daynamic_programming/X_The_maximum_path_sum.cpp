#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

const int MAX = 105;
int A[MAX][MAX];

int maxPathSum(int i, int j, int N, int M)
{
    if (i >= N || j >= M)
    {
        return INT_MIN;
    }
    if (i == N - 1 && j == M - 1)
    {
        return A[i][j];
    }
    int down = maxPathSum(i + 1, j, N, M);
    int right = maxPathSum(i, j + 1, N, M);
    return A[i][j] + max(down, right);
}

int main()
{
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            cin >> A[i][j];
        }
    }
    cout << maxPathSum(0, 0, N, M) << endl;
    return 0;
}