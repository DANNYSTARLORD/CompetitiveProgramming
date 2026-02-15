#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)x.size()
#ifdef LOCAL
#define dbg(x) cerr << #x << " = " << (x) << endl
#else
#define dbg(x)
#endif

bool check(int d, const vi &a, int x, int k)
{
    vector<pii> excluded;
    for (int pos : a)
    {
        int low = max(0, pos - d + 1);
        int high = min(x, pos + d - 1);
        if (low <= high)
            excluded.eb(low, high);
    }
    if (excluded.empty())
        return (x + 1) >= k;

    sort(all(excluded));
    vector<pii> merged;
    merged.eb(excluded[0]);
    for (int i = 1; i < sz(excluded); i++)
    {
        pii &last = merged.back();
        if (excluded[i].first <= last.second + 1)
            last.second = max(last.second, excluded[i].second);
        else
            merged.eb(excluded[i]);
    }
    ll excluded_count = 0;
    for (auto &inter : merged)
        excluded_count += (inter.second - inter.first + 1);

    ll allowed = x + 1 - excluded_count;
    return allowed >= k;
}

void solve()
{
    int n, k, x;
    cin >> n >> k >> x;
    vi a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(all(a));

    int lo = 0, hi = x;
    while (lo <= hi)
    {
        int mid = (lo + hi) / 2;
        if (check(mid, a, x, k))
            lo = mid + 1;
        else
            hi = mid - 1;
    }
    int d = hi;

    vector<pii> excluded;
    for (int pos : a)
    {
        int low = max(0, pos - d + 1);
        int high = min(x, pos + d - 1);
        if (low <= high)
            excluded.eb(low, high);
    }
    vector<pii> merged;
    if (excluded.empty())
    {
        for (int i = 0; i < k; i++)
            cout << i << " ";
        cout << "\n";
        return;
    }
    sort(all(excluded));
    merged.eb(excluded[0]);
    for (int i = 1; i < sz(excluded); i++)
    {
        pii &last = merged.back();
        if (excluded[i].first <= last.second + 1)
            last.second = max(last.second, excluded[i].second);
        else
            merged.eb(excluded[i]);
    }

    vi points;
    int cur = 0;
    for (auto &inter : merged)
    {
        for (int p = cur; p < inter.first && sz(points) < k; p++)
            points.eb(p);
        if (sz(points) >= k)
            break;
        cur = inter.second + 1;
    }
    if (sz(points) < k)
        for (int p = cur; p <= x && sz(points) < k; p++)
            points.eb(p);

    for (int i = 0; i < sz(points); i++)
        cout << points[i] << " ";
    cout << "\n";
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