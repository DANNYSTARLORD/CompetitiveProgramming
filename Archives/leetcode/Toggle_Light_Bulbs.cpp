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
    vector<int> toggleLightBulbs(vector<int> &bulbs)
    {
        set<int> on;
        bitset<101> toggle;
        for (int &bulb : bulbs)
        {
            if (toggle[bulb])
            {
                on.erase(bulb);
                toggle[bulb] = 0;
            }
            else
            {
                on.emplace(bulb);
                toggle[bulb] = 1;
            }
        }

        v<int> ans(all(on));
        return ans;
    }
};