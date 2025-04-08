#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
// #define fast() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int t, n, a[105][105], degIn[105], degOut[105];

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
            a[i][x] = 1;
        }
    }

    if (t == 1) {
        for (int i = 1; i <= n; i++)
            cout << degIn[i] << ' ' << degOut[i] << endl;
    } else {
        cout << n << endl;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++)
                cout << a[i][j] << ' ';
            cout << endl;
        }
    }
}