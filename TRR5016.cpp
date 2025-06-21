#include <bits/stdc++.h>
using namespace std;

const int INF = 10000;
int n, a[105][105], nxt[105][105];

void init()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j) {
            cin >> a[i][j];
            if (i != j && a[i][j] < INF)
                nxt[i][j] = j;
            else
                nxt[i][j] = -1;
        }
}

void Floyd()
{
    for (int k = 1; k <= n; ++k)
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                if (a[i][k] < INF && a[k][j] < INF && a[i][j] > a[i][k] + a[k][j]) {
                    a[i][j] = a[i][k] + a[k][j];
                    nxt[i][j] = nxt[i][k];
                }
}

int main()
{
    freopen("DN.INP", "r", stdin);
    freopen("DN.OUT", "w", stdout);

    init();
    Floyd();

    int res = -1, u = -1, v = -1;

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            if (i != j && a[i][j] < INF) {
                if (res == -1 || a[i][j] > res || (a[i][j] == res && tie(i, j) < tie(u, v))) {
                    res = a[i][j];
                    u = i;
                    v = j;
                }
            }

    if (res == -1) {
        cout << 0 << endl;
        return 0;
    }

    vector<int> path;
    int tmp = u;
    while (tmp != v) {
        path.push_back(tmp);
        tmp = nxt[tmp][v];
        if (tmp == -1) {
            cout << 0 << endl;
            return 0;
        }
    }
    path.push_back(v);

    cout << u << ' ' << v << ' ' << res << endl;
    for (int node : path)
        cout << node << ' ';
    cout << endl;
}
