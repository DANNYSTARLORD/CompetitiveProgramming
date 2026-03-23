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
    int firstUniqueFreq(vector<int> &nums)
    {
        unordered_map<int, int> freq;
        freq.reserve(sz(nums) + sz(nums) >> 2);

        for (int &num : nums)
            ++freq[num];

        unordered_map<int, int> freqCount;
        freqCount.reserve(sz(nums) + sz(nums) >> 2);

        for (auto &[key, val] : freq)
            ++freqCount[val];

        for (int &num : nums)
        {
            if (freqCount[freq[num]] == 1)
                return num;
        }
        return -1;
    }
};