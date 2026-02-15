#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#ifdef LOCAL
#define dbg(x) cerr << #x << " = " << (x) << endl
#else
#define dbg(x)
#endif

void solve()
{
    int low = 1, high = 1e9;

    while (low <= high)
    {
        int mid = midpoint(low, high);
        cout << "? " << mid << endl;

        string res;
        cin >> res;

        if (res == "YES")
            low = mid + 1;
        else
            high = mid - 1;
    }
    cout << "! " << low << endl;
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
