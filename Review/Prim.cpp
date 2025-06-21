#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int n, s;
vector<pair<int, int>> adj[105];
bool used[105];

void prim(int s)
{
    vector<tuple<int, int, int>> MST;
    int d = 0;
    used[s] = true;

    while (MST.size() < n - 1) {
        int min_w = 1e9, u, v;
        for (int i = 1; i <= n; i++) {
            if (used[i]) {
                for (auto [j, w] : adj[i]) {
                    if (!used[j] && w < min_w)
                        min_w = w, u = i, v = j;
                }
            }
        }
        d += min_w;
        MST.push_back({ u, v, min_w });
        used[v] = true;
    }

    if (MST.size() < n - 1) {
        cout << 0 << endl;
        return;
    }

    cout << d << endl;
    for (auto [x, y, w] : MST)
        cout << min(x, y) << ' ' << max(x, y) << ' ' << w << endl;
}

int main()
{
    freopen("CK.INP", "r", stdin);
    freopen("CK.OUT", "w", stdout);

    cin >> n >> s;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int w;
            cin >> w;
            if (w > 0 && w <= 50)
                adj[i].push_back({ j, w });
        }
    }
    prim(s);
}