#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define ii pair<int, int>

int n, m, s;
vector<ii> adj[1005];

void dijkstra()
{
    priority_queue<ii, vector<ii>, greater<ii>> q;
    q.push({ 0, s });
    vector<int> d(n + 1, 1e9);
    d[s] = 0;

    while (!q.empty()) {
        auto [dis, u] = q.top();
        q.pop();
        if (dis > d[u])
            continue;

        for (auto [v, w] : adj[u]) {
            if (d[v] > d[u] + w) {
                d[v] = d[u] + w;
                q.push({ d[v], v });
            }
        }
    }
    for (int i = 1; i <= n; i++)
        cout << d[i] << ' ';
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    cin >> n >> m >> s;
    for (int i = 0; i < m; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        adj[x].push_back({ y, w });
        adj[y].push_back({ x, w });
    }
    dijkstra();
}