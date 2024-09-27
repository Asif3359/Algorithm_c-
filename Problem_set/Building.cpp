#include <bits/stdc++.h>
using namespace std;

const long long int N = 1e5 + 5;

long long int par[N];
long long int group_size[N];
long long int level[N];

void dsu_initialize(long long int n)
{
    for (long long int i = 0; i < n; i++)
    {
        par[i] = -1;
        group_size[i] = 1;
        level[i] = 0;
    }
}

/*
time complexity O(log n);
*/
long long int dsu_find(long long int node)
{
    if (par[node] == -1)
    {
        return node;
    }
    long long int leader = dsu_find(par[node]);
    par[node] = leader;

    return leader;
}

/*
time complexity O(alpha n)
*/
void dsu_union_size(long long int node1, long long int node2)
{
    long long int leaderA = dsu_find(node1);
    long long int leaderB = dsu_find(node2);

    if (group_size[leaderA] > group_size[leaderB])
    {
        par[leaderB] = leaderA;
        group_size[leaderA] += group_size[leaderB];
    }
    else
    {
        par[leaderA] = leaderB;
        group_size[leaderB] += group_size[leaderA];
    }
}

class Edge
{
public:
    long long int u, v, w;
    Edge(long long int u, long long int v, long long int w)
    {
        this->u = u;
        this->v = v;
        this->w = w;
    }
};

bool cmp(Edge a, Edge b)
{
    return a.w < b.w;
}

int main()
{
    long long int n, e;
    cin >> n >> e;
    dsu_initialize(n);

    vector<Edge> edgeList;

    while (e--)
    {
        long long int u, v, w;
        cin >> u >> v >> w;

        edgeList.push_back(Edge(u, v, w));
    }

    sort(edgeList.begin(), edgeList.end(), cmp);

    long long int totalCost = 0;
    long long int edgesUsed = 0;

    for (Edge ed : edgeList)
    {
        long long int leaderA = dsu_find(ed.u);
        long long int leaderB = dsu_find(ed.v);

        if (leaderA == leaderB)
        {
            continue;
        }
        else
        {
            dsu_union_size(ed.u, ed.v);
            totalCost += ed.w;
            edgesUsed++;
            if (edgesUsed == n - 1)
            {
                break;
            }
        }
    }

    if (edgesUsed == n - 1)
    {
        cout << totalCost << endl;
    }
    else
    {
        cout << -1 << endl;
    }

    return 0;
}

/*

5 7
0 1 2
0 2 3
0 3 3
0 4 6
2 4 4
2 1 7
1 4 5


*/