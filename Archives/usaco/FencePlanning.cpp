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
    int x, y;
};

void bfs(int i, vector<vi> &adj, vector<bool> &vis, vector<vi> &reach)
{
    queue<int> q;
    q.emplace(i);
    vis[i] = true;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        for (int &nei : adj[node])
        {
            if (!vis[nei])
            {
                q.emplace(nei);
                reach[i].eb(nei);
                vis[nei] = true;
            }
        }
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<Point> coords(n);

    for (int i = 0; i < n; ++i)
        cin >> coords[i].x >> coords[i].y;

    vector<vi> adj(n);
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        --a, --b;
        adj[a].eb(b);
        adj[b].eb(a);
        dbg(5);
    }

    vector<vi> reach(n);
    vector<bool> vis(n);

    for (int i = 0; i < n; ++i)
    {
        if (!vis[i])
            bfs(i, adj, vis, reach);
    }

    int peri = INT_MAX;

    for (int node = 0; node < n; ++node)
    {
        if (reach[node].empty())
            continue;

        int maxX = 0, minX = INT_MAX;
        int maxY = 0, minY = INT_MAX;

        Point curr = coords[node];

        if (curr.x > maxX)
            maxX = curr.x;
        if (curr.x < minX)
            minX = curr.x;
        if (curr.y > maxY)
            maxY = curr.y;
        if (curr.y < minY)
            minY = curr.y;

        for (int &nei : reach[node])
        {
            curr = coords[nei];

            if (curr.x > maxX)
                maxX = curr.x;
            if (curr.x < minX)
                minX = curr.x;
            if (curr.y > maxY)
                maxY = curr.y;
            if (curr.y < minY)
                minY = curr.y;
        }
        int currPeri = 2 * (maxX - minX + maxY - minY);
        peri = (peri > currPeri) ? currPeri : peri;
    }
    cout << peri;
}

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);

    // freopen("fenceplan.in", "r", stdin);
    // freopen("fenceplan.out", "w", stdout);

    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}
