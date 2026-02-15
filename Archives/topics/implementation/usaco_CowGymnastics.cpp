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
    int k, n;
    cin >> k >> n;
    vector<vi> lines(k, vi(n));
    loop(i, 0, k) loop(j, 0, n) cin >> lines[i][j];

    unordered_map<int, unordered_set<int>> orders;

    loop(j, 0, n) loop(kk, j + 1, n) orders[lines[0][j]].emplace(lines[0][kk]);

    for (int i = 1; i < k; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            unordered_set<int> seen;
            for (int kk = j + 1; kk < n; ++kk)
            {
                if (orders[lines[i][j]].count(lines[i][kk]))
                    seen.emplace(lines[i][kk]);
            }

            unordered_set<int> erasures;

            for (int y : orders[lines[i][j]])
            {
                if (seen.count(y) == 0)
                    erasures.emplace(y);
            }

            for (int y : erasures)
                orders[lines[i][j]].erase(y);
        }
    }

    int res = 0;

    for (auto &[b, s] : orders)
        res += s.size();

    cout << res << endl;
}

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);

    // freopen("gymnastics.in", "r", stdin);
    // freopen("gymnastics.out", "w", stdout);

    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}
