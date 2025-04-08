#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define iii tuple<int, int, int>
// #define fast() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int t, n, a[105][105], degIn[105], degOut[105];
vector<iii> edges;

int main()
{
    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);

    cin >> t >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
            if (a[i][j] && a[i][j] != 10000) {
                degOut[i]++;
                degIn[j]++;
                edges.push_back({ i, j, a[i][j] });
            }
        }
    }

    if (t == 1) {
        for (int i = 1; i <= n; i++)
            cout << degIn[i] << ' ' << degOut[i] << endl;
    } else {
        cout << n << ' ' << edges.size() << endl;
        for (auto [x, y, w] : edges)
            cout << x << ' ' << y << ' ' << w << endl;
    }
}