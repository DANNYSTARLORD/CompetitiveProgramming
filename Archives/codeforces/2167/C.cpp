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
    vi toys(n);
    bool hasOdd = false;
    bool hasEven = false;
    for (int i = 0; i < n; ++i)
    {
        cin >> toys[i];
        if (toys[i] & 1)
            hasOdd = 1;
        else
            hasEven = 1;
    }
    if (!(hasEven && hasOdd))
    {
        for (int i = 0; i < n; ++i)
            cout << toys[i] << " ";
    }
    else
    {
        sort(all(toys));
        for (int i = 0; i < n; ++i)
            cout << toys[i] << " ";
    }
    cout << '\n';
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
