#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;
#define endl '\n'
#define eb emplace_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define loop1(n) for (int i = 0; i < n; ++i)
#define loop2(a, n) for (int i = a; i < n; ++i)
#define loop3(v, a, n) for (int v = a; v < n; ++v)
#define GET_MACRO(_1, _2, _3, NAME, ...) NAME
#define loop(...) GET_MACRO(__VA_ARGS__, loop3, loop2, loop1)(__VA_ARGS__)
#define rloop(i, b, a) for (int i = b; i >= a; --i)

bool empty(vi &required)
{
    for (const int &i : required)
    {
        if (i > 0)
            return false;
    }
    return true;
}

int dp(const vector<vi> &ac, vi &required, int index, int cost)
{
    if (empty(required))
        return cost;

    if (index >= ac.size())
        return INT_MAX;

    loop(ac[index][0], ac[index][1] + 1)
        required[i] -= ac[index][2];

    int take = dp(ac, required, index + 1, cost + ac[index][3]);

    loop(ac[index][0], ac[index][1] + 1)
        required[i] += ac[index][2];

    int skip = dp(ac, required, index + 1, cost);

    return min(take, skip);
}

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vi> cows(n, vi(3));
    vector<vi> ac(m, vi(4));
    loop(n) cin >> cows[i][0] >> cows[i][1] >> cows[i][2];
    loop(m) cin >> ac[i][0] >> ac[i][1] >> ac[i][2] >> ac[i][3];

    vi required(101, 0);

    for (const auto &v : cows)
    {
        loop(v[0], v[1] + 1)
            required[i] = v[2];
    }

    cout << dp(ac, required, 0, 0) << endl;
}

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    // int t;
    // cin >> t;
    // while (t--)
    solve();
    return 0;
}