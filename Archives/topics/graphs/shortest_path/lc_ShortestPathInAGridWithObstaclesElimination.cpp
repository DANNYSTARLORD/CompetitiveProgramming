#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using pi = pair<int, int>;
#define endl '\n'
#define eb emplace_back
#define all(x) x.begin(), x.end()
constexpr int MOD = 1e9 + 7;
#define dbg(x) cerr << #x << " = " << x << endl

class Solution
{
public:
    int shortestPath(vector<vector<int>> &grid, int k)
    {
        int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        vector<vector<bitset<1601>>> visited(41, vector<bitset<1601>>(41));

        // (x, y), (obs, steps)
        queue<pair<pi, pi>> q;
        q.emplace(pi{0, 0}, pi{k, 0});
        visited[0][0][k] = true;

        while (!q.empty())
        {
            auto [pos, state] = q.front();
            auto [a, b] = pos;
            auto [obs, steps] = state;
            q.pop();

            if (a + 1 == grid.size() && b + 1 == grid[0].size())
                return steps;

            for (int i = 0; i < 4; ++i)
            {
                int x = a + dir[i][0];
                int y = b + dir[i][1];

                if (x >= grid.size() || x < 0 || y >= grid[0].size() || y < 0)
                    continue;

                if (grid[x][y] == 1 && obs > 0 && !visited[x][y][obs - 1])
                {
                    q.emplace(pi{x, y}, pi{obs - 1, steps + 1});
                    visited[x][y][obs - 1] = true;
                }
                else if (grid[x][y] == 0 && !visited[x][y][obs])
                {
                    q.emplace(pi{x, y}, pi{obs, steps + 1});
                    visited[x][y][obs] = true;
                }
            }
        }
        return -1;
    }
};