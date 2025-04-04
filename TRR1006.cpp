#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
// #define fast() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int t, n, m, deg[105], res[105][5000];
vector<pair<int, int>> e;

bool cmp(pair<int, int> a, pair<int, int> b)
{
    return a < b;
}

int main()
{
    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);

    cin >> t >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        deg[x]++, deg[y]++;
        e.push_back({ x, y });
    }

    if (t == 1) {
        for (int i = 1; i <= n; i++)
            cout << deg[i] << ' ';
    }
    if (t == 2) {
        sort(e.begin(), e.end());
        for (int i = 0; i < e.size(); i++) {
            res[e[i].first][i + 1] = 1;
            res[e[i].second][i + 1] = 1;
        }
        cout << n << ' ' << m << endl;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= e.size(); j++)
                cout << res[i][j] << ' ';
            cout << endl;
        }
    }
}