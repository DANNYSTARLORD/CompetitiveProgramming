#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using pi = pair<int, int>;
#define eb emplace_back
#define all(x) x.begin(), x.end()
#ifdef LOCAL
#define dbg(x) cerr << #x << " = " << (x) << endl
#else
#define dbg(x)
#endif
constexpr int MOD = 1e9 + 7;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<string> scows(n);
    vector<string> pcows(n);
    for (int i = 0; i < n; ++i)
        cin >> scows[i];
    for (int i = 0; i < n; ++i)
        cin >> pcows[i];

    vector<unordered_set<char>> indices(m);

    for (int i = 0; i < m; ++i)
    {
        for (string &cow : scows)
        {
            indices[i].emplace(cow[i]);
        }
    }

    int sub = 0;

    for (int i = 0; i < m; ++i)
    {
        for (string &cow : pcows)
        {
            if (indices[i].count(cow[i]))
            {
                ++sub;
                break;
            }
        }
    }

    cout << m - sub;
}

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);

    // freopen("cownomics.in", "r", stdin);
    // freopen("cownomics.out", "w", stdout);

    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}
