#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template <typename T>
using v = vector<T>;
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define eb emplace_back
#ifdef LOCAL
#define dbg(x) cerr << #x << " = " << (x) << endl
#else
#define dbg(x)
#endif

struct Info
{
    int arrival, departure, idx;
};

void solve()
{
    int n;
    cin >> n;

    v<Info> ppl(n);
    for (int i = 0; i < n; i++)
    {
        cin >> ppl[i].arrival >> ppl[i].departure;
        ppl[i].idx = i;
    }

    sort(all(ppl), [](const auto &a, const auto &b)
         { return a.arrival < b.arrival; });

    // departure, room
    priority_queue<pair<int, int>, v<pair<int, int>>, greater<>> q;

    v<int> ans(n);
    int rooms = 0;

    for (auto &p : ppl)
    {
        if (!q.empty() && q.top().first < p.arrival)
        {
            auto [dep, room] = q.top();
            q.pop();
            ans[p.idx] = room;
            q.emplace(p.departure, room);
        }
        else
        {
            ans[p.idx] = ++rooms;
            q.emplace(p.departure, rooms);
        }
    }

    cout << rooms << '\n';
    for (int x : ans)
        cout << x << " ";
}

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);

    int t = 1;
    // cin >> t;
    while (t--)
        solve();
}