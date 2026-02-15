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

    ll prefix_sum = 0;
    map<ll, int> remainders;

    for (int &num : nums)
    {
        prefix_sum += num;
        int r = ((prefix_sum % r) + n) % n;
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
