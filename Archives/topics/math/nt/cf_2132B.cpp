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

// n = x * (pow(10, k)+1)
// x = n/(pow(10, k)+1)

void solve()
{
    ll n;
    cin >> n;
    vector<ll> nums;

    for (int k = 1; k < 18; ++k)
    {
        ll y = 1;
        for (int i = 0; i < k; ++i)
            y *= 10;
        y += 1;

        if (n % y == 0)
            nums.eb(n / y);
    }

    cout << sz(nums) << '\n';
    for (auto num = nums.rbegin(); num != nums.rend(); ++num)
        cout << *num << " ";
    if (!nums.empty())
        cout << '\n';
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