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
    int n, m;
    cin >> n >> m;
    vi teams(m);
    for (int i = 0; i < m; ++i)
        cin >> teams[i];

    int lo = 0, hi = 0, best = 0;
    for (int t : teams)
        hi = max(hi, t);

    while (lo <= hi)
    {
        int mid = midpoint(lo, hi);
        int total = 0;

        for (int t : teams)
        {
            total += min(mid, t);
            if (total > n)
                break;
        }

        if (total <= n)
        {
            best = mid;
            lo = mid + 1;
        }
        else
        {
            hi = mid - 1;
        }
    }

    vi accepted(m);
    int used = 0;
    for (int i = 0; i < m; ++i)
    {
        accepted[i] = min(best, teams[i]);
        used += accepted[i];
    }

    int remaining = n - used;
    for (int i = 0; i < m && remaining > 0; ++i)
    {
        if (teams[i] > accepted[i])
        {
            ++accepted[i];
            --remaining;
        }
    }

    for (int &a : accepted)
        cout << a << '\n';
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
