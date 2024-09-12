#include <bits/stdc++.h>
using namespace std;

class Edge
{
public:
    int u, v;
    long long w;
    Edge(int u, int v, long long w)
    {
        this->u = u;
        this->v = v;
        this->w = w;
    }
};

const int N = 1e5 + 5;
long long dist[N];

int main()
{
    int n, e;
    cin >> n >> e;

    vector<Edge> edgeList;
    for (int i = 0; i < e; i++)
    {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        u--;
        v--;
        edgeList.push_back(Edge(u, v, w));
    }

    int s;
    cin >> s;
    s--;

    for (int i = 0; i < n; i++)
    {
        dist[i] = LLONG_MAX;
    }
    dist[s] = 0;

    bool negativeCycle = false;
    for (int i = 1; i <= n - 1; i++)
    {
        for (Edge ed : edgeList)
        {
            int u = ed.u;
            int v = ed.v;
            long long w = ed.w;
            if (dist[u] < LLONG_MAX && dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
            }
        }
    }

    for (Edge ed : edgeList)
    {
        int u = ed.u;
        int v = ed.v;
        long long w = ed.w;
        if (dist[u] < LLONG_MAX && dist[u] + w < dist[v])
        {
            negativeCycle = true;
            break;
        }
    }

    if (negativeCycle)
    {
        cout << "Negative Cycle Detected" << endl;
        return 0;
    }

    int t;
    cin >> t;
    while (t--)
    {
        int d;
        cin >> d;
        d--;

        if (dist[d] == LLONG_MAX)
        {
            cout << "Not Possible" << endl;
        }
        else
        {
            cout << dist[d] << endl;
        }
    }

    return 0;
}
