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

bool bfs(vector<vi> &adj, vi &parent)
{
    vector<bool> vis(adj.size());
    queue<int> q;
    q.emplace(0);
    vis[0] = true;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        for (int &nei : adj[node])
        {
            if (nei == adj.size() - 1)
            {
                parent.back() = node;
                return true;
            }
            else
            {
                if (!vis[nei])
                {
                    q.emplace(nei);
                    parent[nei] = node;
                    vis[nei] = true;
                }
            }
        }
    }
    return false;
}

vi trace(vi &parent)
{
    vi ans;
    ans.eb(parent.size() - 1);

    for (int i = parent.size() - 1; parent[i] != -1; i = parent[i])
    {
        dbg(parent[i]);
        dbg(i);
        ans.eb(parent[i]);
    }

    reverse(all(ans));
    return ans;
}

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<vi> adj(n);

    for (int i = 0; i < m; ++i)
    {
        int a, b;
        cin >> a >> b;
        --a, --b;
        adj[a].eb(b);
        adj[b].eb(a);
    }

    vi parent(n, -1);

    if (!bfs(adj, parent))
        cout << "IMPOSSIBLE";
    else
    {
        vi ans = trace(parent);
        cout << ans.size() << " ";
        for (int &elem : ans)
            cout << elem + 1 << " ";
    }
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
