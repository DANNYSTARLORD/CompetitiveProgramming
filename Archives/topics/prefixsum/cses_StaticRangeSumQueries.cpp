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
    int n, q;
    cin >> n >> q;
    v<ll> nums(n + 1);
    rep(i, 1, n + 1)
    {
        cin >> nums[i];
        nums[i] += nums[i - 1];
    }

    while (q--)
    {
        int a, b;
        cin >> a >> b;
        cout << nums[b] - nums[a - 1] << '\n';
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
