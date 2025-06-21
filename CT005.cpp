#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

// bo doc ghi file

int n, m, s;
vector<int> adj[105], path;
bool vs[105];
vector<vector<int>> res;

void dfs(int u, int cnt)
{
    path.push_back(u);
    vs[u] = true;

    if (cnt == n) {
        for (int v : adj[u]) {
            if (v == s) {
                path.push_back(s);
                res.push_back(path);
                path.pop_back();
            }
        }
    }
    for (int v : adj[u]) {
        if (!vs[v])
            dfs(v, cnt + 1);
    }

    vs[u] = false;
    path.pop_back();
}

int main()
{

    // freopen("CT.in", "r", stdin);
    // freopen("CT.out", "w", stdout);

    cin >> n >> m >> s;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    dfs(s, 1);

    cout << res.size() << endl;
    for (auto v : res) {
        for (auto x : v)
            cout << x << ' ';
        cout << endl;
    }
}