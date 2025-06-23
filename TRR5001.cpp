#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define ii pair<int, int>

int n, s, t, par[105];
vector<ii> adj[105];

int main()
{
    freopen("DN.INP", "r", stdin);
    freopen("DN.OUT", "w", stdout);

    cin >> n >> s >> t;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int w;
            cin >> w;
            if (w > 0 && w <= 50)
                adj[i].push_back({ j, w });
        }
    }

    vector<int> d(n + 1, 1e9);
    d[s] = 0;
    priority_queue<ii, vector<ii>, greater<ii>> q;
    q.push({ 0, s });

    while (!q.empty()) {
        auto [dis, u] = q.top();
        q.pop();

        if (dis > d[u])
            continue;

        for (auto [v, w] : adj[u]) {
            if (d[v] > d[u] + w) {
                d[v] = d[u] + w;
                par[v] = u;
                q.push({ d[v], v });
            }
        }
    }

    if (d[t] == 1e9) {
        cout << 0 << endl;
        return 0;
    }

    vector<int> path;
    cout << d[t] << endl;
    while (t != par[t]) {
        path.push_back(t);
        t = par[t];
    }
    reverse(path.begin(), path.end());
    for (int x : path)
        cout << x << ' ';
}