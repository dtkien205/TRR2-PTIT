#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int n, a[105][105];
vector<int> adj[105];
bool visited[105];
vector<pair<int, int>> edges;

void dfs(int u, int s, int t)
{
    visited[u] = true;
    for (int v : adj[u]) {
        if ((u == s && v == t) || (u == t && v == s))
            continue;
        if (!visited[v])
            dfs(v, s, t);
    }
}

int tplt(int s, int t)
{
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            cnt++;
            dfs(i, s, t);
        }
    }
    return cnt;
}

int main()
{
    freopen("TK.INP", "r", stdin);
    freopen("TK.OUT", "w", stdout);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
            if (a[i][j] == 1) {
                adj[i].push_back(j);
                if (i < j)
                    edges.push_back({ i, j });
            }
        }
    }
    vector<pair<int, int>> res;
    int start = tplt(0, 0);
    for (auto [x, y] : edges) {
        memset(visited, false, sizeof(visited));
        if (start < tplt(x, y)) 
            res.push_back({ x, y });
    }

    cout << res.size() << endl;
    for (auto [x, y] : res)
        cout << x << ' ' << y << endl;
}