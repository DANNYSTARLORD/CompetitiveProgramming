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
    int a = -1, b = -1;

    for (int i = 2; i * i <= n; ++i)
    {
        if (n % i == 0)
        {
            a = i;
            n /= i;
            break;
        }
    }

    for (int i = 2; i * i <= n; ++i)
    {
        if (n % i == 0 && i != a)
        {
            b = i;
            n /= i;
            break;
        }
    }

    if (b == -1 || n == a || n == b || n == 1)
        cout << "NO\n";
    else
    {
        cout << "YES\n";
        cout << a << " " << b << " " << n << '\n';
    }
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