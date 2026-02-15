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
    int n, k;
    cin >> n >> k;
    unordered_set<int> nums;
    nums.reserve(n + n >> 2);

    for (int i = 0; i < n; ++i)
    {
        int g;
        cin >> g;
        nums.emplace(g);
    }
    if (k < nums.size())
        cout << k;
    else
        cout << nums.size();
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