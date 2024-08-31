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

    for (int i = 0; i < n; i++)
    {
        cout << i << " - ";
        for (int x : mat[i])
        {
            cout << x << " ";
        }
        cout << endl;
    }
    cout << endl;

    return 0;
}
/**
 * 
input : 
6 6
0 1
1 5
0 4
0 3
3 4
2 4
output:
0 - 1 4 3
1 - 0 5
2 - 4
3 - 0 4
4 - 0 3 2
5 - 1
 */