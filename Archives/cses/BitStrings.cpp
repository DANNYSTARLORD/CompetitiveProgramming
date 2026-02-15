#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)x.size()
#define loop(i, start, end) for (int i = start; i < end; ++i)
#ifdef LOCAL
#define dbg(x) cerr << #x << " = " << (x) << endl
#else
#define dbg(x)
#endif

constexpr int MOD = 1e9 + 7;

void solve()
{
    int n;
    cin >> n;

    int ans = 1;

    for (int i = 0; i < n; ++i)
    {
        ans = (ans * 2) % MOD;
        dbg(ans);
    }

    cout << ans;
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