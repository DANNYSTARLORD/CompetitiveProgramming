#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template <typename T>
using v = vector<T>;
template <typename A, typename B>
using p = pair<A, B>;
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define loop(i, s, e) for (int i = (s); i < (e); ++i)
#ifdef LOCAL
#define dbg(x) cerr << #x << " = " << (x) << endl
#else
#define dbg(x)
#endif

void solve()
{
    int n;
    cin >> n;
    v<int> nums(n);
    loop(i, 0, n) cin >> nums[i];

    stack<p<int, int>> st;

    v<int> ans(n, -1);

    loop(i, 0, n)
    {
        while (!st.empty())
        {
            auto [val, idx] = st.top();
            if (val < nums[i])
            {
                ans[i] = idx;
                break;
            }
            st.pop();
        }
        st.emplace(nums[i], i);
    }

    for (int &num : ans)
        cout << num + 1 << " ";
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
