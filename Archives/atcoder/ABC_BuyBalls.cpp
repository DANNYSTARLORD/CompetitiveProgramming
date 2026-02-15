#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define loop(i, s, e) for (int i = (s); i < (e); ++i)
#ifdef LOCAL
#define dbg(x) cerr << #x << " = " << (x) << endl
#else
#define dbg(x)
#endif

void solve()
{
    int b, w;
    cin >> b >> w;
    vi black(b), white(w);
    loop(i, 0, b) cin >> black[i];
    loop(i, 0, w) cin >> white[i];
    sort(all(black), greater<int>()), sort(all(white), greater<int>());

    ll blacksum = 0, bp = 0;
    for (; bp < b && black[bp] >= 0; ++bp)
        blacksum += black[bp];

    ll whitesum = 0, wp = 0;
    for(; wp < w && white[wp] >= 0 && wp < bp; ++wp)
        whitesum += white[wp];

    ll ans = whitesum + blacksum;

    if(bp == b || wp == w || (black[bp] < 0 && white[wp] < 0)){
        cout << ans;
        return;
    }

    for(; wp < w && bp < b && black[bp] + white[wp] >= 0; ++bp, ++wp)
        ans += black[bp] + white[wp];

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
