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
public:
    int minimumDistance(vector<int> &nums)
    {
        unordered_map<int, vi> indices;

        loop(i, 0, sz(nums)) indices[nums[i]].eb(i);

        int minDis = INT_MAX;

        for (auto &[val, pos] : indices)
        {
            if (sz(pos) < 3)
                continue;

            sort(all(pos));

            for (int i = 0; i <= sz(pos) - 3; ++i)
            {
                int range = pos[i + 2] - pos[i];
                minDis = min(minDis, 2 * range);
            }
        }

        return minDis == INT_MAX ? -1 : minDis;
    }
};