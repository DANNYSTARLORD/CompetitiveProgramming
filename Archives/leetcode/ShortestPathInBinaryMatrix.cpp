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
    int shortestPathBinaryMatrix(vector<vector<int>> &grid)
    {
        if (grid[0][0] == 1)
            return -1;

        int dir[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

        queue<pair<pi, int>> que;
        que.push({{0, 0}, 1});

        vector<bitset<100>> visited(100);

        while (!que.empty())
        {
            auto [pos, steps] = que.front();
            auto [a, b] = pos;
            que.pop();

            if (a + 1 == grid.size() && b + 1 == grid.size())
                return steps;

            for (int i = 0; i < 8; ++i)
            {
                int x = a + dir[i][0];
                int y = b + dir[i][1];

                if (x >= grid.size() || x < 0 || y >= grid.size() || y < 0 || grid[x][y] == 1)
                    continue;

                if (visited[x][y] == true)
                    continue;

                visited[x][y] = true;

                que.push({{x, y}, steps + 1});
            }
        }
        return -1;
    }
};