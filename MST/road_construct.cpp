#include <bits/stdc++.h>
using namespace std;

const long long int N = 1e5 + 5;

long long int par[N];
long long int group_size[N];

/* Initialize the DSU structure */
void dsu_initialize(long long int n) {
    for (long long int i = 1; i <= n; i++) {
        par[i] = -1;
        group_size[i] = 1;
    }
}

/* Find the leader of the set containing 'node' */
long long int dsu_find(long long int node) {
    if (par[node] == -1) {
        return node;
    }
    return par[node] = dsu_find(par[node]);  // Path compression
}

/* Union the sets containing 'node1' and 'node2' */
void dsu_union_size(long long int node1, long long int node2) {
    long long int leaderA = dsu_find(node1);
    long long int leaderB = dsu_find(node2);

    if (leaderA != leaderB) {
        if (group_size[leaderA] > group_size[leaderB]) {
            par[leaderB] = leaderA;
            group_size[leaderA] += group_size[leaderB];
        } else {
            par[leaderA] = leaderB;
            group_size[leaderB] += group_size[leaderA];
        }
    }
}

/* Class to represent an edge between cities 'u' and 'v' with repair cost 'w' */
class Edge {
public:
    long long int u, v, w;
    Edge(long long int u, long long int v, long long int w) : u(u), v(v), w(w) {}
};

/* Comparison function to sort edges by weight (repair cost) */
bool cmp(Edge a, Edge b) {
    return a.w < b.w;
}

int main() {
    long long int n, m;
    cin >> n >> m;
    
    dsu_initialize(n);

    vector<Edge> edgeList;

    for (long long int i = 0; i < m; i++) {
        long long int u, v, w;
        cin >> u >> v >> w;
        edgeList.push_back(Edge(u, v, w));
    }

    sort(edgeList.begin(), edgeList.end(), cmp);  // Sort edges by repair cost

    long long int totalCost = 0;
    long long int edgesUsed = 0;

    // Process the edges in increasing order of cost
    for (Edge &ed : edgeList) {
        long long int leaderA = dsu_find(ed.u);
        long long int leaderB = dsu_find(ed.v);

        // If the cities are not already connected
        if (leaderA != leaderB) {
            dsu_union_size(ed.u, ed.v);
            totalCost += ed.w;
            edgesUsed++;

            // If we've used n-1 edges, we've connected all cities
            if (edgesUsed == n - 1) break;
        }
    }

    // Check if we were able to connect all cities
    if (edgesUsed == n - 1) {
        cout << totalCost << endl;
    } else {
        cout << "IMPOSSIBLE" << endl;
    }

    return 0;
}
