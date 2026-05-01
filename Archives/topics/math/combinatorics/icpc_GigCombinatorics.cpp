#include <bits/stdc++.h>
using namespace std;
template <typename T>
using v = vector<T>;
#define int long long
#define sz(x) (int)(x).size()
#define eb emplace_back
#ifdef LOCAL
#define dbg(x) cerr << #x << " = " << (x) << endl
#else
#define dbg(x)
#endif

const int MOD = 1e9 + 7;

signed main()
{
    cin.tie(nullptr)->sync_with_stdio(false);

    int n;
    cin >> n;
    int cnt1 = 0, S = 0, ans = 0;

    for (int i = 0; i < n; ++i)
    {
        int num;
        cin >> num;
        if (num == 1)
        {
            cnt1 = (cnt1 + 1) % MOD;
            S = (S + 1) % MOD;
        }
        else if (num == 2)
        {
            S = (S * 2) % MOD;
        }
        else
        {
            ans = (ans + S - cnt1) % MOD;
        }
    }

    cout << ans;

    return 0;
}
