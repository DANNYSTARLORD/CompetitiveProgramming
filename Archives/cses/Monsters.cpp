#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template <typename T>
using v = vector<T>;
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define eb emplace_back

int row_, col_;
v<pair<int, int>> monsters;

struct Data
{
    int type = 0;       // -1 = monster, 1 = player, 0 = unvisited
    int dist = INT_MAX; // distance/time
    char prev = 0;      // previous direction
};

char figure(int x, int y, int nx, int ny)
{
    if (nx - x == 1)
        return 'D';
    if (nx - x == -1)
        return 'U';
    if (ny - y == 1)
        return 'R';
    return 'L';
}

pair<string, string> build_path(v<v<Data>> &info, int x, int y)
{
    string path;

    while (info[x][y].prev)
    {
        char ch = info[x][y].prev;
        path += ch;

        if (ch == 'D')
            --x;
        else if (ch == 'U')
            ++x;
        else if (ch == 'R')
            --y;
        else if (ch == 'L')
            ++y;
    }

    reverse(all(path));
    return {"YES", path};
}

pair<string, string> bfs(v<v<char>> &grid, v<v<Data>> &info, int n, int m)
{
    queue<tuple<int, int, int, int>> q;
    // (x, y, type, dist)

    // push all monsters FIRST
    for (auto [r, c] : monsters)
    {
        info[r][c].type = -1;
        info[r][c].dist = 0;
        q.emplace(r, c, -1, 0);
    }

    // push player
    info[row_][col_].type = 1;
    info[row_][col_].dist = 0;
    q.emplace(row_, col_, 1, 0);

    // if player starts on boundary
    if (row_ == 0 || col_ == 0 || row_ == n - 1 || col_ == m - 1)
        return {"YES", ""};

    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    while (!q.empty())
    {
        auto [x, y, type, dist] = q.front();
        q.pop();

        for (int d = 0; d < 4; ++d)
        {
            int nx = x + dx[d];
            int ny = y + dy[d];

            if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                continue;
            if (grid[nx][ny] == '#')
                continue;

            if (type == -1)
            {
                if (info[nx][ny].dist > dist + 1)
                {
                    info[nx][ny].dist = dist + 1;
                    info[nx][ny].type = -1;
                    q.emplace(nx, ny, -1, dist + 1);
                }
            }

            else
            {
                // already visited by player
                if (info[nx][ny].type == 1)
                    continue;

                // if monster reaches earlier or same time -> unsafe
                if (info[nx][ny].type == -1 &&
                    info[nx][ny].dist <= dist + 1)
                    continue;

                info[nx][ny].type = 1;
                info[nx][ny].dist = dist + 1;
                info[nx][ny].prev = figure(x, y, nx, ny);

                // if boundary -> escape
                if (nx == 0 || ny == 0 || nx == n - 1 || ny == m - 1)
                    return build_path(info, nx, ny);

                q.emplace(nx, ny, 1, dist + 1);
            }
        }
    }

    return {"NO", ""};
}

void solve()
{
    int n, m;
    cin >> n >> m;

    monsters.clear();

    v<v<char>> grid(n, v<char>(m));
    v<v<Data>> info(n, v<Data>(m));

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> grid[i][j];
            if (grid[i][j] == 'A')
                row_ = i, col_ = j;
            else if (grid[i][j] == 'M')
                monsters.eb(i, j);
        }
    }

    auto ans = bfs(grid, info, n, m);

    cout << ans.first << '\n';
    if (ans.first == "YES")
    {
        cout << sz(ans.second) << '\n';
        cout << ans.second << '\n';
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
