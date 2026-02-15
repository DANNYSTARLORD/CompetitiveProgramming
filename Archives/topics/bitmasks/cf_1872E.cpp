#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define sz(x) ssize(x)
#define loop(i, start, end) for (int i = start; i < end; ++i)
#ifdef LOCAL
#define dbg(x) cerr << #x << " = " << (x) << endl
#else
#define dbg(x)
#endif

void solve()
{
    int n;
    cin >> n;
    vi nums(n);
    loop(i, 0, n) cin >> nums[i];
    string s;
    cin >> s;
    int q;
    cin >> q;

    vi prefxor(n + 1);
    loop(i, 0, n) prefxor[i + 1] = prefxor[i] ^ nums[i];

    int x0 = 0, x1 = 0;

    loop(i, 0, n)
    {
        if (s[i] == '0')
            x0 ^= nums[i];
        else
            x1 ^= nums[i];
    }

    while (q--)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int s, e;
            cin >> s >> e;
            x0 ^= prefxor[s - 1] ^ prefxor[e];
            x1 ^= prefxor[s - 1] ^ prefxor[e];
        }
        else
        {
            int g;
            cin >> g;
            if (g)
                cout << x1 << " ";
            else
                cout << x0 << " ";
        }
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