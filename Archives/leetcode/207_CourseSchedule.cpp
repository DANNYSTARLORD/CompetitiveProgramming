#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;
#define endl '\n'
#define eb emplace_back
#define all(x) x.begin(), x.end()
const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1e9 + 7;
#define dbg(x) cerr << #x << " = " << x << endl
#define loop(n) for (int i = 0; i < n; ++i)

class Solution
{
private:
    bool DFS(vector<vi> &adj, bitset<2000> &visited, bitset<2000> &rec, int node)
    {
        visited[node] = true;
        rec[node] = true;

        for (const int &nei : adj[node])
        {
            if (rec[nei])
                return true;

            if (!visited[nei])
            {
                if (DFS(adj, visited, rec, nei))
                    return true;
            }
        }

        rec[node] = false;
        return false;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<vi> adj(numCourses);
        vi indegree(numCourses);

        for (int i = 0; i < prerequisites.size(); ++i)
        {
            adj[prerequisites[i][1]].emplace_back(prerequisites[i][0]);
            ++indegree[prerequisites[i][0]];
        }

        queue<int> topo;

        for (int i = 0; i < numCourses; ++i)
        {
            if (indegree[i] == 0)
                topo.emplace(i);
        }

        int courses = 0;

        while (!topo.empty())
        {
            int node = topo.front();
            topo.pop();
            ++courses;

            for (const int &nei : adj[node])
            {
                if (--indegree[nei] == 0)
                    topo.emplace(nei);
            }
        }

        return courses == numCourses;
    }
};