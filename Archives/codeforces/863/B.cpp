#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;
#define endl '\n'
#define eb emplace_back
#define all(x) x.begin(), x.end()
const int MOD = 1e9 + 7;
#define dbg(x) cerr << #x << " = " << x << endl
#define loop(i, start, end) for (int i = start; i < end; ++i)

void solve()
{
    int n;
    cin >> n;
    vi input(n << 1);
    loop(i, 0, n << 1) cin >> input[i];
    sort(all(input));

    vi weights;
    weights.reserve(n << 1);
    weights.eb(input[0]);

    // drop same weights
    loop(i, 1, n << 1)
    {
        if (weights.back() == input[i])
            weights.pop_back();
        else
            weights.eb(input[i]);
    }
    input.clear();

    int minINS = INT_MAX;

    loop(i, 0, weights.size())
    {
        loop(j, i + 1, weights.size())
        {
            vi take;
            take.reserve(n << 2);
            loop(k, 0, weights.size())
            {
                if (i == k || j == k)
                    continue;
                take.eb(weights[k]);
            }

            int ins = 0;
            for (int k = 0; k + 1 < take.size(); k += 2)
                ins += take[k + 1] - take[k];

            minINS = min(ins, minINS);
        }
    }

    cout << minINS << endl;
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
