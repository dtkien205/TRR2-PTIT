#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int t, n, x, res[105][10000], deg[105];
vector<pair<int, int>> e;

int main()
{
    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);

    cin >> t >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> x;
            if (x == 1) {
                deg[i]++;
                if (i < j)
                    e.push_back({ i, j });
            }
        }
    }
    if (t == 1) {
        for (int i = 1; i <= n; i++)
            cout << deg[i] << ' ';
    } else {
        for (int i = 0; i < e.size(); i++) {
            auto [u, v] = e[i];
            res[u][i + 1] = 1;
            res[v][i + 1] = 1;
        }

        cout << n << ' ' << e.size() << endl;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= e.size(); j++)
                cout << res[i][j] << ' ';
            cout << endl;
        }
    }
}