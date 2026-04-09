#include <bits/stdc++.h>
using namespace std;
template <typename T>
using v = vector<T>;
#define int long long
#define sz(x) (int)(x).size()
#define eb emplace_back
#ifdef LOCAL
#define dbg(x) cerr << #x << " = " << (x) << endl
#else
#define dbg(x)
#endif

signed main()
{
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;

    v<pair<int, int>> ranges(m);
    v<int> changes(n);

    for (auto &[a, b] : ranges)
    {
        cin >> a >> b;
        --a, --b;

        ++changes[a];
        if (b + 1 < n)
            --changes[b + 1];
    }

    for (int i = 1; i < n; ++i)
        changes[i] += changes[i - 1];

    for (int i = 0; i < n; ++i)
    {
        if (changes[i] & 1)
            s[i] = t[i];
    }

    cout << s;

    return 0;
}
