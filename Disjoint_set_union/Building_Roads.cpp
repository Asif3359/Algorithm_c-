#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int par[N];   // Array to store parent of each node (for DSU)
int level[N]; // Array to store the rank of each node (for union by rank)

// Initialize DSU
void dsu_initialize(int n)
{
    for (int i = 1; i <= n; i++)
    { // Cities are 1-indexed
        par[i] = -1;
        level[i] = 0;
    }
}

// Find the leader of the component (with path compression)
int dsu_find(int node)
{
    if (par[node] == -1)
    {
        return node; // If node is its own leader
    }
    return par[node] = dsu_find(par[node]); // Path compression
}

// Union by rank
void dsu_union_rank(int node1, int node2)
{
    int leaderA = dsu_find(node1);
    int leaderB = dsu_find(node2);

    if (leaderA != leaderB)
    {
        if (level[leaderA] > level[leaderB])
        {
            par[leaderB] = leaderA; // Attach smaller tree under larger tree
        }
        else if (level[leaderB] > level[leaderA])
        {
            par[leaderA] = leaderB;
        }
        else
        {
            par[leaderA] = leaderB;
            level[leaderB]++; // Increment rank when both ranks are equal
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    dsu_initialize(n);

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        dsu_union_rank(a, b); // Process the roads
    }

    // Find the leaders of each component
    vector<int> leaders;
    for (int i = 1; i <= n; i++)
    {
        if (dsu_find(i) == i)
        { // If i is the leader of its component
            leaders.push_back(i);
        }
    }

    // Output the number of new roads needed
    int new_roads = leaders.size() - 1;
    cout << new_roads << endl;

    // Output the new roads to connect the components
    for (int i = 1; i < leaders.size(); i++)
    {
        cout << leaders[i - 1] << " " << leaders[i] << endl;
    }

    return 0;
}
