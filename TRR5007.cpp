#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

struct edge {
    int x, y, w;
};

int n, s, t, a[105][105];
int d[105], par[105];
vector<edge> e;

int main()
{
    freopen("BN.INP", "r", stdin);
    freopen("BN.OUT", "w", stdout);

    cin >> n >> s >> t;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int w;
            cin >> w;
            if (w != 10000 && i != j)
                e.push_back({ i, j, w });
        }
    }

    fill(d + 1, d + n + 1, 1e9);
    d[s] = 0;
    par[s] = -1;

    for (int i = 1; i <= n - 1; i++) {
        for (auto [u, v, w] : e) {
            if (d[u] < 1e9 && d[v] > d[u] + w) {
                d[v] = d[u] + w;
                par[v] = u;
            }
        }
    }

    for (auto [u, v, w] : e) {
        if (d[u] < 1e9 && d[v] > d[u] + w) {
            cout << -1 << endl;
            return 0;
        }
    }

    if (d[t] == 1e9) {
        cout << 0 << endl;
        return 0;
    }

    vector<int> path;
    for (int x = t; x != -1; x = par[x])
        path.push_back(x);
    reverse(path.begin(), path.end());

    cout << d[t] << endl;
    for (auto x : path)
        cout << x << ' ';
    cout << endl;
}