#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;
#define endl '\n'
#define eb emplace_back
#define all(x) x.begin(), x.end()
const int MOD = 1e9 + 7;
#define dbg(x) cerr << #x << " = " << x << endl
#define loop(i, start, end) for (int i = start; i < end; ++i)

void solve()
{
    int x, y, m;
    cin >> x >> y >> m;

    int maxFill = 0;

    for (int i = 0; i <= m / x; ++i)
    {
        int remaining = m - i * x;
        int j = remaining / y;
        int fill = i * x + j * y;
        if (fill <= m)
            maxFill = max(fill, maxFill);
    }

    cout << maxFill;
}

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);

    // freopen("pails.in", "r", stdin);
    // freopen("pails.out", "w", stdout);

    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}
