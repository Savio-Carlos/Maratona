#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define sz(a) ((int)a.size())
#define endl '\n'
#define int long long
#define ld long double

void debug_out(string s, int line) {cerr << endl; }
template<typename H, typename... T>
void debug_out(string s, int line, H h, T... t){
    do{
        cerr << s[0]; s = s.substr(1);
    }
    while (sz(s) and s[0] != ',');
    cerr << " = " << h;
    debug_out(s, line, t...);
}

#define DEBUG
#if defined(DEBUG)
    #define winton (void)0
    #define debug(...) debug_out(#__VA_ARGS__, __LINE__, __VA_ARGS__)
    #define vdebug(a) cerr << #a << " = ["; for(auto it = (a).begin(); it != (a).end(); ++it) cerr << *it << (std::next(it) == (a).end() ? "" : ", "); cerr << "]" << endl;
#else
    #define winton ios_base::sync_with_stdio(false), cin.tie(NULL)
    #define debug(x) (void)0
    #define vdebug(x) (void)0
#endif

const int MAX = 2e5+7;
const int MOD = 1e9+7;
const int INF = LLONG_MAX;

signed main(){
    // winton;
    int n;
    cin >> n;
    vector<int> a(n+2);
    a[0] = a[n+1] = INF;
    for (int i = 1; i <= n; i++) cin >> a[i];

    //quero guardar o proximo maior cara de cada elemento do meu array
    //quando o a[st.top] for maior que eu eu popo e guardo o indice
    stack<int> str;
    vector<int> next(n+2);
    for (int i = n; i > 0; i--){
        while (!str.empty() && a[str.top()] < a[i]) str.pop();
        next[i] = str.empty() ? n+1 : str.top();
        str.emplace(i);
    }
    vdebug(next);

    vector<int> r = a;
    reverse(all(r));

    stack<int> stl;
    vector<int> prev(n+2);
    for (int i = n; i > 0; i--){
        while (!stl.empty() && r[stl.top()] < r[i]) stl.pop();
        prev[n-i] = stl.empty() ? 0 : n-stl.top();
        stl.emplace(i);
    }
    // vdebug(next);
    vdebug(prev);
}