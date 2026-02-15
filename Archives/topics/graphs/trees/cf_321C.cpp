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

int n, m;
vector<vi> adj;
bitset<100000> cat;

int dfs(int node, int parent, int threshold)
{
    if (cat[node])
        --threshold;
    else
        threshold = m; // reset

    if (threshold < 0)
        return 0;

    bool isLeaf = true;
    int cnt = 0;
    for (int &nei : adj[node])
    {
        if(nei == parent) continue;

        isLeaf = false;
        cnt += dfs(nei, node, threshold);
    }

    return isLeaf? 1 : cnt;
}

void solve()
{
    cin >> n >> m;
    adj.assign(n, {});
    cat.reset();

    // cat present?
    for (int i = 0; i < n; ++i)
    {
        bool x;
        cin >> x;
        cat[i] = x;
    }

    for (int i = 0; i < n - 1; ++i)
    {
        int a, b;
        cin >> a >> b;
        adj[--a].eb(--b);
        adj[b].eb(a);
    }

    cout << dfs(0, 0, m) << '\n';
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
