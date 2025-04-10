#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int t, n, u, v, a[105][105], parent[105];
vector<int> path, adj[105];
bool visited[105];

void bfs(int u)
{
    visited[u] = true;
    queue<int> q;
    q.push(u);
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (int y : adj[x]) {
            if (!visited[y]) {
                visited[y] = true;
                q.push(y);
                parent[y] = x;
            } 
        }
    }
}

int main()
{
    freopen("TK.INP", "r", stdin);
    freopen("TK.OUT", "w", stdout);

    cin >> t >> n >> u >> v;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
            if (a[i][j] == 1) 
                adj[i].push_back(j);
        }
    }

    if (t == 1) {
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            if (a[u][i] && a[i][v])
                cnt++;
        }
        cout << cnt << endl;
    } else {
        bfs(u);
        if (!visited[v])
            cout << 0 << endl;
        else {
            while (v != u) {
                path.push_back(v);
                v = parent[v];
            }
            path.push_back(u);
            reverse(path.begin(), path.end());
            for (int x : path)
                cout << x << ' ';
        }
    }
}