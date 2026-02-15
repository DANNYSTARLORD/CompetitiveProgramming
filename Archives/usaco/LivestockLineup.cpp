#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using pi = pair<int, int>;
#define endl '\n'
#define eb emplace_back
#define all(x) x.begin(), x.end()
constexpr int MOD = 1e9 + 7;
#define dbg(x) cerr << #x << " = " << x << endl

void solve()
{
    int n;
    cin >> n;

    vector<pair<string, string>> constraints;

    while (n--)
    {
        pair<string, string> con;
        string tmp;
        cin >> con.first >> tmp >> tmp >> tmp >> tmp >> con.second;

        constraints.eb(con.first, con.second);
    }

    vector<string> names = {"Bessie", "Buttercup", "Belinda", "Beatrice", "Bella", "Blue", "Betsy", "Sue"};
    sort(all(names));

    do
    {
        unordered_map<string, int> pos;
        for (int i = 0; i < 8; ++i)
            pos[names[i]] = i;

        bool found = true;
        for (auto &[a, b] : constraints)
        {
            if (abs(pos[a] - pos[b]) != 1)
            {
                found = false;
                break;
            }
        }

        if (found)
        {
            for (int i = 0; i < 8; ++i)
                cout << names[i] << endl;
            return;
        }
    } while (next_permutation(all(names)));
}

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);

    // freopen("lineup.in", "r", stdin);
    // freopen("lineup.out", "w", stdout);

    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}
