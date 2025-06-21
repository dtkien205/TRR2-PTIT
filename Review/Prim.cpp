#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

struct edge {
    int x, y, w;
};

int n, m, a[105][105], par[105], d[105];
vector<pair<int, int>> adj[105];
bool used[105];

void Prim(int u)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    vector<edge> MST;
    int res = 0;
    q.push({ 0, u });

    while (!q.empty()) {
        auto [w, x] = q.top();
        q.pop();
        if (used[x])
            continue;

        res += w;
        used[x] = true;

        if (u != x)
            MST.push_back({ x, par[x], w });

        for (auto [y, w2] : adj[x]) {
            if (!used[y] && w2 < d[y]) {
                q.push({ w2, y });
                d[y] = w2;
                par[y] = x;
            }
        }
    }

    cout << res << endl;
    for (auto [x, y, w] : MST)
        cout << x << ' ' << y << ' ' << w << endl;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        adj[x].push_back({ y, w });
        adj[y].push_back({ x, w });
    }

    for (int i = 1; i <= n; i++)
        d[i] = 1e9;

    Prim(4);
}
