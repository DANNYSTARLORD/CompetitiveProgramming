#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;
#define endl '\n'
#define eb emplace_back
#define all(x) x.begin(), x.end()
const int MOD = 1e9 + 7;
#define dbg(x) cerr << #x << " = " << x << endl
#define loop(i, start, end) for (int i = start; i < end; ++i)

int find(vi &parent, int i)
{
    if (parent[i] == i)
        return i;
    return parent[i] = find(parent, parent[i]);
}

void Union(vi &parent, vi &size, int x, int y)
{
    int xP = find(parent, x), yP = find(parent, y);

    if (xP == yP)
        return;

    if (size[xP] > size[yP])
    {
        size[xP] += size[yP];
        parent[yP] = xP;
    }
    else
    {
        size[yP] += size[xP];
        parent[xP] = yP;
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vi> adj(n);
    vi parent(n);
    iota(all(parent), 0);
    vi size(n, 1);
    loop(i, 0, m)
    {
        int a, b;
        cin >> a >> b;
        Union(parent, size, --a, --b);
    }

    vector<int> reps;
    loop(i, 0, n)
    {
        int p = find(parent, i);
        if (p == i)
            reps.eb(i);
    }

    cout << reps.size() - 1 << endl;
    loop(i, 1, reps.size()) cout << reps[i - 1] + 1 << " " << reps[i] + 1 << endl;
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
