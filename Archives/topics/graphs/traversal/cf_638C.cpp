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

inline long long mark(int a, int b)
{
    if (a > b)
        swap(a, b);
    return ((long long)a << 32) | (unsigned int)b;
}

int n;
vector<vi> adj;
// hashing roads
unordered_map<long long, int> roads;
// are you taken on that day?
vector<unordered_set<int>> taken;
// which roads are you fixing on this day?
vector<vi> days;
int max_deg;

void dfs(int par, int node, int used_day = -1)
{
    int day = 0;
    for (int nei : adj[node])
    {
        if (nei == par)
            continue;

        while (taken[node].count(day) || taken[nei].count(day) || day == used_day)
            ++day;
        taken[node].insert(day);
        taken[nei].insert(day);
        days[day].eb(roads[mark(node, nei)]);
        dfs(node, nei, day);
        ++day;
    }
}

void solve()
{
    cin >> n;
    adj.assign(n, {});
    max_deg = 0;
    for (int i = 1; i < n; ++i)
    {
        int a, b;
        cin >> a >> b;
        --a, --b;
        roads[mark(a, b)] = i;
        adj[a].eb(b);
        adj[b].eb(a);
        max_deg = max({max_deg, sz(adj[a]), sz(adj[b])});
    }
    taken.assign(n, {});
    days.assign(max_deg, {});

    dfs(-1, 0);

    cout << max_deg << '\n';
    for (int i = 0; i < max_deg; ++i)
    {
        cout << sz(days[i]) << " ";
        for (int j = 0; j < sz(days[i]); ++j)
        {
            if (j)
                cout << " ";
            cout << days[i][j];
        }
        cout << '\n';
    }
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