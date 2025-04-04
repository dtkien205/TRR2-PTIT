#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
// #define fast() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int t, n;
int a[105][105], res[105][10000], deg[105];

int main()
{
    // freopen("DT.INP", "r", stdin);
    // freopen("DT.OUT", "w", stdout);

    cin >> t >> n;
    vector<pair<int, int>> e;
    memset(res, 0, sizeof(res));
    memset(deg, 0, sizeof(deg));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
            if (a[i][j] == 1) {
                deg[i]++;
                if (i < j)
                    e.push_back({ i, j });
            }
        }
    }
    if (t == 1) {
        for (int i = 1; i <= n; i++)
            cout << deg[i] << ' ';
    }
    if (t == 2) {
        for (int i = 0; i < e.size(); i++) {
            res[e[i].first][i + 1] = 1;
            res[e[i].second][i + 1] = 1;
        }
        cout << n << ' ' << e.size() << endl;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= e.size(); j++)
                cout << res[i][j] << ' ';
            cout << endl;
        }
    }
}