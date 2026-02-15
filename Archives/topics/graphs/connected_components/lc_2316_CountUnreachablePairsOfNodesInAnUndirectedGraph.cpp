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
private:
    int find(vi &parent, int i)
    {
        if (parent[i] == i)
            return i;
        return parent[i] = find(parent, parent[i]);
    }

    void Union(vi &parent, vi &size, int x, int y)
    {
        int xParent = find(parent, x), yParent = find(parent, y);

        if (xParent == yParent)
            return;

        if (size[xParent] > size[yParent])
        {
            parent[yParent] = xParent;
            size[xParent] += size[yParent];
        }
        else
        {
            parent[xParent] = yParent;
            size[yParent] += size[xParent];
        }
    }

public:
    long long countPairs(int n, vector<vector<int>> &edges)
    {
        vi parent(n);
        iota(all(parent), 0);
        vi size(n, 1);

        for (auto &edge : edges)
        {
            if (find(parent, edge[0]) != find(parent, edge[1]))
                Union(parent, size, edge[0], edge[1]);
        }

        unordered_set<int> seen;
        seen.reserve(n);
        loop(i, 0, n) seen.emplace(find(parent, i));

        ll pairs = 0, remaining = n;

        for (auto &root : seen)
        {
            remaining -= size[root];
            pairs += size[root] * remaining;
        }
        return pairs;
    }
};