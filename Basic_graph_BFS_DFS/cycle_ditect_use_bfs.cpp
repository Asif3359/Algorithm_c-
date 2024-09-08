#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
bool vis[N];
vector<int> adj[N];
int parentArray[N];

bool isCycle = false;

void bfs(int s)
{
    queue<int> q;
    q.push(s);
    vis[s] = true;

    while (!q.empty())
    {
        int parent = q.front();
        q.pop();
        for (int child : adj[parent])
        {
            if (vis[child] && parentArray[parent] != child)
            {
                isCycle = true;
            }
            if (!vis[child])
            {
                parentArray[child] = parent;
                vis[child] = true;
                q.push(child);
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
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    memset(vis, false, sizeof(vis));
    memset(parentArray, -1, sizeof(parentArray));
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            bfs(i);
        }
    }

    if (isCycle)
    {
        cout << "Cycle exist\n";
    }
    else
    {
        cout << "Cycle not exist\n";
    }

    return 0;
}