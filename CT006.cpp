#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
// #define fast() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int n, start, a[105][105], res = INT_MAX, sum;
vector<int> path, adj[105];
vector<vector<int>> cycles;
bool visited[105];

void dfs(int u, int cnt)
{
    if (cnt == n) {
        for (int v : adj[u]) {
            if (v == start) {
                sum += a[u][v];
                if (sum < res) {
                    res = sum;
                    cycles.clear();
                    path.push_back(start);
                    cycles.push_back(path);
                    path.pop_back();
                } else if (sum == res) {
                    path.push_back(start);
                    cycles.push_back(path);
                    path.pop_back();
                }
                sum -= a[u][v];
            }
        }
        return;
    }

    for (int v : adj[u]) {
        if (!visited[v]) {
            path.push_back(v);
            visited[v] = true;
            sum += a[u][v];
            dfs(v, cnt + 1);
            visited[v] = false;
            path.pop_back();
            sum -= a[u][v];
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
            if (a[i][j] > 0 && a[i][j] <= 50)
                adj[i].push_back(j);
        }
    }

    visited[start] = true;
    path.push_back(start);
    dfs(start, 1);
    if (res == INT_MAX)
        cout << 0 << endl;
    else {
        cout << res << endl;
        for (auto x : cycles) {
            for (int y : x)
                cout << y << ' ';
            cout << endl;
        }
    }
}
