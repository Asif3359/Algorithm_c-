#include <bits/stdc++.h>
using namespace std;

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
        mat[b].push_back(a);
    }
    int q;
    cin >> q;

    while (q--)
    {
        int a;
        cin >> a;
        sort(mat[a].rbegin(), mat[a].rend());
        if (!mat[a].empty())
        {
            for (int x : mat[a])
            {
                cout << x << " ";
            }
        }
        else
        {
            cout << -1 << " ";
        }
        cout << endl;
    }

    return 0;
}