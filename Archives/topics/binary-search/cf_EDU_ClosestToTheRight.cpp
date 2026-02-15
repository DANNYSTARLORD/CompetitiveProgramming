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
    int n, k;
    cin >> n >> k;
    vi nums(n);
    loop(i, 0, n) cin >> nums[i];

    while (k--)
    {
        int q;
        cin >> q;

        int l = 0, r = n;

        while (l < r)
        {
            int m = l + (r - l) / 2;
            if (nums[m] < q)
                l = m + 1;
            else
                r = m;
        }
        cout << l+1 << '\n';
    }
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