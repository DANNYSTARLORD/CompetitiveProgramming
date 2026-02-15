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
    int A, B, C, D;
    cin >> A >> B >> C >> D;

    int g = gcd(A, B);
    if (D % g != 0)
    {
        cout << "No solution.\n";
        return;
    }

    int b_min = ceil(C / (B * 1.0));
    int b_max = b_min + ceil(B / (g * 1.0));
    int bestT = INT_MAX, bestB;

    loop(b, b_min, b_max)
    {
        if ((D + B * b) % A != 0)
            continue;

        int t = (D + B * b) / A;

        if (t >= 0 && B * b >= C && t < bestT)
        {
            bestT = t;
            bestB = b;
        }
    }

    cout << "We need " << bestT << " truck" << (bestT != 1 ? "s" : "")
         << " and " << bestB << " boat" << (bestB != 1 ? "s." : ".");
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
