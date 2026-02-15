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

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vi> g(n, vi(m));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
            cin >> g[i][j];
    }

    vi row(n, 0), col(m, 0);
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            row[i] += g[i][j];
            col[j] += g[i][j];
        }
    }

    auto wM = [](const vi &arr)
    {
        int total = accumulate(all(arr), 0);
        int half = (total + 1) / 2;
        int prefix = 0;
        for (int i = 0; i < sz(arr); ++i)
        {
            prefix += arr[i];
            if (prefix >= half)
                return i;
        }
        return 0;
    };

    int r = wM(row);
    int c = wM(col);

    ll cost = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
            cost += 1LL * g[i][j] * (abs(i - r) + abs(j - c));
    }

    cout << cost << '\n';
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
