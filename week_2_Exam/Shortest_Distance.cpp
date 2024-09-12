#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define INF 1e18
const int MAXN = 1000;

int main()
{
    ll n, e;
    cin >> n >> e;

    ll adj[MAXN][MAXN];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                adj[i][j] = 0;
            }
            else
            {
                adj[i][j] = INF;
            }
        }
    }

    for (int i = 0; i < e; i++)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        adj[a][b] = min(adj[a][b], c);
    }

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (adj[i][k] < INF && adj[k][j] < INF)
                {
                    adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
                }
            }
        }
    }

    ll t;
    cin >> t;

    while (t--)
    {
        ll s, d;
        cin >> s >> d;
        s--;
        d--;

        if (adj[s][d] == INF)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << adj[s][d] << endl;
        }
    }

    return 0;
}
