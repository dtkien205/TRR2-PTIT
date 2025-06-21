#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int n;
vector<int> adj[105];
bool vs[105];

void dfs(int u, vector<int> g[])
{
    vs[u] = true;
    for (int v : g[u]) {
        if (!vs[v])
            dfs(v, g);
    }
}

bool stronglyConnected()
{
    for (int i = 1; i <= n; i++) {
        memset(vs, false, sizeof(vs));
        dfs(i, adj);
        for (int j = 1; j <= n; j++)
            if (!vs[j])
                return false;
    }
    return true;
}

bool weaklyConnected()
{
    vector<int> undir[105];
    for (int u = 1; u <= n; u++) {
        for (int v : adj[u]) {
            undir[u].push_back(v);
            undir[v].push_back(u);
        }
    }
    memset(vs, false, sizeof(vs));
    dfs(1, undir);
    for (int i = 1; i <= n; i++) {
        if (!vs[i])
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
            int w;
            cin >> w;
            if (w)
                adj[i].push_back(j);
        }
    }
    if (stronglyConnected())
        cout << 1;
    else if (weaklyConnected())
        cout << 2;
    else
        cout << 0;
}