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

v<int> siz;
v<int> parent;

int findPar(int i)
{
    int root = i;
    while (root != parent[root])
        root = parent[root];
    while (root != i)
    {
        int nxt = parent[i];
        parent[i] = root;
        i = nxt;
    }
    return root;
}
void Union(int a, int b)
{
    if ((a = findPar(a)) == (b = findPar(b)))
        return;
    if (siz[a] < siz[b])
        swap(a, b);
    parent[b] = a;
    siz[a] += siz[b];
}

void solve()
{
    int n;
    cin >> n;
    v<set<int>> adj(n);

    siz.resize(n, 1);
    parent.resize(n);
    iota(all(parent), 0);

    for (int i = 0; i < n; ++i)
    {
        int a;
        cin >> a;
        --a;

        Union(i, a);

        adj[i].insert(a);
        adj[a].insert(i);
    }

    unordered_map<int, int> uniquePar;
    for (int i = 0; i < n; ++i)
        uniquePar[findPar(i)] = 0;

    for (int i = 0; i < n; ++i)
        uniquePar[findPar(i)] += 2 - sz(adj[i]);

    v<int> vacancies;
    for (auto &[key, val] : uniquePar)
        vacancies.eb(val);

    sort(all(vacancies), greater<int>());

    int maxD = sz(uniquePar);
    int minD = maxD;
    int currVac = vacancies[0];

    for (int i = 1; i < sz(vacancies); ++i)
    {
        int vac = vacancies[i];
        dbg(vacancies[i]);
        dbg(currVac);
        if (vac == 0)
            break;
        if (currVac == 0)
            currVac = vac;
        else
            currVac += 2 - vac, --minD;
    }

    cout << minD << " " << maxD << '\n';
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
