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

void dfs(vector<string> &building, vector<bitset<1000>> &visited, int i, int j)
{
    if (i < 0 || j < 0 || i >= building.size() || j >= building[0].size())
        return;

    visited[i][j] = true;

    if (building[i][j] == '#' || visited[i][j])
        return;

    dfs(building, visited, i + 1, j);
    dfs(building, visited, i - 1, j);
    dfs(building, visited, i, j + 1);
    dfs(building, visited, i, j - 1);
}

void bfs(vector<string> &building, vector<bitset<1000>> &visited, int i, int j)
{
    queue<pii> que;
    que.emplace(i, j);
    visited[i][j] = true;

    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    while (!que.empty())
    {
        auto [x, y] = que.front();
        que.pop();

        loop(dir, 0, 4)
        {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (nx < 0 || ny < 0 || nx >= building.size() || ny >= building[0].size())
                continue;
            if (visited[nx][ny] || building[nx][ny] == '#')
                continue;

            visited[nx][ny] = true;
            que.emplace(nx, ny);
        }
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<string> building(n);
    loop(i, 0, n) cin >> building[i];
    vector<bitset<1000>> visited(n);

    int rooms = 0;

    loop(i, 0, n)
    {
        loop(j, 0, m)
        {
            if (!visited[i][j] && building[i][j] == '.')
            {
                bfs(building, visited, i, j);
                ++rooms;
            }
        }
    }
    cout << rooms << endl;
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
