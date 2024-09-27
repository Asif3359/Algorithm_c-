#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1005;
char adj[MAX_N][MAX_N];
bool vis[MAX_N][MAX_N];
int dist[MAX_N][MAX_N];
int n, m;
pair<int, int> par[MAX_N][MAX_N];

vector<pair<int, int>> d = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

bool valid(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m || adj[i][j] == '#')
        return false;
    return true;
}

void bfs(int si, int sj)
{
    queue<pair<int, int>> q;
    q.push({si, sj});
    vis[si][sj] = true;
    dist[si][sj] = 0;
    par[si][sj] = {-1, -1};

    while (!q.empty())
    {
        pair<int, int> p = q.front();
        int a = p.first;
        int b = p.second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int ci = a + d[i].first;
            int cj = b + d[i].second;

            if (valid(ci, cj) && !vis[ci][cj])
            {
                q.push({ci, cj});
                vis[ci][cj] = true;
                dist[ci][cj] = dist[a][b] + 1;
                par[ci][cj] = {a, b};
            }
        }
    }
}

int main()
{
    cin >> n >> m;

    pair<int, int> src;
    pair<int, int> des;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> adj[i][j];
            if (adj[i][j] == 'R')
            {
                src = {i, j};
            }
            if (adj[i][j] == 'D')
            {
                des = {i, j};
            }
        }
    }

    memset(vis, false, sizeof(vis));
    memset(dist, -1, sizeof(dist));

    int si = src.first;
    int sj = src.second;

    bfs(si, sj);

    int di = des.first;
    int dj = des.second;

    if (vis[di][dj])
    {
        while (di != si || dj != sj)
        {
            if (adj[di][dj] == '.')
            {
                adj[di][dj] = 'X';
            }
            int ti = di;
            int tj = dj;
            di = par[ti][tj].first;
            dj = par[ti][tj].second;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << adj[i][j];
        }
        cout << endl;
    }

    return 0;
}