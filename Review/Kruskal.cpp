#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

struct edge {
    int x, y, w;
};

int n, m, a[105][105], sz[105], par[105];
vector<edge> adj;

void init()
{
    for (int i = 1; i <= n; i++) {
        sz[i] = 1;
        par[i] = i;
    }
}

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
    if (u < v)
        swap(u, v);
    sz[u] += sz[v];
    par[v] = u;
    return true;
}

bool cmp(edge a, edge b)
{
    return a.w < b.w;
}

void Kruskal()
{
    vector<edge> MST;
    int res = 0;
    sort(adj.begin(), adj.end(), cmp);

    for (auto [x, y, w] : adj) {
        if (MST.size() == n - 1)
            break;
        if (Union(x, y)) {
            MST.push_back({ x, y, w });
            res += w;
        }
    }

    if (MST.size() < n - 1)
        cout << "Do thi khong lien thong\n";
    else {
        cout << res << endl;
        for (auto [x, y, w] : adj)
            cout << x << ' ' << y << ' ' << w << endl;
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
            if (i < j && a[i][j] && a[i][j] != 100)
                adj.push_back({ i, j, a[i][j] });
        }
    }

    init();
    Kruskal();
}
