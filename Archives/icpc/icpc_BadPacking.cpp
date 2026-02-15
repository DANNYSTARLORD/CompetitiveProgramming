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
#define loop(n) for (int i = 0; i < n; ++i)

int n, c;
vi weights;
vector<unordered_map<int, int>> memo;

int dp(int i, int rem)
{
    if (i == n)
        return rem;

    auto &cache = memo[i];
    if (auto it = cache.find(rem); it != cache.end())
        return it->second;

    int best = -1;

    if (rem >= weights[i])
    {
        int take = dp(i + 1, rem - weights[i]);
        if (take != -1)
            best = max(take, best);
    }

    int skip = dp(i + 1, rem);
    if (skip != -1 && skip < weights[i])
        best = max(skip, best);

    return cache[rem] = best;
}

void solve()
{
    cin >> n >> c;
    weights.resize(n);
    loop(n) cin >> weights[i];
    sort(all(weights), greater<int>());

    memo.assign(n, {});

    int left = dp(0, c);
    int used = c - left;
    cout << used << endl;
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
