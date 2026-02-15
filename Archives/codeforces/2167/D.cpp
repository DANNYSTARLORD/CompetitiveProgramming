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
    ll g = 0;
    for (int i = 0; i < n; ++i)
    {
        ll num;
        cin >> num;
        g = gcd(g, num);
    }

    ll ans = -1;
    for (ll x = 2; x <= 100; ++x)
    {
        if (gcd(g, x) == 1)
        {
            ans = x;
            break;
        }
    }

    cout << ans << '\n';
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
