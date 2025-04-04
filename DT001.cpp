#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
// #define fast() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

// bỏ đọc ghi file mới AC

int t, n;
int a[105][105], deg[105];
vector<pair<int, int>> edges;

int main()
{
    // freopen("DT.INP", "r", stdin);
    // freopen("DT.OUT", "w", stdout);

    cin >> t >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
            if (a[i][j] == 1) {
                deg[i]++;
                if (i < j)
                    edges.push_back({ i, j });
            }
        }
    }

    if (t == 1) {
        for (int i = 1; i <= n; i++)
            cout << deg[i] << ' ';
    } else {
        cout << n << ' ' << edges.size() << endl;
        for (auto [x, y] : edges)
            cout << x << ' ' << y << endl;
    }
}
