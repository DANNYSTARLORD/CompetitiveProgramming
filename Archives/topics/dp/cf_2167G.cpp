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
    int n;
    cin >> n;
    vi nums(n);
    for (int i = 0; i < n; ++i)
        cin >> nums[i];
    vi costs(n);
    for (int i = 0; i < n; ++i)
        cin >> costs[i];

    // dp[i] = maximum sum of costs for a non-decreasing subsequence ending at position i
    vector<ll> dp(n);
    ll tc = 0;

    //[1,1,1,1]
    //[4,3,2,1]
    for (int i = 0; i < n; ++i)
    {
        dp[i] = costs[i];
        tc += costs[i];

        for (int j = 0; j < i; ++j)
        {
            if (nums[j] <= nums[i])
                dp[i] = max(dp[i], dp[j] + costs[i]);
        }
    }

    ll msc = *max_element(all(dp));

    cout << tc - msc << "\n";
}

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);

    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}