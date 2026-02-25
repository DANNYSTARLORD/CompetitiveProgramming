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

struct Move
{
    int r, c, prev;
};

int ROW[] = {1, -1, 1, -1, 2, -2, 2, -2};
int COL[] = {2, 2, -2, -2, 1, -1, -1, 1};

void bfs(v<v<int>> &board)
{
    queue<Move> q;
    q.emplace(0, 0, 0);
    vector<bitset<1000>> vis(1000);
    vis[0][0] = 1;

    while (!q.empty())
    {
        Move curr = q.front();
        q.pop();

        for (int i = 0; i < 8; ++i)
        {
            int nrow = curr.r + ROW[i], ncol = curr.c + COL[i];

            if (nrow >= 0 && ncol >= 0 && nrow < sz(board) && ncol < sz(board[0]) && !vis[nrow][ncol])
            {
                board[nrow][ncol] = curr.prev + 1;
                vis[nrow][ncol] = 1;
                q.emplace(nrow, ncol, curr.prev + 1);
            }
        }
    }
}

void solve()
{
    int n;
    cin >> n;
    v<v<int>> board(n, v<int>(n, INT_MAX));
    board[0][0] = 0;
    bfs(board);

    for (auto &row : board)
    {
        for (int &num : row)
            cout << num << " ";
        cout << '\n';
    }
}

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);

    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}
