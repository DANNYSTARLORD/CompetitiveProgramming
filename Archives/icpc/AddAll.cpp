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
    priority_queue<int, vi, greater<int>> nums;
    loop(i, 0, n)
    {
        int num;
        cin >> num;
        nums.emplace(num);
    }

    ll cost = 0;

    while (nums.size() >= 2)
    {
        int merge = nums.top();
        nums.pop();
        merge += nums.top();
        nums.pop();

        cost += merge;

        nums.emplace(merge);
    }

    cout << cost << endl;
}

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);

    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
