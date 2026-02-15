#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using pi = pair<int, int>;
#define endl '\n'
#define eb emplace_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define sz(x) (int)(x).size()
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
    vi shuffle(n);
    loop(n) cin >> shuffle[i];
    vi final(n);
    loop(n) cin >> final[i];

    vi arr = final;
    vi inv(n);
    loop(n) inv[shuffle[i] - 1] = i;
    loop(3)
    {
        vi shuffled(n);
        loop(n) shuffled[inv[i]] = arr[i];
        arr = shuffled;
    }
    loop(n) cout << arr[i] << endl;
}

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);

    freopen("shuffle.in", "r", stdin);
    freopen("shuffle.out", "w", stdout);

    // int t;
    // cin >> t;
    // while (t--)
    solve();
    return 0;
}
