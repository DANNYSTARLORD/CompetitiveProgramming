#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using pi = pair<int, int>;
#define eb emplace_back
#define all(x) x.begin(), x.end()
#ifdef LOCAL
#define dbg(x) cerr << #x << " = " << (x) << endl
#else
#define dbg(x)
#endif
constexpr int MOD = 1e9 + 7;

void solve()
{
    int r, g, b;
    cin >> r >> g >> b;
    int cr, cg, cb;
    cin >> cr >> cg >> cb;
    int crg, cgb;
    cin >> crg >> cgb;

    r = max(0, r - cr);
    g = max(0, g - cg);
    b = max(0, b - cb);

    dbg(r);
    dbg(g);
    dbg(b);

    int ncrg = crg;
    int ncgb = cgb;

    ncrg -= r;
    ncgb -= b;

    if (ncrg < 0 || ncgb < 0 || g > (ncrg + ncgb))
    {
        cout << -1;
        return;
    }

    if (ncrg >= g)
    {
        ncrg -= g;
        g = 0;
    }
    else
    {
        g -= ncrg;
        ncrg = 0;
        ncgb -= g;
    }

    cout << crg - ncrg + cgb - ncgb;
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