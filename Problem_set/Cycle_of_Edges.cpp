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

int main()
{
    long long int count = 0;
    long long int n, e;
    cin >> n >> e;

    dsu_initialize(n);

    bool cycle = false;
    while (e--)
    {
        long long int a, b;
        cin >> a >> b;
        long long int leaderA = dsu_find(a);
        long long int leaderB = dsu_find(b);

        if (leaderA == leaderB)
        {
            count++;
        }
        else
        {
            dsu_union_size(a, b);
        }
    }

    cout << count << endl;

    return 0;
}

/*

6 6
0 1
0 2
0 3
3 4
3 5
4 5

*/