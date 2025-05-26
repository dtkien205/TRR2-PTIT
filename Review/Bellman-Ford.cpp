#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

// Các đỉnh không phải đỉnh gốc đều là vô cùng
//  Đỉnh gốc có chi phí là 0

// Bước lặp n - 1
//     Duyệt tất cả các cạnh trên đồ thị
//     Relaxtion

struct edge {
    int x, y, w;
};

int n, m;
int d[100005];
vector<edge> e;

void nhap()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        e.push_back({ x, y, w });
    }
}

void BellmanFord(int s)
{
    fill(d + 1, d + n + 1, 1e9);
    d[s] = 0;
    for (int i = 1; i <= n - 1; i++) {
        for (auto [x, y, w] : e) {
            if (d[x] < 1e9)
                d[y] = min(d[y], d[x] + w);
        }
    }
    for (int i = 1; i <= n; i++)
        cout << d[i] << ' ';
}

main()
{
    cin.tie(0)->sync_with_stdio(0);
    nhap();
    BellmanFord(1);
}