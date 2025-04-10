#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int n, a[105][105];
vector<int> adj[105], rev_adj[105], unDir[105];
bool visited[105];

void dfs(int u, vector<int> graph[])
{
    visited[u] = true;
    for (int v : graph[u]) {
        if (!visited[v])
            dfs(v, graph);
    }
}

bool lien_thong_manh()
{
    memset(visited, false, sizeof(visited));
    dfs(1, adj);
    for (int i = 1; i <= n; i++) {
        if (!visited[i])
            return false;
    }
    memset(visited, false, sizeof(visited));
    dfs(1, rev_adj);
    for (int i = 1; i <= n; i++) {
        if (!visited[i])
            return false;
    }
    return true;
}

bool lien_thong_yeu()
{
    memset(visited, false, sizeof(visited));
    dfs(1, unDir);
    for (int i = 1; i <= n; i++) {
        if (!visited[i])
            return false;
    }
    return true;
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
                adj[i].push_back(j);
                rev_adj[j].push_back(i);
                unDir[i].push_back(j);
                unDir[j].push_back(i);
            }
        }
    }
    if (lien_thong_manh())
        cout << 1;
    else if (lien_thong_yeu())
        cout << 2;
    else
        cout << 0;
}