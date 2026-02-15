#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define sz(x) ssize(x)
#define loop(i, start, end) for (int i = start; i < end; ++i)
#ifdef LOCAL
#define dbg(x) cerr << #x << " = " << (x) << endl
#else
#define dbg(x)
#endif

void solve()
{
    ll n, k;
    cin >> n >> k;
    ll x, a, b, c;
    cin >> x >> a >> b >> c;

    ll ans = 0;
    ll sum = x;
    queue<ll> series;
    series.emplace(x);

    for (ll i = 0; i < n - 1; ++i)
    {
        x = (a * x + b) % c;
        if (sz(series) == k)
        {
            ans ^= sum;
            sum ^= series.front();
            series.pop();
        }
        sum ^= x;
        series.emplace(x);
    }

    if (sz(series) == k)
    {
        ans ^= sum;
        sum ^= series.front();
        series.pop();
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