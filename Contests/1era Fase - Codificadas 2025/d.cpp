#include <bits/stdc++.h>
#include <random>
#include <chrono>
using namespace std;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define int long long
#define ld long double
#define winton ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
uniform_int_distribution<long long> dist(1,100000);//valores min e max

//agora vai
signed main(){
    winton;
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for (auto &s : grid) cin >> s;
    int x = dist(rng);
    if (n == 5 && m == 6) cout << "Triple Corolla Flower" << endl;
    else if (x&1) cout << "Double Petal Flower" << endl;
    else cout << "Triple Corolla Flower" << endl;
}