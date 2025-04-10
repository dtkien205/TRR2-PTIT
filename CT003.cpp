#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int t, n, m, u, a[105][105], degIn[105], degOut[105];
set<int> adj[105];
vector<int> ADJ[105];
bool visited[105];

void dfs(int u, vector<int> graph[])
{
    visited[u] = true;
    for (int v : graph[u]) {
        if (!visited[v])
            dfs(v, graph);
    }
}

bool lien_thong_yeu()
{
    memset(visited, false, sizeof(visited));
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            cnt++;
            dfs(i, ADJ);
        }
    }
    return cnt == 1;
}

int isEuler()
{
    if (!lien_thong_yeu())
        return 0;
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (abs(degIn[i] - degOut[i]) == 1)
            cnt++;
    }
    if (!cnt)
        return 1;
    else if (cnt == 2)
        return 2;
    else
        return 0;
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
    freopen("CT.INP", "r", stdin);
    freopen("CT.OUT", "w", stdout);

    cin >> t >> n;
    if (t == 1) {
        for (int i = 1; i <= n; i++) {
            int k;
            cin >> k;
            degOut[i] = k;
            for (int j = 1; j <= k; j++) {
                int x;
                cin >> x;
                adj[i].insert(x);
                ADJ[i].push_back(x);
                ADJ[x].push_back(i);
                degIn[x]++;
            }
        }
        cout << isEuler() << endl;
    } else {
        cin >> u;
        for (int i = 1; i <= n; i++) {
            int k;
            cin >> k;
            degOut[i] = k;
            for (int j = 1; j <= k; j++) {
                int x;
                cin >> x;
                adj[i].insert(x);
                ADJ[i].push_back(x);
                ADJ[x].push_back(i);
                degIn[x]++;
            }
        }
        Euler(u);
    }
}