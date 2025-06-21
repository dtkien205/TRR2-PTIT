#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define iii tuple<int, int, int>

vector<iii> edges;
int n, m;
int d[10005];

bool check(int s)
{
    fill(d + 1, d + n + 1, 1e9);
    d[s] = 0;
    for (int i = 1; i <= n - 1; i++) {
        for (auto [x, y, w] : edges) {
            if (d[x] < 1e9)
                d[y] = min(d[y], d[x] + w);
        }
    }

    bool ok = false;
    for (auto [x, y, w] : edges) {
        if (d[x] < 1e9) {
            if (d[y] > d[x] + w) {
                ok = true;
                break;
            }
        }
    }
    return ok;
}

int negativeCycle()
{
    fill(d + 1, d + n + 1, 1e9);
    int ok = 0;
    for (int i = 1; i <= n; i++) {
        if (d[i] == 1e9) {
            if (check(i)) {
                ok = 1;
                break;
            }
        }
    }
    return ok;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    
    cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        edges.push_back({ x, y, w });
    }
    cout << negativeCycle() << endl;
}