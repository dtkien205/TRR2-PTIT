#include <bits/stdc++.h>
using namespace std;

#ifdef HoangHoangTuan
#include <debug.h>
#else
#define debug(...) 1901
#endif

#define all(x) x.begin(), x.end()
#define endl '\n'
#define LL long long
const string NAME = "CK";

const int MAXN = 1e3 + 5;
const int INF = 1e9 + 7;

int n, src, a[MAXN][MAXN], dist[MAXN];
bool visited[MAXN];

void DFS(int u)
{
    visited[u] = true;
    for (int v = 1; v <= n; ++v) {
        if (a[u][v] > 0 && !visited[v])
            DFS(v);
    }
}
signed main()
{
    if (fopen((NAME + ".INP").c_str(), "r")) {
        freopen((NAME + ".INP").c_str(), "r", stdin);
        freopen((NAME + ".OUT").c_str(), "w", stdout);
    }

    cin >> n >> src;
    for (int u = 1; u <= n; ++u) {
        for (int v = 1; v <= n; ++v) {
            cin >> a[u][v];
            if (a[u][v] == 10000)
                a[u][v] = 0;
        }
    }

    fill(visited, visited + n + 1, false);
    DFS(src);
    for (int u = 1; u <= n; ++u) {
        if (!visited[u]) {
            cout << 0 << endl;
            return 0;
        }
    }

    vector<array<int, 3>> MST;
    priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>> pq;
    fill(dist, dist + n + 1, INF);

    dist[src] = 0;
    pq.push({ 0, -1, src });
    int dH = 0;
    while (!pq.empty()) {
        auto [du, par, u] = pq.top();
        pq.pop();

        if (du > dist[u])
            continue;

        if (par != -1)
            MST.push_back({ dist[u], par, u });
        dH += dist[u];
        dist[u] = -INF;

        for (int v = 1; v <= n; ++v) {
            if (a[u][v] && a[u][v] <= dist[v]) {
                dist[v] = a[u][v];
                pq.push({ dist[v], u, v });
            }
        }
    }

    cout << dH << endl;
    for (auto [w, u, v] : MST)
        cout << min(u, v) << " " << max(u, v) << " " << w << endl;
}