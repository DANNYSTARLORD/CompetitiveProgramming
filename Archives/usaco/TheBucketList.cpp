#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;
#define endl '\n'
#define eb emplace_back
#define all(x) x.begin(), x.end()
const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1e9 + 7;
#define dbg(x) cerr << #x << " = " << x << endl
#define loop1(n) for (int i = 0; i < (n); ++i)
#define loop2(v, a, n) for (int v = (a); v < (n); ++v)
#define GET_MACRO(_1, _2, _3, NAME, ...) NAME
#define loop(...) GET_MACRO(__VA_ARGS__, loop2, throwaway, loop1)(__VA_ARGS__)
#define rloop(i, b, a) for (int i = b; i >= a; --i)

void solve()
{
    int n;
    cin >> n;
    vector<vi> cows(n, vi(3));
    loop(n) cin >> cows[i][0] >> cows[i][1] >> cows[i][2];
    sort(all(cows));

    int used = 0, maxUsed = 0;

    set<pair<int, int>> ongoing; // end, buckets

    for (const vi &cow : cows)
    {
        while (ongoing.begin() != ongoing.end() && cow[0] > (*ongoing.begin()).first)
        {
            used -= (*ongoing.begin()).second;
            ongoing.erase(ongoing.begin());
        }

        used += cow[2];
        maxUsed = max(used, maxUsed);
        ongoing.emplace(cow[1], cow[2]);
    }

    cout << maxUsed << endl;
}

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);

    // freopen("blist.in", "r", stdin);
    // freopen("blist.out", "w", stdout);

    // int t;
    // cin >> t;
    // while (t--)
    solve();
    return 0;
}
