#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int n, a[105][105];
vector<int> adj[105];
bool visited[105];

void dfs(int u)
{
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v])
            dfs(v);
    }
}

int tplt()
{
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            cnt++;
            dfs(i);
        }
    }
    return cnt;
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
    vector<int> res;
    int start = tplt();
    for (int i = 1; i <= n; i++) {
        memset(visited, false, sizeof(visited));
        visited[i] = true;
        if (start < tplt())
            res.push_back(i);
    }
    cout << res.size() << endl;
    for (int x : res)
        cout << x << ' ';
}