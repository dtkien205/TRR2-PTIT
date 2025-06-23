#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int t, n, u, degIn[105], degOut[105];
set<int> adj[105];
bool visited[105];

int isEuler()
{
    int cnt = 0;
    for (int i = 1; i <= n; ++i) {
        int x = abs(degIn[i] - degOut[i]);
        if (x > 1)
            return 0;
        if (x == 1)
            cnt++;
    }
    if (cnt == 0)
        return 1;
    else if (cnt == 2)
        return 2;
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
    // freopen("CT.INP", "r", stdin);
    // freopen("CT.OUT", "w", stdout);

    cin >> t >> n;
    if (t == 2)
        cin >> u;

    for (int u = 1; u <= n; ++u) {
        string str;
        getline(cin >> ws, str);
        stringstream ss(str);
        string v;
        ss >> v;
        while (ss >> v) {
            int x = stoi(v);
            adj[u].insert(x);
            degIn[u]++;
            degOut[x]++;
        }
    }

    if (t == 1)
        cout << isEuler() << endl;
    else
        Euler(u);
}