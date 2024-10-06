#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 100001;

int main()
{
    int t;
    cin >> t;

    bool dp[MAX_N];
    memset(dp, false, sizeof(dp));

    dp[1] = true;
    for (int i = 1; i < MAX_N; i++)
    {
        if (dp[i])
        {
            if (i + 3 < MAX_N)
            {
                dp[i + 3] = true;
            }
            if (2 * i < MAX_N)
            {
                dp[2 * i] = true;
            }
        }
    }

    while (t--)
    {
        int n;
        cin >> n;

        if (dp[n])
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
