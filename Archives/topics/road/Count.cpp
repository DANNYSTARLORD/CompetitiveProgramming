#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template <typename T>
using v = vector<T>;
template <typename A, typename B>
using p = pair<A, B>;
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define rep(i, s, e) for (int i = (s); i < (e); ++i)

class Solution
{
public:
    int countCollisions(string directions)
    {
        stack<char> dir;
        int res = 0;

        for (char &ch : directions)
        {
            if (ch == 'R' || dir.empty())
                dir.push(ch);
            else if (ch == 'S')
            {
                while (!dir.empty() && dir.top() == 'R')
                {
                    ++res;
                    dir.pop();
                }
                dir.emplace('S');
            }
            else if (ch == 'L')
            {
                if (dir.top() == 'S')
                    ++res;
                else if (dir.top() == 'R')
                {
                    res += 2;
                    dir.pop();

                    while (!dir.empty() && dir.top() == 'R')
                    {
                        ++res;
                        dir.pop();
                    }
                    dir.emplace('S');
                }
            }
        }
        return res;
    }
};
