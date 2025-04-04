#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
// #define fast() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int t, n;
int a[105][105], deg[105];

int main()
{
    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);
    cin >> t >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
            if (a[i][j] == 1)
                deg[i]++;
        }
    }
    if (t == 1) {
        for (int i = 1; i <= n; i++)
            cout << deg[i] << ' ';
    }
    if (t == 2) {
        cout << n << endl;
        for (int i = 1; i <= n; i++) {
            cout << deg[i] << ' ';
            for (int j = 1; j <= n; j++) {
                if (a[i][j] == 1)
                    cout << j << ' ';
            }
            cout << endl;
        }
    }
}
