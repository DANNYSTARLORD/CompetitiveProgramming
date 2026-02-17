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
    double findMaxAverage(vector<int> &nums, int k)
    {
        v<ll> prefix_sum(sz(nums) + 1);
        for (int i = 1; i < sz(prefix_sum); ++i)
            prefix_sum[i] += prefix_sum[i - 1] + nums[i - 1];

        double avg = -DBL_MAX;

        for (int i = 0, j = k; j <= sz(nums); ++i, ++j)
            avg = max((prefix_sum[j] - prefix_sum[i]) / (k * 1.0), avg);

        return avg;
    }
};