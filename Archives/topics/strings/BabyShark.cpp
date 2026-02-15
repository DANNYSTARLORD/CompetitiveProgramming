#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template <typename T>
using vc = vector<T>;
template <typename A, typename B>
using pr = pair<A, B>;
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define sz(x) ssize(x)
#define rep(i, s, e) for (int i = s; i < e; ++i)
#ifdef LOCAL
#define dbg(x) cerr << #x << " = " << (x) << endl
#else
#define dbg(x)
#endif

void solve()
{
    string line;
    getline(cin, line);

    string prev, curr, ans;
    int currFreq = 0, maxFreq = 0;

    auto update = [&](string &word, int freq)
    {
        if (freq > maxFreq)
        {
            maxFreq = freq;
            ans = word;
        }
    };

    for (char &ch : line)
    {
        if (ch == ' ')
        {
            if (curr == prev)
            {
                ++currFreq;
            }
            else
            {
                if (!prev.empty())
                    update(prev, currFreq);
                prev = curr;
                currFreq = 1;
            }
            curr = "";
        }
        else
            curr += ch;
    }

    if (curr == prev)
        ++currFreq;
    else
    {
        if (!prev.empty())
            update(prev, currFreq);
        prev = curr;
        currFreq = 1;
    }

    update(prev, currFreq);

    cout << ans;
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
