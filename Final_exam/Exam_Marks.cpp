#include <bits/stdc++.h>
using namespace std;

int dp[1001][1001];

bool Target_sum(vector<int> &A, int n, int target)
{
    if (target == 0)
    {
        return true;
    }
    if (n == 0 || target < 0)
    {
        return false;
    }

    if (dp[n][target] != -1)
    {
        return dp[n][target];
    }

    bool op1 = Target_sum(A, n - 1, target);
    bool op2 = false;

    if (target >= A[n - 1])
    {
        op2 = Target_sum(A, n - 1, target - A[n - 1]);
    }

    return dp[n][target] = (op1 || op2);
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int N, M;
        cin >> N >> M;
        vector<int> A(N);
        for (int i = 0; i < N; i++)
        {
            cin >> A[i];
        }

        int target = 1000 - M;

        memset(dp, -1, sizeof(dp));

        if (M <= 1000 && Target_sum(A, N, target))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}
