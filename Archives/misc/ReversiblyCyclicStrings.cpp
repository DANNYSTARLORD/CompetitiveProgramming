#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)x.size()
#ifdef LOCAL
#define dbg(x) cerr << #x << " = " << (x) << endl
#else
#define dbg(x)
#endif

void solve()
{
    string s;
    cin >> s;

    string chk = s + s;

    for (int i = 0; i < sz(s); ++i)
    {
        for (int j = 1; j < sz(s) - i; ++j)
        {
            string tmp = s.substr(i, j);
            reverse(all(tmp));
            if (chk.find(tmp) == string::npos)
            {
                cout << 0;
                return;
            }
        }
    }
    cout << 1;
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
