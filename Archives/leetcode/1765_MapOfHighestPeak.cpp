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
    vector<vector<int>> highestPeak(vector<vector<int>> &isWater)
    {
        vector<bitset<1000>> vis(sz(isWater));
        vector<vi> ans(sz(isWater), vi(sz(isWater[0])));
        queue<pii> q;

        for (int i = 0; i < sz(isWater); ++i)
        {
            for (int j = 0; j < sz(isWater[i]); ++j)
            {
                if (isWater[i][j])
                {
                    q.emplace(i, j);
                    vis[i][j] = 1;
                }
            }
        }

        int dx[] = {1, 0, -1, 0};
        int dy[] = {0, 1, 0, -1};

        while (!q.empty())
        {
            int n = sz(q);
            while (n--)
            {
                auto [x, y] = q.front();
                q.pop();

                for (int dir = 0; dir < 4; ++dir)
                {
                    int nx = x + dx[dir], ny = y + dy[dir];

                    if(nx < 0 || nx >= sz(isWater) || ny < 0 || ny >= sz(isWater[0]) || vis[nx][ny]) continue;

                    q.emplace(nx, ny);
                    vis[nx][ny] = 1;
                    ans[nx][ny] = ans[x][y] + 1;
                }
            }
        }
        return ans;
    }
};