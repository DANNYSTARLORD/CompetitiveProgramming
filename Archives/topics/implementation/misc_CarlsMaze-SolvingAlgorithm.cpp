#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using pi = pair<int, int>;
#define eb emplace_back
#define all(x) x.begin(), x.end()
#ifdef LOCAL
#define dbg(x) cerr << #x << " = " << (x) << endl
#else
#define dbg(x)
#endif
constexpr int MOD = 1e9 + 7;

char left(char c)
{
    if (c == 'L')
        return 'D';
    if (c == 'D')
        return 'R';
    if (c == 'R')
        return 'U';
    return 'L';
}

char right(char c)
{
    if (c == 'L')
        return 'U';
    if (c == 'D')
        return 'L';
    if (c == 'R')
        return 'D';
    return 'R';
}

void solve()
{
    int r, c;
    cin >> r >> c;
    int x, y;
    cin >> x >> y;
    int destX, destY;
    cin >> destX >> destY;
    --x, --y, --destX, --destY;
    vector<string> grid(r);
    for (int i = 0; i < r; ++i)
        cin >> grid[i];

    // R = 0, U = 1, L = 2, R = 3
    unordered_map<char, int> idx = {{'R', 0}, {'U', 1}, {'L', 2}, {'D', 3}};
    vector<vector<bitset<50>>> vis(r, vector<bitset<50>>(4));
    vis[x][idx['R']][y] = true;

    char dir = 'R';

    unordered_map<char, pi> mp = {{'L', {-1, 0}}, {'R', {1, 0}}, {'U', {0, -1}}, {'D', {0, 1}}};

    while (true)
    {
        char l = left(dir);
        auto [lx, ly] = mp[l];
        int nx = x + lx, ny = y + ly;

        if (nx >= 0 && nx < r && ny >= 0 && y < c && grid[nx][ny] == '0')
        {
            if (vis[nx][idx[l]][ny])
            {
                cout << 0;
                return;
            }
            if (nx == destX && ny == destY)
            {
                cout << 1;
                return;
            }
            dir = l;
            x = nx, y = ny;
            vis[nx][idx[l]][ny] = true;
            continue;
        }

        auto [dx, dy] = mp[dir];
        nx = x + dx, ny = y + dy;

        if (nx >= 0 && nx < r && ny >= 0 && y < c && grid[nx][ny] == '0')
        {
            if (vis[nx][idx[dir]][ny])
            {
                cout << 0;
                return;
            }
            if (nx == destX && ny == destY)
            {
                cout << 1;
                return;
            }
            x = nx, y = ny;
            vis[nx][idx[dir]][ny] = true;
            continue;
        }

        dir = right(dir);

        if (vis[x][idx[dir]][y])
        {
            cout << 0;
            return;
        }
        vis[x][idx[dir]][y] = true;
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