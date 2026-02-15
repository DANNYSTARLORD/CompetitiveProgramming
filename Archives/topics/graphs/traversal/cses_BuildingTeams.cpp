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

bool dfs(int u, vector<vi> &adj, vi &teams)
{
    int assign;
    if (teams[u] == 0)
    {
        teams[u] = 1;
        assign = 2;
    }
    else
        assign = (teams[u] == 1) ? 2 : 1;

    for (int &nei : adj[u])
    {
        if (teams[nei] == 0)
        {
            teams[nei] = assign;
            if (!dfs(nei, adj, teams))
                return false;
        }
        else if (teams[nei] != assign)
            return false;
    }
    return true;
}

bool bfs(int u, vector<vi> &adj, vi &teams)
{
    queue<int> q;
    q.emplace(u);

    while (!q.empty())
    {
        int v = q.front();
        q.pop();

        int assign;

        if (teams[v] == 0)
        {
            teams[v] = 1;
            assign = 2;
        }
        else
            assign = (teams[v] == 1) ? 2 : 1;

        for (int &nei : adj[v])
        {
            if (teams[nei] != 0)
            {
                if (teams[nei] != assign)
                    return false;
                continue;
            }
            teams[nei] = assign;
            q.emplace(nei);
        }
    }
    return true;
}

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<vi> adj(n);
    vi teams(n);

    for (int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;
        --u, --v; // 0 based indexing
        adj[u].eb(v);
        adj[v].eb(u);
    }

    for (int u = 0; u < n; ++u)
    {
        if (teams[u] != 0)
            continue;
        if (!dfs(u, adj, teams))
        {
            cout << "IMPOSSIBLE";
            return;
        }
    }

    for (int &t : teams)
        cout << t << " ";
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
