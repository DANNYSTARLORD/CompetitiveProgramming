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

struct Point
{
    float x, y, w;
};

int bfs(vector<vi> &adj, int i)
{
    queue<int> q;
    q.emplace(i);
    vector<bool> vis(adj.size());
    vis[i] = true;
    int count = 0;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        ++count;

        for (int &nei : adj[node])
        {
            if (!vis[nei])
            {
                q.emplace(nei);
                vis[nei] = true;
            }
        }
    }
    return count;
}

int dfs(vector<vi> &adj, vector<bool> &vis, int i)
{
    vis[i] = true;
    int count = 1;
    for (int &nei : adj[i])
    {
        if (!vis[nei])
            count += dfs(adj, vis, nei);
    }

    return count;
}

void solve()
{
    int n;
    cin >> n;
    vector<Point> nodes(n);
    for (int i = 0; i < n; ++i)
        cin >> nodes[i].x >> nodes[i].y >> nodes[i].w;

    vector<vi> adj(n);

    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            float dis = sqrt(pow(nodes[i].x - nodes[j].x, 2) + pow(nodes[i].y - nodes[j].y, 2));
            if (dis <= nodes[i].w)
                adj[i].eb(j);
            if (dis <= nodes[j].w)
                adj[j].eb(i);
        }
    }

    int reach = 0;

    for (int i = 0; i < n; ++i)
    {
        vector<bool> vis(n, false);
        int temp = dfs(adj, vis, i);
        reach = (temp > reach) ? temp : reach;
    }

    cout << reach;
}

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);

    freopen("moocast.in", "r", stdin);
    freopen("moocast.out", "w", stdout);

    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}
