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
    int n;
    cin >> n;
    v<int> nums(n);
    for (int &num : nums)
        cin >> num;

    // (prefix_sum) / x = divisor
    // (prefix_sum) / divisor = x

    ll prefix_sum = 0, ans = 0;
    map<ll, int> divisors;
    divisors[1] = 1;

    for (int num : nums)
    {
        prefix_sum += num;

        if (prefix_sum % n == 0)
            ans += divisors[prefix_sum / n];

        ++divisors[prefix_sum];
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
