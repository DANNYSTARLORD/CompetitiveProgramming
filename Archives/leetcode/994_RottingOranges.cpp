#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)x.size()

class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        // 0 = empty, 1 = fresh, 2 = rotten
        queue<pii> coords;
        int fresh = 0;

        for (int i = 0; i < sz(grid); ++i)
        {
            for (int j = 0; j < sz(grid[i]); ++j)
            {
                if (grid[i][j] == 2)
                    coords.emplace(i, j);
                else if (grid[i][j] == 1)
                    ++fresh;
            }
        }
        if (!fresh)
            return 0;
        if (coords.empty())
            return -1;

        int time = -1;

        int dx[] = {1, 0, -1, 0};
        int dy[] = {0, 1, 0, -1};

        while (!coords.empty())
        {
            int n = sz(coords);
            while (n--)
            {
                auto [x, y] = coords.front();
                coords.pop();

                for (int dir = 0; dir < 4; ++dir)
                {
                    int nx = x + dx[dir], ny = y + dy[dir];

                    if (nx < 0 || nx >= sz(grid) || ny < 0 || ny >= sz(grid[0]) || grid[nx][ny] != 1)
                        continue;

                    grid[nx][ny] = 2; // rotten now
                    --fresh;
                    coords.emplace(nx, ny);
                }
            }
            ++time;
        }

        if (fresh)
            return -1;
        return time;
    }
};
