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

short sz(const vector<unordered_set<short>> &bags, const vector<short> &chosen)
{
    unordered_set<short> res;
    res.reserve(40);

    for (const short &idx : chosen)
    {
        for (const short &candy : bags[idx])
            res.insert(candy);
    }
    return res.size();
}

short dp(vector<unordered_set<short>> &bags, vector<short> chosen, short index, short &k)
{
    if (index >= bags.size() || chosen.size() == k)
        return sz(bags, chosen);

    int skip = dp(bags, chosen, index + 1, k);

    chosen.eb(index);
    int take = dp(bags, chosen, index + 1, k);

    return max(take, skip);
}

void solve()
{
    short b, k;
    cin >> b >> k;
    vector<unordered_set<short>> bags(b);
    loop(b)
    {
        bags[i].reserve(40);
        short x;
        cin >> x;
        loop(j, 0, x)
        {
            short candy;
            cin >> candy;
            bags[i].insert(candy);
        }
    }

    vector<short> chosen;
    chosen.reserve(b);

    cout << dp(bags, chosen, 0, k) << endl;
}

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
