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
    void DFS(vector<vi> &graph, bitset<200> &visited, int node)
    {
        visited[node] = true;

        for (int i = 0; i < graph.size(); ++i)
        {
            if (graph[node][i] && !visited[i])
                DFS(graph, visited, i);
        }
    }

public:
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        bitset<200> visited;
        int res = 0;

        for (int i = 0; i < isConnected.size(); ++i)
        {
            if (!visited[i])
            {
                DFS(isConnected, visited, i);
                ++res;
            }
        }
        return res;
    }
};