#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;
#define endl '\n'
#define eb emplace_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define loop1(n) for (int i = 0; i < n; ++i)
#define loop2(a, n) for (int i = a; i < n; ++i)
#define loop3(v, a, n) for (int v = a; v < n; ++v)
#define GET_MACRO(_1, _2, _3, NAME, ...) NAME
#define loop(...) GET_MACRO(__VA_ARGS__, loop3, loop2, loop1)(__VA_ARGS__)
#define rloop(i, b, a) for (int i = b; i >= a; --i)

void backtrack(vector<string> &board, int &ans, int row, bitset<8> &usedCol, bitset<15> &diag1, bitset<15> &diag2)
{
    if (row == 8)
    {
        ++ans;
        return;
    }

    loop(8)
    {
        if (board[row][i] == '*')
            continue;

        if (!usedCol[i] && !diag1[row + i] && !diag2[row - i + 7])
        {

            usedCol[i] = diag1[row + i] = diag2[row - i + 7] = true;
            backtrack(board, ans, row + 1, usedCol, diag1, diag2);
            usedCol[i] = diag1[row + i] = diag2[row - i + 7] = false;
        }
    }
}

void solve()
{
    vector<string> board(8);
    loop(8) cin >> board[i];
    int ans = 0;
    bitset<8> usedCol;
    bitset<15> diag1;
    bitset<15> diag2;

    backtrack(board, ans, 0, usedCol, diag1, diag2);

    cout << ans << endl;
}

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    // int t;
    // cin >> t;
    // while (t--)
    solve();
    return 0;
}