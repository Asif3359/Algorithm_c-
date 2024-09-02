#include <bits/stdc++.h>
using namespace std;
vector<int> mat[1005];
bool vis[1005];

void bfs(int src)
{
    queue<int> qu;
    qu.push(src);
    vis[src] = true;

    while (!qu.empty())
    {
        int par = qu.front();
        qu.pop();
        cout << par << " ";
        // for (int i = 0; i < mat[par].size(); i++)
        // {
        //     int child = mat[par][i];
        //     cout << child << " ";
        // }
        for (int child : mat[par])
        {
            if (vis[child] == false)
            {
                qu.push(child);
                vis[child] = true;
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
    int src;
    cin >> src;
    memset(vis, false, sizeof(vis));
    bfs(src);
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