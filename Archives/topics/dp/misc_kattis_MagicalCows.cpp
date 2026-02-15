#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template <typename T>
using v = vector<T>;
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define eb emplace_back
#ifdef LOCAL
#define dbg(x) cerr << #x << " = " << (x) << endl
#else
#define dbg(x)
#endif

void solve()
{
    int c, n, m;
    cin >> c >> n >> m;

    const int MAX_DAYS = 50;
    vector<vector<ll>> dp(MAX_DAYS + 1, vector<ll>(c + 1));

    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        dp[0][a]++;
    }

    for (int day = 0; day < MAX_DAYS; day++)
    {
        for (int i = 1; i <= c; i++)
        {
            if (i <= c / 2)
                dp[day + 1][i * 2] += dp[day][i];
            else
                dp[day + 1][i] += 2 * dp[day][i];
        }
    }

    while (m--)
    {
        int day;
        cin >> day;
        ll ans = 0;
        for (int i = 1; i <= c; i++)
            ans += dp[day][i];
        cout << ans << '\n';
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
