#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#ifdef LOCAL
#define dbg(x) cerr << #x << " = " << (x) << endl
#else
#define dbg(x)
#endif

void solve()
{
    int n;
    cin >> n;

    if (n <= 2)
        cout << 0 << '\n';
    else
        cout << (n + 1) / 2 - 1 << '\n';
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
