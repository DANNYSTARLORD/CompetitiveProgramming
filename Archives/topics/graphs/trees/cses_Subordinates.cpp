#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)x.size()
#ifdef LOCAL
#define dbg(x) cerr << #x << " = " << (x) << endl
#else
#define dbg(x)
#endif

int dfs(vector<vi> &adj, vi &sub, int u)
{
    int cnt = 0;
    for (int &node : adj[u])
        cnt += 1 + dfs(adj, sub, node);
    return sub[u] = cnt;
}

void solve()
{
    int n;
    cin >> n;
    vector<vi> adj(n);

    for (int i = 1; i < n; ++i)
    {
        int a;
        cin >> a;
        adj[--a].eb(i);
    }

    vi sub(n);

    dfs(adj, sub, 0);

    for (int &ele : sub)
        cout << ele << " ";
}

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);

    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
