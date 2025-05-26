#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

vector<int> adj[1005];
int n, s, a[1005][1005];
bool visited[1005];
vector<pair<int, int>> res;

void dfs(int u)
{
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) {
            res.push_back({ u, v });
            dfs(v);
        }
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
            if (i < j && a[i][j]) {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }

    dfs(1);
    if (res.size() == n - 1) {
        for (auto [u, v] : res)
            cout << u << ' ' << v << endl;
    } else
        cout << -1 << endl;
}