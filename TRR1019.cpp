#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
// #define fast() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int t, n, degIn[105], degOut[105];
vector<pair<int, int>> edges;

int main()
{
    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);

    cin >> t >> n;
    for (int i = 1; i <= n; i++) {
        int k;
        cin >> k;
        degOut[i] = k;
        for (int j = 0; j < k; j++) {
            int x;
            cin >> x;
            degIn[x]++;
            edges.push_back({ i, x });
        }
    }

    if (t == 1) {
        for (int i = 1; i <= n; i++)
            cout << degIn[i] << ' ' << degOut[i] << endl;
    } else {
        cout << n << ' ' << edges.size() << endl;
        for (auto [x, y] : edges)
            cout << x << ' ' << y << endl;
    }
}