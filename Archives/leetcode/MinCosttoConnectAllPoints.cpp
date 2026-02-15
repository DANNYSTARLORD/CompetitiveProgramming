#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define sz(x) ssize(x)
#define loop(i, start, end) for (int i = start; i < end; ++i)

class Solution
{
private:
    int manhattan(vi &a, vi &b)
    {
        return abs(a[0] - b[0]) + abs(a[1] - b[1]);
    }

public:
    int minCostConnectPoints(vector<vector<int>> &points)
    {
        vector<vector<pii>> adj(sz(points));

        loop(i, 0, sz(points)) loop(j, i + 1, sz(points))
        {
            adj[i].eb(j, manhattan(points[i], points[j]));
            adj[j].eb(i, manhattan(points[i], points[j]));
        }

        bitset<1000> vis;
        // {wt, curr}
        priority_queue<pii, vector<pii>, greater<pii>> pq;

        pq.emplace(0, 0);
        ll ans = 0;

        while (!pq.empty())
        {
            auto [wt, curr] = pq.top();
            pq.pop();

            if (vis[curr])
                continue;

            vis[curr] = 1;
            ans += wt;

            for (auto [dest, cost] : adj[curr])
            {
                if (vis[dest])
                    continue;
                pq.emplace(cost, dest);
            }
        }
        return ans;
    }
};