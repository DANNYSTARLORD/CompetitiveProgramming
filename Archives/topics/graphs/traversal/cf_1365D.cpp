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

bool addWalls(vector<string> &grid, int x, int y)
{
    int dx[] = {0, 1, 0, -1};
    int dy[] = {1, 0, -1, 0};

    for (int i = 0; i < 4; ++i)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= sz(grid) || nx < 0 || ny >= sz(grid[0]) || ny < 0)
            continue;

        if (grid[nx][ny] == 'B')
            continue;

        if (grid[nx][ny] == 'G')
            return false;

        grid[nx][ny] = '#';
    }
    return true;
}

void bfs(vector<string> &grid, vector<vector<bool>> &vis, int i, int j)
{
    int dx[] = {0, 1, 0, -1};
    int dy[] = {1, 0, -1, 0};

    queue<pii> q;

    q.emplace(i, j);

    while (!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();

        for (int i = 0; i < 4; ++i)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= sz(grid) || nx < 0 || ny >= sz(grid[0]) || ny < 0)
                continue;

            if (vis[nx][ny] || grid[nx][ny] == '#')
                continue;

            vis[nx][ny] = 1;
            q.emplace(nx, ny);
        }
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<string> grid(n);
    for (int i = 0; i < n; ++i)
        cin >> grid[i];

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (grid[i][j] == 'B')
            {
                if (!addWalls(grid, i, j))
                {
                    cout << "No\n";
                    return;
                }
            }
        }
    }
    vector<vector<bool>> vis(n, vector<bool>(m));
    if (grid[n - 1][m - 1] != '#')
        bfs(grid, vis, n - 1, m - 1);

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (grid[i][j] == 'G' && !vis[i][j])
            {
                cout << "No\n";
                return;
            }
            if (grid[i][j] == 'B' && vis[i][j])
            {
                cout << "No\n";
                return;
            }
        }
    }

    cout << "Yes\n";
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
