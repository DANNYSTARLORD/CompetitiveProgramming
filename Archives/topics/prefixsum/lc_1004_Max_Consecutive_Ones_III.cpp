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
    struct Data
    {
        int ones = 0, zeroes = 0;
    };

public:
    int longestOnes(vector<int> &nums, int k)
    {
        v<Data> prefix_arr(sz(nums) + 1);

        for (int i = 1; i < sz(prefix_arr); ++i)
        {
            prefix_arr[i].ones += prefix_arr[i - 1].ones + ((nums[i - 1] == 1) ? 1 : 0);
            prefix_arr[i].zeroes += prefix_arr[i - 1].zeroes + ((nums[i - 1] == 0) ? 1 : 0);
        }

        int lo = 0, ans = 0;

        for (int hi = 1; hi < sz(prefix_arr); ++hi)
        {
            int ones = prefix_arr[hi].ones - prefix_arr[lo].ones;
            int zeroes = prefix_arr[hi].zeroes - prefix_arr[lo].zeroes;

            cout << ones << " " << zeroes << '\n';

            if (zeroes > k)
                ++lo;
            else
                ans = max(ones + zeroes, ans);
        }
        return ans;
    }
};