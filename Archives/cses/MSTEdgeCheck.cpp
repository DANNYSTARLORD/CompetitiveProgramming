#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define loop(i, s, e) for (int i = (s); i < (e); ++i)
#ifdef LOCAL
#define dbg(x) cerr << #x << " = " << (x) << endl
#else
#define dbg(x)
#endif

struct node
{
    int a, b, w, i;
};

vi sz;
vi parent;

int findPar(int i)
{
    int root = i;
    while (root != parent[root])
        root = parent[root];

    while (root != i)
    {
        int nxt = parent[i];
        parent[i] = root;
        i = nxt;
    }
    return root;
}

void Union(int a, int b)
{
    if ((a = findPar(a)) == (b = findPar(b)))
        return;

    if (sz[a] < sz[b])
        swap(a, b);

    parent[b] = a;
    sz[a] += sz[b];
}

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<node> adj;
    loop(i, 0, m)
    {
        int a, b, w;
        cin >> a >> b >> w;
        --a, --b;
        adj.eb(a, b, w, i);
    }
    sort(all(adj), [](node &x, node &y)
         { return x.w < y.w; });

    parent.resize(n);
    sz.resize(n, 1);
    iota(all(parent), 0);
    vi ans(m, 0);
    int curr = adj[0].w;
    queue<pii> q;

    for (auto &[a, b, w, i] : adj)
    {
        if (curr != w)
        {
            while (!q.empty())
            {
                auto [x, y] = q.front();
                q.pop();
                Union(x, y);
            }
            curr = w;
        }
        if (findPar(a) == findPar(b))
            continue;
        q.emplace(a, b);
        ans[i] = 1;
    }

    for (int out : ans)
    {
        if (out)
            cout << "YES\n";
        else
            cout << "NO\n";
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