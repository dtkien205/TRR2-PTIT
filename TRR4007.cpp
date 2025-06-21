#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int n, m;
vector<tuple<int, int, int>> adj;
int par[105], sz[105];

int Find(int u)
{
    if (u == par[u])
        return u;
    return par[u] = Find(par[u]);
}

bool Union(int u, int v)
{
    u = Find(u), v = Find(v);
    if (u == v)
        return false;
    if (u > v)
        swap(u, v);
    sz[u] += sz[v];
    par[v] = u;
    return true;
}

void Kruskal()
{
    vector<tuple<int, int, int>> MST;
    int res = 0;
    sort(adj.begin(), adj.end());

    for (auto [w, x, y] : adj) {
        if (MST.size() == n - 1)
            break;
        if (Union(x, y)) {
            res += w;
            MST.push_back({ w, x, y });
        }
    }

    if (MST.size() < n - 1)
        cout << 0 << endl;
    else {
        cout << res << endl;
        for (auto [w, x, y] : MST)
            cout << x << ' ' << y << ' ' << w << endl;
    }
}

int main()
{
    freopen("CK.INP", "r", stdin);
    freopen("CK.OUT", "w", stdout);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        sz[i] = 1;
        par[i] = i;
    }

    for (int i = 0; i < m; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        adj.push_back({ w, x, y });
    }

    Kruskal();
}