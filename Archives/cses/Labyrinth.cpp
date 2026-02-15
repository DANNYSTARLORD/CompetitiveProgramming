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

pii bfs(vector<string> &maze, vector<bitset<1000>> &visited, int i, int j, vector<vector<char>> &ans)
{
    visited[i][j] = true;

    queue<pii> que;
    que.emplace(i, j);

    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    bool reached = false;
    pii B;

    while (!que.empty())
    {
        auto [x, y] = que.front();
        que.pop();

        loop(dir, 0, 4)
        {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (nx < 0 || ny < 0 || nx >= maze.size() || ny >= maze[0].size())
                continue;
            if (visited[nx][ny] || maze[nx][ny] == '#')
                continue;

            visited[nx][ny] = true;
            que.emplace(nx, ny);

            if (dx[dir] == 1)
                ans[nx][ny] = 'D';
            else if (dx[dir] == -1)
                ans[nx][ny] = 'U';
            else if (dy[dir] == 1)
                ans[nx][ny] = 'R';
            else
                ans[nx][ny] = 'L';

            if (maze[nx][ny] == 'B')
            {
                reached = true;
                B = {nx, ny};
                break;
            }
        }
    }
    if (reached)
        return B;
    return {-1, -1};
}

string compute(vector<vector<char>> &ans, int x, int y)
{
    string res = "";

    while (ans[x][y] != '.')
    {
        if (ans[x][y] == 'U')
            ++x, res += 'U';
        else if (ans[x][y] == 'D')
            --x, res += 'D';
        else if (ans[x][y] == 'R')
            --y, res += 'R';
        else
            ++y, res += 'L';
    }

    reverse(all(res));
    return res;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<string> maze(n);
    loop(i, 0, n) cin >> maze[i];

    vector<bitset<1000>> visited(n);

    vector<vector<char>> ans(n, vector<char>(m, '.'));
    pii B;

    loop(i, 0, n)
    {
        loop(j, 0, m)
        {
            if (maze[i][j] == 'A')
            {
                B = bfs(maze, visited, i, j, ans);
                if (B.first != -1)
                {
                    string res = compute(ans, B.first, B.second);
                    cout << "YES\n";
                    cout << res.size() << endl;
                    cout << res << endl;
                }
                else
                    cout << "NO\n";
                return;
            }
        }
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
