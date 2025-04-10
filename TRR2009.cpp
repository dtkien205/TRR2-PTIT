#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int n, a[105][105];
vector<int> adj[105];
vector<vector<int>> res;
bool visited[105];

void dfs(int u, vector<int>& tmp)
{
    visited[u] = true;
    tmp.push_back(u);
    for (int v : adj[u]) {
        if (!visited[v])
            dfs(v, tmp);
    }
}

int main()
{
    freopen("TK.INP", "r", stdin);
    freopen("TK.OUT", "w", stdout);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
            if (a[i][j] == 1)
                adj[i].push_back(j);
        }
    }

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            vector<int> curr;
            dfs(i, curr);
            res.push_back(curr);
        }
    }
    cout << res.size() << endl;
    for (auto x : res) {
        sort(x.begin(), x.end());
        for (auto y : x)
            cout << y << ' ';
        cout << endl;
    }
}