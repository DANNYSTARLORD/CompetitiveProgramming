#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define loop(i, s, e) for (int i = (s); i < (e); ++i)

class Solution
{
public:
    int maxPathScore(vector<vector<int>> &grid, int k)
    {
        int n = sz(grid), m = sz(grid[0]);
        vector<vvi> dp(n, vvi(m, vi(k + 1, -1)));

        int cost[] = {0, 1, 1};
        dp[0][0][0] = 0;

        loop(i, 0, n)
        {
            loop(j, 0, m)
            {
                loop(c, 0, k + 1)
                {
                    if (dp[i][j][c] == -1)
                        continue;

                    // moving right
                    if (j + 1 < m)
                    {
                        int newCost = c + cost[grid[i][j + 1]];
                        if (newCost <= k)
                            dp[i][j + 1][newCost] = max(dp[i][j][c] + grid[i][j + 1], dp[i][j + 1][newCost]);
                    }

                    // moving down
                    if (i + 1 < n)
                    {
                        int newCost = c + cost[grid[i + 1][j]];
                        if (newCost <= k)
                            dp[i + 1][j][newCost] = max(dp[i][j][c] + grid[i + 1][j], dp[i + 1][j][newCost]);
                    }
                }
            }
        }

        int best = -1;
        loop(c, 0, k + 1)
            best = max(dp[n - 1][m - 1][c], best);

        return best;
    }
};