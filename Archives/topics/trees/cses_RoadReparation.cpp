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
    int a, b, w;
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
        adj.eb(a, b, w);
    }
    sort(all(adj), [](node &x, node &y)
         { return x.w < y.w; });

    parent.resize(n);
    sz.resize(n, 1);
    iota(all(parent), 0);

    ll ans = 0;

    for (auto &[a, b, w] : adj)
    {
        if (findPar(a) == findPar(b))
            continue;
        Union(a, b);
        ans += w;
    }
    if (sz[findPar(0)] == n)
        cout << ans;
    else
        cout << "IMPOSSIBLE";
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
