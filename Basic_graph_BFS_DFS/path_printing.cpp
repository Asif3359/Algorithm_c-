#include <bits/stdc++.h>
using namespace std;
vector<int> mat[1005];
bool vis[1005];
int level[1005];
int parent[1005];

void bfs(int src)
{
    queue<int> qu;
    qu.push(src);
    vis[src] = true;
    level[src] = 0;

    while (!qu.empty())
    {
        int par = qu.front();
        qu.pop();
        for (int child : mat[par])
        {
            if (vis[child] == false)
            {
                qu.push(child);
                vis[child] = true;
                level[child] = level[par] + 1;
                parent[child] = parent[par] + 1;
            }
        }
    }
}

int main()
{
    int n, e;
    cin >> n >> e;

    while (e--)
    {
        int a, b;
        cin >> a >> b;
        mat[a].push_back(b);
        mat[b].push_back(a);
    }
    int src, des;
    cin >> src >> des;
    memset(vis, false, sizeof(vis));
    memset(level, -1, sizeof(level));
    memset(parent, -1, sizeof(parent));

    bfs(src);

    int x = des;
    vector<int> path;
    while (x != -1)
    {
        path.push_back(x);
        x = parent[x];
    }

    sort(path.begin(), path.end());

    for (int x : path)
    {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}

/*
input:
5 6
0 1
1 2
0 4
1 3
2 0
3 4
0
*/