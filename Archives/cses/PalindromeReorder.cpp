#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template <typename T>
using v = vector<T>;
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define eb emplace_back
#ifdef LOCAL
#define dbg(x) cerr << #x << " = " << (x) << endl
#else
#define dbg(x)
#endif

void solve()
{
    string s;
    cin >> s;

    v<int> freq(26, 0);

    for (char &c : s)
        ++freq[c - 'A'];

    bool odd = 0, fail = 0;

    for (int &i : freq)
    {
        if (i == 0)
            continue;

        if (i & 1 && odd)
            fail = 1;
        else if (i & 1)
            odd = 1;
    }

    if (fail)
    {
        cout << "NO SOLUTION\n";
        return;
    }

    string ans;
    ans.resize(sz(s), ' ');

    int start = 0, end = sz(s) - 1;

    int uni = -1;

    for (int i = 0; i < 26; ++i)
    {
        if (freq[i] & 1)
            uni = i;

        for (int j = 0; j < freq[i] / 2; ++j)
        {
            ans[start++] = 'A' + i;
            ans[end--] = 'A' + i;
        }
    }

    if (uni != -1)
        ans[sz(s) / 2] = 'A' + uni;

    cout << ans << '\n';
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
