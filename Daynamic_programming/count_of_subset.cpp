#include <bits/stdc++.h>
using namespace std;

int dp[1005][1005];

int subsetSum_count(int n, int arr[], int sum)
{
    if (n == 0)
    {
        if (sum == 0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    if (dp[n][sum] != -1)
    {
        return dp[n][sum];
    }

    if (arr[n - 1] <= sum)
    {
        int op1 = subsetSum_count(n - 1, arr, sum - arr[n - 1]);
        int op2 = subsetSum_count(n - 1, arr, sum);

        return dp[n][sum] = op1 + op2;
    }
    else
    {
        return dp[n][sum] = subsetSum_count(n - 1, arr, sum);
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

    // if (subsetSum_count(n, a, sum))
    // {
    //     cout << "YES\n";
    // }
    // else
    // {
    //     cout << "NO\n";
    // }

    cout << subsetSum_count(n, a, sum) << "\n";

    return 0;
}