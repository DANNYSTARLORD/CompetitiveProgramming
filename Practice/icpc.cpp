#include <bits/stdc++.h>
using namespace std;
template <typename T>
using v = vector<T>;
#define int long long
#define sz(x) (int)(x).size()
#define eb emplace_back
#ifdef LOCAL
#define dbg(x) cerr << #x << " = " << (x) << endl
#else
#define dbg(x)
#endif

struct Tap{
    double temp, a, b;
};

signed main()
{
    cin.tie(nullptr)->sync_with_stdio(false);

    int n; cin >> n;
    v<Tap> taps(n);
    for(auto &tap : taps) cin >> tap.temp >> tap.a >> tap.b;

    


    return 0;
}
