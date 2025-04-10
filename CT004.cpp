#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
// #define fast() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int n, start, a[105][105];
vector<int> path, adj[105];
vector<vector<int>> cycles;
bool visited[105];

void dfs(int u, int cnt)
{
    if (cnt == n) {
        for (int v : adj[u]) {
            if (v == start) {
                path.push_back(start);
                cycles.push_back(path);
                path.pop_back();
            }
        }
        return;
    }

    for (int v : adj[u]) {
        if (!visited[v]) {
            path.push_back(v);
            visited[v] = true;
            dfs(v, cnt + 1);
            visited[v] = false;
            path.pop_back();
        }
    }
}

int main()
{
    // freopen("CT.INP", "r", stdin);
    // freopen("CT.OUT", "w", stdout);

    cin >> n >> start;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
            if (a[i][j] == 1)
                adj[i].push_back(j);
        }
    }

    visited[start] = true;
    path.push_back(start);
    dfs(start, 1);
    cout << cycles.size() << endl;
    for (auto x : cycles) {
        for (int y : x)
            cout << y << ' ';
        cout << endl;
    }
}
