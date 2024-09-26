#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 35;
char adj[MAX_N][MAX_N];
bool vis[MAX_N][MAX_N];
int dist[MAX_N][MAX_N];
int n;

vector<pair<int, int>> d = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

bool valid(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= n || adj[i][j] == 'T')
        return false;
    return true;
}

void bfs(int si, int sj)
{
    queue<pair<int, int>> q;
    q.push({si, sj});
    vis[si][sj] = true;
    dist[si][sj] = 0;

    while (!q.empty())
    {
        pair<int, int> par = q.front();
        int a = par.first;
        int b = par.second;
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
            }
        }
    }
}

int main()
{
    cin >> n;

    pair<int, int> src;
    pair<int, int> des;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> adj[i][j];
            if (adj[i][j] == 'S')
            {
                src = {i, j};
            }
            if (adj[i][j] == 'E')
            {
                des = {i, j};
            }
        }
    }

    memset(vis, false, sizeof(vis));
    memset(dist, -1, sizeof(dist));

    int si = src.first;
    int sj = src.second;

    int di = des.first;
    int dj = des.second;

    bfs(si, sj);

    cout << dist[di][dj] << endl;

    return 0;
}
