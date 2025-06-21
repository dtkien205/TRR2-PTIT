#include <bits/stdc++.h>
using namespace std;
#define iii tuple<int, int, int>

struct edge {
    int x, y, w;
};

int n, s, a[105][105], par[105], d[105];
vector<pair<int, int>> adj[105];
bool used[105];

void Prim(int u)
{
    priority_queue<iii, vector<iii>, greater<iii>> q;
    vector<edge> MST;
    int res = 0;

    fill(d + 1, d + n + 1, 1e9);
    fill(par + 1, par + n + 1, -1);

    d[u] = 0;
    q.push({ 0, -1, u });

    while (!q.empty()) {
        auto [w, x, y] = q.top();
        q.pop();
        if (used[y])
            continue;

        used[y] = true;
        res += w;
        if (x != -1)
            MST.push_back({ x, y, w });

        for (auto [v, w2] : adj[y]) {
            if (!used[v] && w2 < d[v]) {
                d[v] = w2;
                par[v] = y;
                q.push({ w2, y, v });
            }
        }
    }

    if (MST.size() < n - 1) {
        cout << 0 << endl;
        return;
    }

    cout << res << endl;
    for (auto [u, v, w] : MST)
        cout << min(u, v) << ' ' << max(u, v) << ' ' << w << endl;
}

int main()
{
    freopen("CK.INP", "r", stdin);
    freopen("CK.OUT", "w", stdout);

    cin >> n >> s;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
            if (i != j && a[i][j] < 10000)
                adj[i].push_back({ j, a[i][j] });
        }
    }

    Prim(s);
}
