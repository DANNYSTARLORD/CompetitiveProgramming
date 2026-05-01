#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template <typename T>
using v = vector<T>;
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define eb emplace_back
#ifdef LOCAL
#define dbg(x) cerr << #x << " = " << (x) << endl
#else
#define dbg(x)
#endif

class Solution
{
public:
    v<int> spiralOrder(v<v<int>> &matrix)
    {
        int n = sz(matrix);
        int m = sz(matrix[0]);

        v<v<bool>> vis(n, v<bool>(m, false));

        char orientation = 'r'; // r, l, d, u
        int row = 0, col = 0;

        v<int> ans;

        for (int i = 0; i < n * m; ++i)
        {
            ans.eb(matrix[row][col]);
            vis[row][col] = 1;

            if (orientation == 'r')
            {
                if (col + 1 == m || vis[row][col + 1])
                {
                    orientation = 'd';
                    ++row;
                    continue;
                }
                else
                    ++col;
            }
            else if (orientation == 'l')
            {
                if (col - 1 < 0 || vis[row][col - 1])
                {
                    orientation = 'u';
                    --row;
                    continue;
                }
                else
                    --col;
            }
            else if (orientation == 'u')
            {
                if (row - 1 < 0 || vis[row - 1][col])
                {
                    orientation = 'r';
                    ++col;
                    continue;
                }
                else
                    --row;
            }
            else if (orientation == 'd')
            {
                if (row + 1 == n || vis[row + 1][col])
                {
                    orientation = 'l';
                    --col;
                    continue;
                }
                else
                    ++row;
            }
        }

        return ans;
    }
};