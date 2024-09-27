#include <bits/stdc++.h>
using namespace std;

char graph[1005][1005];
bool vis[1005][1005];
long long int level[1005][1005];

long long int n, m;

long long int dx[4] = {-1, 0, 1, 0};
long long int dy[4] = {0, 1, 0, -1};

bool valid(long long int x, long long int y)
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

long long int bfs(long long int si, long long int sj)
{

    queue<pair<long long int, long long int>> q;
    q.push({si, sj});
    vis[si][sj] = true;
    long long int area = 1;

    while (!q.empty())
    {

        pair<long long int, long long int> node = q.front();
        q.pop();
        long long int nrow = node.first;
        long long int ncol = node.second;

        for (long long int i = 0; i < 4; i++)
        {

            long long int ci = nrow + dx[i];
            long long int cj = ncol + dy[i];

            if (valid(ci, cj) && vis[ci][cj] == false)
            {
                vis[ci][cj] = true;
                q.push({ci, cj});
                area++;
            }
        }
    }

    return area;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for (long long int i = 0; i < n; i++)
    {
        for (long long int j = 0; j < m; j++)
        {
            cin >> graph[i][j];
        }
    }

    long long int cnt = 0;
    bool isExist = false;
    priority_queue<long long int, vector<long long int>, greater<long long int>> comp;

    for (long long int i = 0; i < n; i++)
    {
        for (long long int j = 0; j < m; j++)
        {

            if (graph[i][j] == '.' && vis[i][j] == false)
            {
                long long int area = bfs(i, j);
                comp.push(area);
                isExist = true;
                cnt++;
            }
        }
    }

    if (isExist)
    {
        cout << comp.top() << endl;
    }
    else
    {
        cout << -1 << endl;
    }
}