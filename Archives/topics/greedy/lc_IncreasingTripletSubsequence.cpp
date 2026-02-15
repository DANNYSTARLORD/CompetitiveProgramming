#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)x.size()
#define loop(i, start, end) for (int i = start; i < end; ++i)

class Solution
{
public:
    bool increasingTriplet(vector<int> &nums)
    {
        ll mn = LLONG_MAX, cache = LLONG_MAX;

        for (int &num : nums)
        {
            if (num <= mn)
                mn = num;
            else if (num <= cache)
                cache = num;
            else
                return true;
        }

        return false;
    }
};