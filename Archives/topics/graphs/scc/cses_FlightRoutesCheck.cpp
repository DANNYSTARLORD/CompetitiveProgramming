#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#ifdef LOCAL
#define dbg(x) cerr << #x << " = " << (x) << endl
#else
#define dbg(x)
#endif

void bfs(int i, vector<vi> &adj, vector<bool> &vis)
{
    vis[i] = 1;
    queue<int> q;
    q.emplace(i);

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        for (int &nei : adj[node])
        {
            if (!vis[nei])
            {
                q.emplace(nei);
                vis[nei] = 1;
            }
        }
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vi> adj(n);
    vector<vi> rev_adj(n);

    while (m--)
    {
        int a, b;
        cin >> a >> b;
        --a, --b;
        adj[a].eb(b);
        rev_adj[b].eb(a);
    }

    vector<bool> vis1(n);
    vector<bool> vis2(n);

    bfs(0, adj, vis1);
    bfs(0, rev_adj, vis2);

    for (int i = 0; i < n; ++i)
    {
        if (!vis1[i])
        {

            cout << "NO\n"
                 << 1 << " " << i + 1 << '\n';
            return;
        }
    }
    for (int i = 0; i < n; ++i)
    {
        if (!vis2[i])
        {
            cout << "NO\n"
                 << i + 1 << " 1\n";
            return;
        }
    }

    cout << "YES";
}

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);

    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}
