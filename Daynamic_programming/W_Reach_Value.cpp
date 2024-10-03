#include <bits/stdc++.h>
using namespace std;



bool ReachNumber(long long int cur, long long int n)
{
    if (cur == n)
    {
        return true;
    }

    if (cur > n)
    {
        return false;
    }
    return ReachNumber(cur * 10, n) || ReachNumber(cur * 20, n);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long int n;
        cin >> n;

        bool isTrue = ReachNumber(1, n);

        if (isTrue)
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