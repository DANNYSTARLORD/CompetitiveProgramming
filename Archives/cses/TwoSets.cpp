#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)x.size()
#define loop(i, start, end) for (int i = start; i < end; ++i)
#ifdef LOCAL
#define dbg(x) cerr << #x << " = " << (x) << endl
#else
#define dbg(x)
#endif

void solve()
{
    int n;
    cin >> n;
    ll sum = n * 1LL * (n + 1) / 2;

    if (sum & 1)
    {
        cout << "NO\n";
        return;
    }

    vi first, second;
    int pf, pb;

    if (n % 4 == 0)
    {
        pf = 1, pb = n;
    }
    else
    {
        first.eb(1), first.eb(2);
        second.eb(3);
        pf = 4, pb = n;
    }
    while (pf < pb)
    {
        first.eb(pf++), first.eb(pb--);
        second.eb(pf++), second.eb(pb--);
    }

    cout << "YES\n"
         << sz(first) << '\n';
    for (int &item : first)
        cout << item << " ";
    cout << '\n'
         << sz(second) << '\n';
    for (int &item : second)
        cout << item << " ";
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