#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using pi = pair<int, int>;
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#ifdef LOCAL
#define dbg(x) cerr << #x << " = " << (x) << endl
#else
#define dbg(x)
#endif
constexpr int MOD = 1e9 + 7;

void solve()
{
    unordered_map<string, int> milk = {{"Bessie", 0}, {"Elsie", 0}, {"Daisy", 0}, {"Gertie", 0}, {"Annabelle", 0}, {"Maggie", 0}, {"Henrietta", 0}};

    int n;
    cin >> n;
    while (n--)
    {
        string name;
        int num;
        cin >> name >> num;
        milk[name] += num;
    }

    vector<pair<string, int>> vec(all(milk));
    sort(all(vec), [](pair<string, int> &a, pair<string, int> &b)
         { return a.second < b.second; });

    int i;
    int small = vec[0].second, secSmall = INT_MAX;

    for (i = 1; i < 7; ++i)
    {
        dbg(vec[i].first);
        if (small == vec[i].second)
            continue;
        else if (secSmall == INT_MAX)
            secSmall = vec[i].second;
        else if (secSmall == vec[i].second)
        {
            cout << "Tie\n";
            return;
        }
        else
            break;
    }
    if (secSmall != INT_MAX)
        cout << vec[--i].first << '\n';
    else
        cout << "Tie\n";
}

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);

    // freopen("notlast.in", "r", stdin);
    // freopen("notlast.out", "w", stdout);

    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}
