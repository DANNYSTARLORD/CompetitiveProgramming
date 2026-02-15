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
    int n;
    cin >> n;
    string s;
    cin >> s;

    loop(k, 1, n + 1)
    {
        unordered_set<string> seen;
        bool found = true;
        loop(i, 0, n - k + 1) // length exactly k
        {
            string sub = s.substr(i, k);
            if (seen.count(sub))
            {
                found = false;
                break;
            }
            seen.emplace(sub);
        }
        if (found)
        {
            cout << k << endl;
            return;
        }
    }
}

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);

    // freopen("whereami.in", "r", stdin);
    // freopen("whereami.out", "w", stdout);

    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}
