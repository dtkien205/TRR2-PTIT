#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int t, n, u, a[105][105], degIn[105], degOut[105];
set<int> adj[105];
bool visited[105];

// khong can check lien thong yeu ??

int isEuler()
{
    int cnt1 = 0, cnt2 = 0;
    for (int i = 1; i <= n; ++i) {
        if (abs(degIn[i] - degOut[i]) > 1)
            ++cnt1;
        if (abs(degIn[i] - degOut[i]) == 1)
            ++cnt2;
    }

    if (cnt1)
        return 0;
    else if (cnt2 == 2)
        return 2;
    else
        return 1;
}

void Euler(int u)
{
    stack<int> st;
    vector<int> EC;
    st.push(u);

    while (!st.empty()) {
        int x = st.top();
        if (!adj[x].empty()) {
            int y = *adj[x].begin();
            st.push(y);
            adj[x].erase(y);
            adj[y].erase(x);
        } else {
            st.pop();
            EC.push_back(x);
        }
    }
    reverse(EC.begin(), EC.end());
    for (int x : EC)
        cout << x << ' ';
}

int main()
{
    // freopen("CT.INP", "r", stdin);
    // freopen("CT.OUT", "w", stdout);

    cin >> t >> n;

    if (t == 1) {

        for (int u = 1; u <= n; ++u) {
            string str;
            getline(cin >> ws, str);
            stringstream ss(str);
            string v;
            ss >> v;
            while (ss >> v) {
                int x = stoi(v);
                adj[u].insert(x);
                degIn[x]++;
            }
        }

        for (int i = 1; i <= n; ++i)
            degOut[i] = adj[i].size();

        cout << isEuler() << endl;

    } else {

        cin >> u;
        for (int i = 1; i <= n; i++) {
            int k;
            cin >> k;
            for (int j = 1; j <= k; j++) {
                int x;
                cin >> x;
                adj[i].insert(x);
            }
        }
        Euler(u);
    }
}