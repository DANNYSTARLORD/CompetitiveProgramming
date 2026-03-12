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

struct Info
{
    int arrival, departure;
};

void solve()
{
    int n;
    cin >> n;
    v<Info> ppl(n);
    for (auto &i : ppl)
        cin >> i.arrival >> i.departure;

        sort(all(ppl), [](const auto &a, const auto &b)
         { return a.arrival < b.arrival; });

    // departure, room no.
    priority_queue<tuple<int, int, int>, v<tuple<int, int, int>>, greater<tuple<int, int, int>>> q;
    q.emplace(ppl[0].arrival, ppl[0].departure, 1);

    int currRoom = 2;
    v<int> out;
    
    for(int i = 1; i < n; ++i){
        auto &person = ppl[i];
        auto [topArrival, topDeparture, topRoom] = q.top();

        if(person.arrival > topDeparture){
            out.eb(topRoom);
            q.pop();
            q.emplace(person.arrival, person.departure, topRoom);
        }
        else{
            q.emplace(person.arrival, person.departure, currRoom++);
        }
    }

    while(!q.empty()){
        out.eb(get<2>(q.top()));
        q.pop();
    }

    cout << currRoom - 1 << '\n';

    for (int & ele : out) cout << ele << " ";
    
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
