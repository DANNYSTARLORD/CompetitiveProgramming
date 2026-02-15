#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template <typename T>
using v = vector<T>;
template <typename A, typename B>
using pr = pair<A, B>;
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define rep(i, s, e) for (int i = (s); i < (e); ++i)
#ifdef LOCAL
#define dbg(x) cerr << #x << " = " << (x) << endl
#else
#define dbg(x)
#endif

void solve()
{
    int n, x;
    cin >> n >> x;
    v<int> nums(n);
    rep(i, 0, n) cin >> nums[i];

    ll l = 0, r = 0, sum = 0, ans = 0;

    for (; r < n; ++r)
    {
        sum += nums[r];
        while (sum > x)
        {
            sum -= nums[l];
            ++l;
        }
        if (sum == x)
        {

            sum -= nums[l];
            ++ans, ++l;
        }
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
