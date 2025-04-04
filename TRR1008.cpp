#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
// #define fast() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

// sai test mau

int t, n, m, deg[105], a[105][105];
vector<pair<int, int>> edges;

int main()
{
    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);

    cin >> t >> n;
    for (int i = 1; i <= n; i++) {
        int k;
        cin >> k;
        deg[i] = k;
        while (k--) {
            int x;
            cin >> x;
            if (i < x)
                edges.push_back({ i, x });
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
