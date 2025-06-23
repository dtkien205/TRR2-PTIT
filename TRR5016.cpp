#include <bits/stdc++.h>
using namespace std;

int n, a[105][105], e[105][105];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j) {
            cin >> a[i][j];
            if (i != j && a[i][j] <= 50)
                e[i][j] = j;
            else
                e[i][j] = -1;
        }

    for (int k = 1; k <= n; ++k)
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                if (a[i][j] > a[i][k] + a[k][j]) {
                    a[i][j] = a[i][k] + a[k][j];
                    e[i][j] = e[i][k];
                }

    int res = -1, u = -1, v = -1;

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            if (i != j && a[i][j] < 10000)
                if (res == -1 || a[i][j] > res || (a[i][j] == res && tie(i, j) < tie(u, v)))
                    res = a[i][j], u = i, v = j;

    if (res == -1) {
        cout << 0 << endl;
        return 0;
    }

    vector<int> path;
    cout << u << ' ' << v << ' ' << res << endl;
    while (u != v) {
        path.push_back(u);
        u = e[u][v];
    }
    path.push_back(v);

    for (int node : path)
        cout << node << ' ';
    cout << endl;
}