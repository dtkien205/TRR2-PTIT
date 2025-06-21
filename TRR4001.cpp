#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int n, t, s;
vector<int> adj[105];
vector<pair<int, int>> res;
bool vs[105];

void dfs(int u)
{
    vs[u] = true;
    for (int v : adj[u]) {
        if (!vs[v]) {
            res.push_back({ u, v });
            dfs(v);
        }
    }
}

void bfs(int u)
{
    queue<int> q;
    q.push(u);
    vs[u] = true;

    while (!q.empty()) {
        u = q.front();
        q.pop();
        for (int v : adj[u]) {
            if (!vs[v]) {
                vs[v] = true;
                q.push(v);
                res.push_back({ u, v });
            }
        }
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    freopen("CK.INP", "r", stdin);
    freopen("CK.OUT", "w", stdout);

    cin >> t >> n >> s;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int w;
            cin >> w;
            if (w == 1)
                adj[i].push_back(j);
        }
    }

    (t == 1 ? dfs(s) : bfs(s));

    if (res.size() == n - 1) {
        cout << n - 1 << endl;
        for (auto [u, v] : res) {
            if (u > v)
                swap(u, v);
            cout << u << ' ' << v << endl;
        }
    } else
        cout << 0 << endl;
}