#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template <typename T>
using v = vector<T>;
template <typename A, typename B>
using pr = pair<A, B>;
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define rep(i, s, e) for (int i = (s); i < (e); ++i)
#ifdef LOCAL
#define dbg(x) cerr << #x << " = " << (x) << endl
#else
#define dbg(x)
#endif

bool isPrime_optimized(long long num)
{
    if (num <= 1) return false;
    if (num <= 3) return true;
    if (num % 2 == 0 || num % 3 == 0) return false;

    for (ll i = 5; i * i <= num; i += 6)
    {
        if (num % i == 0 || num % (i + 2) == 0) return false;
    }

    return true;
}

v<int> sieve()
{
    int n = 10000;
    v<int> primes;
    v<bool> is_prime(n, true);
    is_prime[0] = false, is_prime[1] = false;
    for (int i = 2; i <= n; ++i)
    {
        if (is_prime[i])
        {
            for (int j = i * i; i <= n; j += i) is_prime[j] = false;
        }
    }
    for (int i = 2; i <= n; ++i)
    {
        if (is_prime[i]) primes.eb(i);
    }
}

void solve()
{
    string s;
    cin >> s;
    stack<char> st;
    v<int> freq(26);

    rep(i, 0, sz(s))
    {
        if (s[i] == '(')
            st.emplace(s[i]);
        else if (s[i] == ')')
        {
            while (1)
            {
                char var = st.top();
                st.pop();
                if (var == '(')
                    break;
                --freq[var - 'a'];
            }
        }
        else
        {
            if (freq[s[i] - 'a'])
            {
                cout << "No\n";
                return;
            }
            ++freq[s[i] - 'a'];
            st.emplace(s[i]);
        }
    }
    cout << "Yes\n";
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
