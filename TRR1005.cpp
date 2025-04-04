#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
// #define fast() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int t, n, m, deg[105];
vector<int> adj[105];

int main()
{
    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);

    cin >> t >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        deg[x]++, deg[y]++;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    if (t == 1) {
        for (int i = 1; i <= n; i++)
            cout << deg[i] << ' ';
    }
    if (t == 2) {
        cout << n << endl;
        for (int i = 1; i <= n; i++) {
            sort(adj[i].begin(), adj[i].end());
            cout << adj[i].size() << ' ';
            for (int x : adj[i])
                cout << x << ' ';
            cout << endl;
        }
    }
}