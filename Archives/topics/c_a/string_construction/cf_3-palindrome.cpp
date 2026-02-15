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

    string algo;

    for (int i = 0; i < n; ++i)
    {
        if (algo.size() == 2)
        {
            char p = (algo[0] == 'a') ? 'b' : 'a';
            cout << p;

            algo = string(1, algo[1]) + p;
        }
        else
        {
            algo += 'b';
            cout << 'b';
        }
    }

    cout << endl;
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
