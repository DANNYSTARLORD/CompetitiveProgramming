#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template <typename T>
using v = vector<T>;
template <typename A, typename B>
using p = pair<A, B>;
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define rep(i, s, e) for (int i = (s); i < (e); ++i)
#ifdef LOCAL
#define dbg(x) cerr << #x << " = " << (x) << endl
#else
#define dbg(x)
#endif

v<ll> factorials;

void precompute()
{
    ll i = 2;
    rep(c, 3, 15)
    {
        i *= c;
        factorials.eb(i);
    }
}

void solve()
{
    ll num;
    cin >> num;
    int lim = 1 << sz(factorials);

    ll minx = LLONG_MAX;

    rep(i, 0, lim)
    {
        ll replica = num;
        ll f = 0;
        rep(j, 0, sz(factorials))
        {
            if ((i & (1 << j)) && replica >= factorials[j])
            {
                ++f;
                replica -= factorials[j];
            }
        }
        minx = min(f + __builtin_popcountll(replica), minx);
    }
    cout << minx << "\n";
}

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    precompute();
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}