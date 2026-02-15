#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;
#define eb emplace_back
#pragma GCC optimization("Ofast,unroll-loops") // lmao cheese
#define all(x) (x).begin(), (x).end()
#ifdef LOCAL
#define dbg(x) cerr << #x << " = " << (x) << endl
#else
#define dbg(x)
#endif

int whichBound(vector<pii> &bounds, int index)
{
    for (int i = bounds.size() - 1; i >= 0; --i)
    {
        if (bounds[i].first <= index)
            return i;
    }
    return 0;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<pair<int, short>> music(n);
    for (int i = 0; i < n; ++i)
        cin >> music[i].first;
    vector<pair<int, short>> mark(m);
    unordered_map<string, short> mp = {{"ppp", 1}, {"pp", 2}, {"p", 3}, {"mp", 4}, {"mf", 5}, {"f", 6}, {"ff", 7}, {"fff", 8}};

    for (int i = 0; i < m; ++i)
    {
        cin >> mark[i].first;
        string note;
        cin >> note;
        --mark[i].first;
        mark[i].second = mp[note];
    }

    for (int i = 0; i < m; ++i)
    {
        if (i == m - 1)
        {
            for (int j = mark[i].first; j < n; ++j)
                music[j].second = mark[i].second;
            break;
        }
        for (int j = mark[i].first; j < mark[i + 1].first; ++j)
        {
            music[j].second = mark[i].second;
        }
    }

    sort(all(music), [](const pair<int, short> &a, const pair<int, short> &b)
         {
             if (a.second != b.second) return a.second < b.second;
             return a.first < b.first; });

    vector<pii> bounds;

    int prev = 0;
    short p = music[0].second;

    for (int i = 1; i < n; ++i)
    {
        if (music[i].second != p)
        {
            bounds.eb(prev, i - 1);
            prev = i;
            p = music[i].second;
        }
    }

    bounds.eb(prev, n - 1);

    if (bounds.size() <= 1)
    {
        cout << 0;
        return;
    }

    ll ans = 0;

    // optional optimization
    vector<vector<bool>> cache(n, vector<bool>(bounds.size(), true));

    for (int i = bounds[1].first; i < n; ++i)
    {
        int index = whichBound(bounds, i);

        for (int j = 0; j < index; ++j)
        {
            // optional optimization
            if (i != bounds[index].first && cache[i - 1][j])
                continue;

            auto g = lower_bound(music.begin() + bounds[j].first, music.begin() + bounds[j].second + 1, music[i].first,
                                 [](const pair<int, short> &a, int val)
                                 {
                                     return a.first < val;
                                 });
            if (g == music.begin() + bounds[j].second + 1)
                continue;

            ans += distance(g, music.begin() + bounds[j].second + 1);
            cache[i][j] = false;
        }
    }
    cout << ans;
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