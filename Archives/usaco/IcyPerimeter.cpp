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

pii bfs(int i, int j, vector<string> &grid, vector<vector<bool>> &vis)
{
    vis[i][j] = true;
    queue<pii> q;
    q.emplace(i, j);

    int dx[] = {0, 1, 0, -1};
    int dy[] = {1, 0, -1, 0};

    int area = 1; // already started with '#'
    int peri = 0;

    while (!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();

        for (int var = 0; var < 4; ++var)
        {
            int nx = x + dx[var], ny = y + dy[var];

            if (nx < 0 || ny < 0 || nx >= grid.size() || ny >= grid.size() || grid[nx][ny] == '.')
            {
                ++peri;
                continue;
            }
            if (vis[nx][ny])
                continue;
            else
                ++area, vis[nx][ny] = true, q.emplace(nx, ny);
        }
    }
    return {area, peri};
}

void solve()
{
    int n;
    cin >> n;
    vector<string> grid(n);

    for (int i = 0; i < n; ++i)
        cin >> grid[i];

    vector<vector<bool>> vis(n, vector<bool>(n));

    // area, peri
    pii ap = {0, 0};

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (grid[i][j] == '#' && !vis[i][j])
            {
                pii curr = bfs(i, j, grid, vis);

                if (curr.first > ap.first)
                    ap = curr;
                else if (curr.first == ap.first)
                    ap = (curr.second > ap.second) ? ap : curr;
            }
        }
    }
    cout << ap.first << " " << ap.second;
}

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);

    // freopen("perimeter.in", "r", stdin);
    // freopen("perimeter.out", "w", stdout);

    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}
