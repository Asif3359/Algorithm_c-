#include <bits/stdc++.h>
using namespace std;

int dp[1005][1005];

bool subsetSum(int n, int arr[], int sum)
{
    if (n == 0)
    {
        if (sum == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    if (dp[n][sum] != -1)
    {
        return dp[n][sum];
    }

    if (arr[n - 1] <= sum)
    {
        bool op1 = subsetSum(n - 1, arr, sum - arr[n - 1]);
        bool op2 = subsetSum(n - 1, arr, sum);

        return dp[n][sum] = op1 || op2;
    }
    else
    {
        return dp[n][sum] = subsetSum(n - 1, arr, sum);
    }
}

int main()
{
    int n;
    cin >> n;

    int a[n];

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int sum;
    cin >> sum;

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            dp[i][j] = -1;
        }
    }

    if (subsetSum(n, a, sum))
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }

    return 0;
}