#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum = sum + a[i];
    }
    bool dp[n + 1][sum + 1];

    dp[0][0] = true;

    for (int i = 1; i <= sum; i++)
    {
        dp[0][i] = false;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            if (a[i - 1] <= j)
            {
                dp[i][j] = dp[i - 1][j - a[i - 1]] || dp[i - 1][j];
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    vector<int> arr;
    for (int j = 0; j <= sum; j++)
    {
        if (dp[n][j]) // Check only the last row of dp (i.e., dp[n][j])
        {
            arr.push_back(j); // Collect the valid subset sum
        }
    }

    int ans = INT_MAX;
    for (int x : arr)
    {
        int s1 = x;
        int s2 = sum - s1;

        ans = min(ans, abs(s1 - s2));
    }

    cout << ans << endl;

    return 0;
}