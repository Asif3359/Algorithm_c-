#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e5 + 5;

vector<int> adj[MAX_N];
int parent[MAX_N];
int dist[MAX_N];

void bfs(int start, int n)
{
    queue<int> q;
    q.push(start);
    dist[start] = 0;
    parent[start] = -1;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int v : adj[u])
        {
            if (dist[v] == -1)
            {
                q.push(v);
                dist[v] = dist[u] + 1;
                parent[v] = u;
                if (v == n)
                    return;
            }
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    fill(dist, dist + n + 1, -1);
    fill(parent, parent + n + 1, -1);

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    bfs(1, n);

    if (dist[n] == -1)
    {
        cout << "IMPOSSIBLE" << endl;
    }
    else
    {
        vector<int> path;
        for (int v = n; v != -1; v = parent[v])
        {
            path.push_back(v);
        }
        reverse(path.begin(), path.end());

        cout << path.size() << endl;
        for (int v : path)
        {
            cout << v << " ";
        }
        cout << endl;
    }

    return 0;
}
