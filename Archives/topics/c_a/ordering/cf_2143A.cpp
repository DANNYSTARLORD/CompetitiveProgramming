#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;
#define endl '\n'
#define eb emplace_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define loop1(n) for (int i = 0; i < n; ++i)
#define loop2(a, n) for (int i = a; i < n; ++i)
#define loop3(v, a, n) for (int v = a; v < n; ++v)
#define GET_MACRO(_1, _2, _3, NAME, ...) NAME
#define loop(...) GET_MACRO(__VA_ARGS__, loop3, loop2, loop1)(__VA_ARGS__)
#define rloop(i, b, a) for (int i = b; i >= a; --i)

void solve()
{
    int n;
    cin >> n;
    vi p(n);
    for (int i = 0; i < n; i++)
        cin >> p[i];

    int l = 0, r = n - 1;
    bool ok = true;

    loop(x, 1, n + 1)
    {
        if (p[l] == x)
            ++l;
        else if (p[r] == x)
            --r;
        else
        {
            ok = false;
            break;
        }
    }

    cout << (ok ? "YES" : "NO") << endl;
}

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}