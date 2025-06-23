#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define ii pair<int, int>

int n, m, s, t, a[105][105], par[105], e[105][105], ans = INT_MAX, sum;
bool vs[105];
// vector<tuple<int, int, int>> e;
vector<int> adj[105];
vector<int> path;
vector<vector<int>> res;

void dfs(int u, int cnt)
{
    if (cnt == n) {
        for (int v : adj[u]) {
            if (v == s) {
                sum += a[u][v];
                if (ans > sum) {
                    ans = sum;
                    res.clear();
                    path.push_back(v);
                    res.push_back(path);
                    path.pop_back();
                }
                sum -= a[u][v];
                if (sum == ans) {
                    path.push_back(v);
                    res.push_back(path);
                    path.pop_back();
                }
            }
        }
    }

    for (int v : adj[u]) {
        if (!vs[v]) {
            sum += a[u][v];
            path.push_back(v);
            vs[v] = true;
            dfs(v, cnt + 1);
            vs[v] = false;
            sum -= a[u][v];
            path.pop_back();
        }
    }
}

int main()
{
    // freopen("DN.INP", "r", stdin);
    // freopen("DN.OUT", "w", stdout);

    cin >> n >> s;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
            if (a[i][j] <= 50 && a[i][j] > 0)
                adj[i].push_back(j);
        }
    }
    vs[s] = true;
    path.push_back(s);
    dfs(s, 1);

    if (ans == INT_MAX) {
        cout << 0 << endl;
        return 0;
    }

    cout << ans << endl;
    for (auto v : res) {
        for (int x : v)
            cout << x << ' ';
        cout << endl;
    }
}