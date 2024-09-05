#include <bits/stdc++.h>
using namespace std;

char graph[1001][1001];
bool vis[1001][1001];

int n, m;

int dx[4] = {-1, 0, 1, 0}; // row er move
int dy[4] = {0, 1, 0, -1}; // col er move

bool valid(int x, int y)
{
    if (x >= 0 && x < n && y >= 0 && y < m && graph[x][y] == '.')
    {
        return true;
    }
    else
    {
        return false;
    }
}

int dfs(int si, int sj)
{
    vis[si][sj] = true;
    int count = 1;

    for (int i = 0; i < 4; i++)
    {
        int ci = si + dx[i]; // children er row
        int cj = sj + dy[i]; // children er column

        if (valid(ci, cj) && !vis[ci][cj])
        {
            count += dfs(ci, cj);
        }
    }

    return count;
}

int main()
{
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> graph[i][j];
        }
    }

    memset(vis, false, sizeof(vis));

    vector<int> roomCounts;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (graph[i][j] == '.' && !vis[i][j])
            {
                int count = dfs(i, j);
                roomCounts.push_back(count);
            }
        }
    }

    if (roomCounts.empty())
    {
        cout << 0 << endl;
    }
    else
    {
        sort(roomCounts.begin(), roomCounts.end());

        for (int count : roomCounts)
        {
            cout << count << " ";
        }
        cout << endl;
    }

    return 0;
}