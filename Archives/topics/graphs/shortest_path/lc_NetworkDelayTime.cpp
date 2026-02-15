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

class Solution
{
public:
    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {
        vector<vector<pii>> adj(n);
        for (auto &edge : times)
            adj[--edge[0]].eb(--edge[1], edge[2]);

        vi dist(n, INT_MAX);
        dist[--k] = 0;

        priority_queue<pii, vector<pii>, greater<>> pq;
        pq.emplace(0, k);

        while (!pq.empty())
        {
            auto [cd, u] = pq.top();
            pq.pop();

            if (cd != dist[u])
                continue;

            for (auto &edge : adj[u])
            {
                auto [v, w] = edge;
                if (dist[u] + w < dist[v])
                {
                    dist[v] = dist[u] + w;
                    pq.emplace(dist[v], v);
                }
            }
        }

        int ans = *max_element(all(dist));
        if (ans == INT_MAX)
            return -1;
        return ans;
    }
};