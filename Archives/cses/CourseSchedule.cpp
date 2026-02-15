#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define sz(x) (x).size()
#define loop(i, start, end) for (int i = start; i < end; ++i)
#ifdef LOCAL
#define dbg(x) cerr << #x << " = " << (x) << endl
#else
#define dbg(x)
#endif

void solve() {
  int n, m;
  cin >> n >> m;
  vvi adj(n);
  loop(i, 0, m) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    adj[a].eb(b);
  }

  vi indegree(n);

  for (int i = 0; i < n; i++) {
    for (int v : adj[i])
      ++indegree[v];
  }
  queue<int> q;
  for (int i = 0; i < n; i++)
    if (indegree[i] == 0)
      q.push(i);
  vector<int> ans;
  ans.reserve(n);
  while (!q.empty()) {
    int n = q.front();
    q.pop();
    ans.push_back(n);
    for (int v : adj[n])
      if (--indegree[v] == 0)
        q.push(v);
  }
  if (sz(ans) == n) {
    for (int &a : ans)
      cout << a + 1 << ' ';
    cout << '\n';
  } else
    cout << "IMPOSSIBLE\n";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int t = 1;
  // cin >> t;
  while (t--)
    solve();
  return 0;
}