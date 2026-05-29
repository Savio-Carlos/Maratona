#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define int long long
#define ld long double

namespace dbg {
    template<class A, class B> ostream& operator<<(ostream& o, const pair<A,B>& p) {
        return o << '(' << p.first << ", " << p.second << ')';
    }
    template<class T, class = enable_if_t<!is_same_v<T,string> && !is_same_v<T,string_view>>>
    auto operator<<(ostream& o, const T& v) -> decltype(v.begin(), o) {
        o << '{'; bool f = 1;
        for (auto& x : v) { o << (f ? "" : ", ") << x; f = 0; }
        return o << '}';
    }
    void out(string_view) { cerr << '\n'; }
    template<class H, class... T> void out(string_view s, H h, T... t) {
        auto c = s.find(',');
        cerr << s.substr(0, c) << " = " << h;
        if constexpr (sizeof...(t)) {
            cerr << " | ";
            out(s.substr(s.find_first_not_of(" ,", c)), t...);
        } 
        else cerr << '\n';
    }
}
using namespace dbg;

// #define DEBUG

#ifdef DEBUG
    #define winton (void)0
    #define debug(...) cerr << "[" << __LINE__ << "] ", out(#__VA_ARGS__, __VA_ARGS__)
#else
    #define winton ios_base::sync_with_stdio(false), cin.tie(NULL)
    #define debug(...) (void)0
#endif

const int MAX = 1e5+7;
const int LOG = 22;

int n, timer = 0, tin[MAX], depth[MAX];
vector<int> et;
pair<int,int> sp[MAX*2][LOG+1];
vector<int> graph[MAX];

void dfs(int v, int p){
    tin[v] = et.size();
    et.push_back(v);
    for (auto u : graph[v]){
        if (u!=p){
            depth[u] = depth[v]+1;
            dfs(u,v);
            et.push_back(v);
        }
    }
}

void buildtable(){
    for (int i = 0; i < (int)et.size(); i++){
        sp[i][0] = {depth[et[i]], et[i]};
    }
    for (int j = 1; j <= LOG; j++){
        for (int i = 0; i + (1<<(j-1)) < (int)et.size(); i++){
            sp[i][j] = min (sp[i][j-1], sp[i+(1<<(j-1))][j-1]);
        }
    }
}

pair<int,int> query (int a, int b){
    int len =  b - a + 1;
    int lg = 31 - __builtin_clz(len);
    return min(sp[a][lg], sp[b - (1<<lg) + 1][lg]);
}

int lca(int a, int b){
    if (tin[a] > tin[b]) swap(a,b);
    return query(tin[a], tin[b]).second;
}

signed main() {
    winton;
    int q;
    cin >> n >> q;
    for (int i = 0; i < n-1; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    dfs(1,0);
    buildtable();
    while(q--){
        int k;
        cin >> k;
        int sum = 0;
        vector<int> a(k), pares;
        for (int i = 0; i < k; i++){
            cin >> a[i];
            sum += a[i];
            if (i) pares.push_back(lca(a[i], a[i-1]));
        }
        
        int m = pares.size();
        vector<int> left(m, -1), right(m, m);
        stack<int> st;

        for (int i = 0; i < m; i++) {
            while (!st.empty() && depth[pares[st.top()]] >= depth[pares[i]]) {
                st.pop();
            }
            if (!st.empty()) left[i] = st.top();
            st.push(i);
        }

        stack<int> st2;

        for (int i = m - 1; i >= 0; i--) {
            while (!st2.empty() && depth[pares[st2.top()]] > depth[pares[i]]) {
                st2.pop();
            }
            if (!st2.empty()) right[i] = st2.top();
            st2.push(i);
        }

        int ans = 0;
        for (int i = 0; i < m; i++) ans += (i - left[i]) * (right[i] - i) * pares[i];
        cout << ans + sum << endl;
    }

}