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
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    bool hasB = s.find('B') != string::npos;

    while (q--)
    {
        int x;
        cin >> x;
        if (!hasB)
        {
            cout << x << '\n';
            continue;
        }

        long long time = 0;
        int i = 0;
        while (x > 0)
        {
            if (s[i] == 'A')
                --x;
            else
                x /= 2;
            ++time;
            i = (i + 1) % n;
        }
        cout << time << '\n';
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
