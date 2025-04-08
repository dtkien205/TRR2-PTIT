#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define iii tuple<int, int, int>
// #define fast() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int t, n, c[105][105], deg[105];
vector<iii> edges;

int main()
{
    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);

    cin >> t >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> c[i][j];
            if (c[i][j] != 10000 && c[i][j]) {
                deg[i]++;
                if (i < j)
                    edges.push_back({ i, j, c[i][j] });
            }
        }
    }

    if (t == 1) {
        for (int i = 1; i <= n; i++)
            cout << deg[i] << ' ';
    } else {
        cout << n << ' ' << edges.size() << endl;
        for (auto [x, y, z] : edges)
            cout << x << ' ' << y << ' ' << z << endl;
    }
}