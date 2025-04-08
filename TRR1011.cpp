#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define iii tuple<int, int, int>
// #define fast() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int t, n, m, c[105][105], deg[105];

int main()
{
    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);

    cin >> t >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        c[x][y] = c[y][x] = w;
        deg[x]++, deg[y]++;
    }

    if (t == 1) {
        for (int i = 1; i <= n; i++)
            cout << deg[i] << ' ';
    } else {
        cout << n << endl;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i != j && !c[i][j])
                    c[i][j] = 10000;
                cout << c[i][j] << ' ';
            }
            cout << endl;
        }
    }
}