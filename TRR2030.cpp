#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int n, a[105][105];
set<int> adj[105];
bool visited[105];
vector<pair<int, int>> edges;

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
            }
        }
    }
}

int tplt()
{
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            cnt++;
            bfs(i);
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
            if (a[i][j] == 1) {
                adj[i].insert(j);
                if (i < j)
                    edges.push_back({ i, j });
            }
        }
    }
    vector<pair<int, int>> res;
    int start = tplt();
    for (auto [x, y] : edges) {
        adj[x].erase(y);
        adj[y].erase(x); // xoa canh x-y
        memset(visited, false, sizeof(visited));
        if (start < tplt())
            res.push_back({ x, y });
        adj[x].insert(y);
        adj[y].insert(x); // them lai canh x-y
    }

    cout << res.size() << endl;
    for (auto [x, y] : res)
        cout << x << ' ' << y << endl;
}