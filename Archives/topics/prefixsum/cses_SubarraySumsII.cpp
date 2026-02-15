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
    int n, x;
    cin >> n >> x;
    v<int> nums(n);
    for (int i = 0; i < n; ++i)
        cin >> nums[i];

    ll prefix_sum = 0, ans = 0;
    map<ll, int> sums;
    sums[0] = 1;

    for (int num : nums)
    {
        prefix_sum += num;

        ans += sums[prefix_sum - x];

        ++sums[prefix_sum];
    }
    cout << ans << '\n';
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
