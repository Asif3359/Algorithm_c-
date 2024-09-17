#include <bits/stdc++.h>
using namespace std;

int n, m;
char a[1001][1001];
bool vis[1001][1001];

vector<pair<int, int>> d = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

bool valid(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
    {
        return false;
    }
    if (a[i][j] == '#')
    {
        return false;
    }
    if (vis[i][j])
    {
        return false;
    }
    return true;
}

void dfs(int si, int sj)
{
    vis[si][sj] = true;

    for (int i = 0; i < 4; i++)
    {
        int ci = si + d[i].first;
        int cj = sj + d[i].second;

        if (valid(ci, cj))
        {
            dfs(ci, cj);
        }
    }
}

int main()
{
    cin >> n >> m;

    pair<int, int> roomA, roomB;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
            if (a[i][j] == 'A')
            {
                roomA = {i, j};
            }
            else if (a[i][j] == 'B')
            {
                roomB = {i, j};
            }
        }
    }

    memset(vis, false, sizeof(vis));
    dfs(roomA.first, roomA.second);

    if (vis[roomB.first][roomB.second])
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }

    return 0;
}