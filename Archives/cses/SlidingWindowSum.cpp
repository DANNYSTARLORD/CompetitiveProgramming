#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
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
        sum += x;
        series.emplace(x);

        if (series.size() == k)
        {
            ans ^= sum;
            sum -= series.front();
            series.pop();
        }
    }
    
    if (series.size() == k)
    {
        ans ^= sum;
        sum -= series.front();
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
