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

class Solution
{
public:
    int minimumEffortPath(vector<vector<int>> &heights)
    {
        int l = heights.size();
        int b = heights[0].size();

        vector<vi> dists(l, vi(b, INT_MAX));
        dists[0][0] = 0;

        vector<bitset<100>> processed(100);

        int dx[4] = {1, 0, -1, 0};
        int dy[4] = {0, 1, 0, -1};

        priority_queue<pair<int, pii>, vector<pair<int, pii>>, greater<pair<int, pii>>> q;

        q.emplace(0, pii(0, 0));

        while (!q.empty())
        {
            auto [dist, coord] = q.top();
            auto [x, y] = coord;
            q.pop();

            if (x == l - 1 && y == b - 1)
                return dist;

            if (processed[x][y])
                continue;
            processed[x][y] = true;

            vector<pii> coords;
            for (int i = 0; i < 4; ++i)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx >= 0 && nx < l && ny >= 0 && ny < b && processed[nx][ny] == false)
                    coords.eb(nx, ny);
            }

            for (auto &[nx, ny] : coords)
            {
                int diff = abs(heights[x][y] - heights[nx][ny]);
                int effort = max(dists[x][y], diff);
                if (effort < dists[nx][ny])
                {
                    dists[nx][ny] = effort;
                    q.emplace(effort, pii(nx, ny));
                }
            }
        }
        return dists[l - 1][b - 1];
    }
};