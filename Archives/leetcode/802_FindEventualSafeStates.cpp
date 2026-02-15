#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template <typename T>
using v = vector<T>;
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()

class Solution
{
public:
    v<int> eventualSafeNodes(vector<v<int>> &graph)
    {
        int n = graph.size();
        v<v<int>> rev(n);
        v<int> outdeg(n, 0);

        for (int u = 0; u < n; ++u)
        {
            outdeg[u] = graph[u].size();
            for (int v : graph[u])
            {
                rev[v].eb(u);
            }
        }

        queue<int> q;
        for (int i = 0; i < n; ++i)
        {
            if (outdeg[i] == 0)
                q.push(i);
        }

        vector<bool> safe(n, false);

        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            safe[u] = true;
            for (int p : rev[u])
            {
                if (--outdeg[p] == 0)
                    q.push(p);
            }
        }

        v<int> ans;
        for (int i = 0; i < n; ++i)
        {
            if (safe[i])
                ans.eb(i);
        }
        return ans;
    }
};