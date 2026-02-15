#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define sz(x) ssize(x)
#define loop(i, start, end) for (int i = start; i < end; ++i)
#ifdef LOCAL
#define dbg(x) cerr << #x << " = " << (x) << endl
#else
#define dbg(x)
#endif

struct pair_hash
{
    template <class TFirst, class TSecond>
    size_t operator()(const pair<TFirst, TSecond> &p) const noexcept
    {
        return hash<TFirst>{}(p.first) * 31 + hash<TSecond>{}(p.second);
    }
};

constexpr int UB = 1e9;

unordered_map<int, vector<pii>> ftchk;

int bfs(int sx, int sy, int destx, int desty)
{
    queue<pii> q;
    q.emplace(sx, sy);
    unordered_set<pii, pair_hash> vis;
    vis.emplace(sx, sy);

    int dx[] = {1, -1, 0, 0, 1, 1, -1, -1};
    int dy[] = {0, 0, 1, -1, 1, -1, 1, -1};

    int steps = 1;

    while (!q.empty())
    {
        int n = q.size();
        while (n--)
        {
            auto [x, y] = q.front();
            q.pop();

            for (int dir = 0; dir < 8; ++dir)
            {
                int nx = x + dx[dir];
                int ny = y + dy[dir];

                if (nx < 1 || nx > UB || ny < 1 || ny > UB)
                    continue;
                if (nx == destx && ny == desty)
                    return steps;

                if (ftchk.find(nx) == ftchk.end())
                    continue;

                for (auto &[a, b] : ftchk[nx])
                {
                    if (ny >= a && ny <= b && !vis.count({nx, ny}))
                    {
                        vis.emplace(nx, ny);
                        q.emplace(nx, ny);
                        break;
                    }
                }
            }
        }
        ++steps;
    }
    return -1;
}

void solve()
{
    int sx, sy, destx, desty;
    cin >> sx >> sy >> destx >> desty;
    int n;
    cin >> n;

    while (n--)
    {
        int r, a, b;
        cin >> r >> a >> b;

        auto &v = ftchk[r];
        v.eb(a, b);
        sort(all(v));
        vector<pii> merged;

        for (auto &p : v)
        {
            if (merged.empty() || merged.back().second < p.first - 1)
                merged.eb(p);
            else
                merged.back().second = max(merged.back().second, p.second);
        }
        v.swap(merged);
    }

    cout << bfs(sx, sy, destx, desty);
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