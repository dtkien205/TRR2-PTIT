#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int n, m; // ap dung voi n < 400
int a[1005][1005]; // duong di tu i den j min

void init()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j)
                a[i][j] = 0;
            else
                a[i][j] = 1e9;
        }
    }
    for (int i = 1; i <= m; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        a[x][y] = w;
        a[y][x] = w;
    }
}

void Floyd()
{
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
}

int main()
{
    init();
    Floyd();
    int l, r;
    cin >> l >> r;
    cout << a[l][r] << endl;
}