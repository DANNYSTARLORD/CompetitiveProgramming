#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;
using ldouble = long double;
#define endl '\n'
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define loop1(i, n) for (int i = 0; i < n; ++i)
#define loop2(i, a, b) for (int i = a; i < b; ++i)
#define GET_MACRO(_1, _2, _3, NAME, ...) NAME
#define loop(...) GET_MACRO(__VA_ARGS__, loop2, loop1)(__VA_ARGS__)

void perm(string &s, string curr, vector<string> &perms, vector<int> &freq)
{
    if (s.size() == curr.size())
    {
        perms.eb(curr);
        return;
    }

    loop(i, 26)
    {
        if (freq[i] > 0)
        {
            --freq[i];
            perm(s, curr + char(i + 'a'), perms, freq);
            ++freq[i];
        }
    }
}

void solve()
{
    string s;
    cin >> s;

    vector<int> freq(26, 0);
    for (const char &c : s)
        ++freq[c - 'a'];

    vector<string> perms;
    perms.reserve(40320);

    perm(s, "", perms, freq);

    cout << perms.size() << endl;
    for (const string &str : perms)
        cout << str << endl;
}

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    // int t;
    // cin >> t;
    // while (t--)
    solve();
    return 0;
}