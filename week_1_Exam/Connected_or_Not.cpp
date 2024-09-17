#include <bits/stdc++.h>
using namespace std;

bool is_connected(vector<int> *mat, int a, int b)
{
    for (int x : mat[a])
    {
        if (x == b)
        {
            return true;
        }
    }
    if (a == b)
    {
        return true;
    }
    return false;
}

int main()
{
    int n, e;
    cin >> n >> e;
    vector<int> mat[n];

    while (e--)
    {
        int a, b;
        cin >> a >> b;
        mat[a].push_back(b);
    }

    int q;
    cin >> q;

    while (q--)
    {
        int a, b;
        cin >> a >> b;
        if (is_connected(mat, a, b))
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }

    return 0;
}