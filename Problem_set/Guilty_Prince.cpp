#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> d = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

bool valid(int i, int j, char adj[35][35], int n, int m)
{
    return i >= 0 && i < n && j >= 0 && j < m && adj[i][j] != '#';
}

int dfs(int si, int sj, char adj[35][35], bool vis[35][35], int n, int m)
{
    if (!valid(si, sj, adj, n, m) || vis[si][sj])
        return 0;
    vis[si][sj] = true;
    int count = 1;

    for (int i = 0; i < 4; i++)
    {
        int ci = si + d[i].first;
        int cj = sj + d[i].second;
        count += dfs(ci, cj, adj, vis, n, m);
    }

    return count;
}

int main()
{
    int t;
    cin >> t;

    for (int tc = 1; tc <= t; tc++)
    {
        const int MAX_N = 35;
        char adj[MAX_N][MAX_N];
        bool vis[MAX_N][MAX_N];
        int n, m;
        cin >> m >> n;

        pair<int, int> src;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> adj[i][j];
                if (adj[i][j] == '@')
                {
                    src = {i, j};
                }
            }
        }

        memset(vis, false, sizeof(vis));

        int si = src.first;
        int sj = src.second;

        int count = dfs(si, sj, adj, vis, n, m);

        cout << "Case " << tc << ": " << count << endl;
    }

    return 0;
}