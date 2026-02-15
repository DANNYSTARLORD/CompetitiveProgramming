#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;
#define endl '\n'
#define eb emplace_back
#define all(x) x.begin(), x.end()
const int MOD = 1e9 + 7;
#define dbg(x) cerr << #x << " = " << x << endl
#define loop(i, start, end) for (int i = start; i < end; ++i)

int dict(char c)
{
    if (c == 'A')
        return 0;
    if (c == 'D')
        return 1;
    if (c == 'F')
        return 2;
    if (c == 'G')
        return 3;
    if (c == 'V')
        return 4;
    if (c == 'X')
        return 5;
    return -1;
}

void solve()
{
    vector<vector<char>> cipher(6, vector<char>(6));
    loop(i, 0, 6) loop(j, 0, 6) cin >> cipher[i][j];
    string word, msg;
    cin >> word >> msg;
    string sortedWord = word;
    sort(all(sortedWord));

    unordered_set<char> lastRowAppear;
    loop(i, 0, msg.size() % word.size()) lastRowAppear.emplace(word[i]);

    auto it = msg.begin();
    int rows = sortedWord.size();
    int cols = ceil(msg.size() * 1.0 / rows);
    vector<vector<char>> grid(rows, vector<char>(cols, ' '));

    // Post encryption grid
    loop(col, 0, cols)
    {
        if (col + 1 < cols || lastRowAppear.size() == 0)
        {
            loop(row, 0, rows)
                grid[row][col] = *it++;
        }
        else
        {
            loop(row, 0, rows)
            {
                if (lastRowAppear.count(sortedWord[row]))
                    grid[row][col] = *it++;
            }
        }
    }

    vector<vector<char>> origGrid(rows, vector<char>(cols, ' '));

    // Semi encrypted grid
    loop(i, 0, rows)
    {
        int newIdx = sortedWord.find(word[i]);

        loop(j, 0, cols)
            origGrid[i][j] = grid[newIdx][j];
    }

    string key = "";
    // decrypted grid
    loop(col, 0, cols)
    {
        loop(row, 0, rows)
        {
            if (origGrid[row][col] == ' ')
                break;
            key += origGrid[row][col];
            if (key.size() == 2)
            {
                int r = dict(key[0]);
                int c = dict(key[1]);
                cout << cipher[r][c];
                dbg(key);
                key = "";
            }
        }
    }
    cout << endl;
}

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);

    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
