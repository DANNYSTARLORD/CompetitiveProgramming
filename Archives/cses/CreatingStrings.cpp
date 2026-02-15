#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;
#define endl '\n'
#define eb emplace_back
#define all(x) x.begin(), x.end()
const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1e9 + 7;
#define dbg(x) cerr << #x << " = " << x << endl

void permute(string s, string curr, bitset<8> &used, vector<string> &permutations)
{
    if (curr.size() == s.size())
    {
        permutations.eb(curr);
        return;
    }

    for (int i = 0; i < s.size(); ++i)
    {

        if (used[i] || i > 0 && !used[i] && s[i - 1] == s[i] && !used[i - 1])
            continue;

        used[i] = true;
        curr += s[i];

        permute(s, curr, used, permutations);

        curr.pop_back();
        used[i] = false;
    }
}

void solve()
{
    string s;
    cin >> s;
    sort(all(s));
    vector<string> permutations;
    permutations.reserve(40320);

    bitset<8> used;

    permute(s, "", used, permutations);

    cout << permutations.size() << endl;
    for (const auto &st : permutations)
        cout << st << endl;
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
