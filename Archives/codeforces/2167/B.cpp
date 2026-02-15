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
    int n;
    cin >> n;
    string k, gf;
    cin >> k >> gf;

    vector<int> freqK(26);
    vector<int> freqGF(26);

    for (int i = 0; i < n; ++i)
    {
        ++freqK[k[i] - 'a'];
        ++freqGF[gf[i] - 'a'];
    }

    for (int i = 0; i < 26; ++i)
    {
        if (freqK[i] != freqGF[i])
        {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);

    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
