#include <bits/stdc++.h>

using namespace std;

int n, m;
char A[1000][1000];
bool vis[1000][1000];

// previousStep stores the previous direction that we moved in to arrive at this cell
int previousStep[1000][1000];

// 0 = up, 1 = right, 2 = down, 3 = left
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
string stepDir = "URDL";

bool valid(pair<int, int> v)
{
    // Check if the cell is within bounds
    if (v.first < 0 || v.first >= n || v.second < 0 || v.second >= m)
        return false;
    // Check if the cell is a wall
    if (A[v.first][v.second] == '#')
        return false;
    // Check if the cell has already been visited
    if (vis[v.first][v.second])
        return false;
    return true;
}

void bfs(pair<int, int> begin, pair<int, int> end)
{
    queue<pair<int, int>> q;
    q.push(begin);
    vis[begin.first][begin.second] = true;

    while (!q.empty())
    {
        pair<int, int> u = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            pair<int, int> v = make_pair(u.first + dx[i], u.second + dy[i]);
            if (valid(v))
            {
                vis[v.first][v.second] = true;
                previousStep[v.first][v.second] = i;
                q.push(v);
            }
        }
    }
}

int main()
{
    cin >> n >> m;

    pair<int, int> begin, end;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> A[i][j];
            if (A[i][j] == 'A')
            {
                begin = make_pair(i, j);
            }
            else if (A[i][j] == 'B')
            {
                end = make_pair(i, j);
            }
        }
    }

    bfs(begin, end);

    if (vis[end.first][end.second])
    {
        cout << "YES" << endl;
        vector<int> steps;
        while (end != begin)
        {
            int p = previousStep[end.first][end.second];
            steps.push_back(p);
            // undo the previous step to get back to the previous square
            end = make_pair(end.first - dx[p], end.second - dy[p]);
        }
        reverse(steps.begin(), steps.end());

        cout << steps.size() << endl;
        for (int c : steps)
        {
            cout << stepDir[c];
        }
        cout << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}