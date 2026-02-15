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

void dp(vi &coins, set<int> &res, vector<bitset<100000>> &memo, int idx, int sum)
{
    if (idx == coins.size())
    {
        if (sum > 0)
            res.emplace(sum);
        return;
    }

    if (memo[idx][sum])
        return;

    memo[idx][sum] = true;

    dp(coins, res, memo, idx + 1, sum + coins[idx]);
    dp(coins, res, memo, idx + 1, sum);
}

void solve()
{
    int n;
    cin >> n;
    vi coins(n);
    loop(i, 0, n) cin >> coins[i];
    set<int> res;
    vector<bitset<100000>> memo(n);

    dp(coins, res, memo, 0, 0);
    cout << res.size() << endl;

    for (int sum : res)
        cout << sum << " ";
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
