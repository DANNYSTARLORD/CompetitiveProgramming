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
    int find(vi &parent, int x)
    {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent, parent[x]);
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
    bool equationsPossible(vector<string> &equations)
    {
        vi indices;
        indices.reserve(equations.size());
        vi parent(26);
        iota(all(parent), 0);
        vi size(26, 1);

        for (int i = 0; i < equations.size(); ++i)
        {
            if (equations[i][1] == '!')
                indices.emplace_back(i);
            else
                Union(parent, size, equations[i][0] - 'a', equations[i][3] - 'a');
        }

        for (const int &i : indices)
        {
            if (find(parent, equations[i][0] - 'a') == find(parent, equations[i][3] - 'a'))
                return false;
        }
        return true;
    }
};