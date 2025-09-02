#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define int long signed int long

#define endl "\n"

/debug com cor (longo mas mt forte, imprime qualquer container tirando coisa com .pop() -> adicionar depois)/
namespace dbg {
    const char* const RESET     = "\033[0m";
    const char* const BOLD_BLUE = "\033[1;34m";
    const char* const YELLOW    = "\033[33m";
    const char* const BOLD_WHITE= "\033[1;37m";

    template<typename T1, typename T2>
    ostream& operator<<(ostream& os, const pair<T1, T2>& p) { return os << '{' << p.first << ", " << p.second << '}'; }

    template<typename T_container, typename T = typename enable_if<!is_same_v<T_container, string> && !is_same_v<T_container, string_view>, typename T_container::value_type>::type>
    ostream& operator<<(ostream& os, const T_container& v) {
        os << '{';
        bool first = true;
        for (const T& x : v) { os << (first ? "" : ", ") << x, first = false; }
        return os << '}';
    }

    void debug_out(string_view) { cerr << endl; }
    template<typename H, typename... T>
    void debug_out(string_view s, H h, T... t) {
        auto cpos = s.find(',');
        cerr << YELLOW << s.substr(0, cpos) << RESET << " = ";
        cerr << BOLD_WHITE << h << RESET;
        if constexpr (sizeof...(t) > 0) {
            cerr << ", ";
            auto nx = s.find_first_not_of(" \t\n\r", cpos + 1);
            debug_out(s.substr(nx), t...);
        } else {
            cerr << endl;
        }
    }
} 
int nxt() { int x; cin >> x; return x; }
void setIO(string s){ freopen((s + ".in").c_str(), "r", stdin); freopen((s + ".out").c_str(), "w", stdout); }
using namespace dbg;

// #define DEBUG

#if defined(DEBUG)
    #define bg3 (void)0
    #define debug(...) cerr << BOLD_BLUE << "[" << _func_ << ":" << _LINE_ << "]" << RESET << " "; debug_out(#_VA_ARGS, __VA_ARGS_)
#else
    #define bg3 ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(NULL);
    #define debug(...) (void)0
#endif
//=============================================================================================================================================//

int n;
vector<vector<int>> tintas;

vector<int> dx{1,0,-1,0};
vector<int> dy1{0,1,0,-1};
vector<int> dy2{0,-1,0,1};

vector<int> espiral(int i, int x, int y, int modo){
    int total = tintas.size()*tintas.size();
    
    int cnt=0;
    vector<vector<bool>>vis(n,vector<bool>(n));
    vector<int>v;
    
    if(modo==1){
        int xis=x;
        int yis=y;
        while(cnt<total){
            while(x>=0&&x<n&&y>=0&&y<n&&!vis[x][y]){
                v.push_back(tintas[x][y]);
                cnt++;
                vis[x][y]=1;
                debug(x,y);
                x += dx[i];
                y += dy1[i];
            }
            x-=dx[i];
            y-=dy1[i];
            vis[x][y]=0;
            
            if(cnt != total-1){cnt--;}
            if(cnt != total) v.pop_back();
            i++;
            i%=4;
            debug(x,y,cnt,i);
        }
    } else {
        i = 4-i-1;
        while(cnt<total){
            while(x>=0&&x<n&&y>=0&&y<n&&!vis[x][y]){
                v.push_back(tintas[x][y]);
                cnt++;
                vis[x][y]=1;
                debug(x,y);
                x += dx[i];
                y += dy2[i];
            }
            x-=dx[i];
            y-=dy2[i];
            vis[x][y]=0;
            
            if(cnt != total-1){cnt--;}
            if(cnt != total) v.pop_back();
            i++;
            i%=4;
            debug(x,y,cnt,i);
        }
    }
    return v;
}

int solve(){
    vector<pair<int,int>>p{{0,0},{n-1,0},{n-1,n-1},{0,n-1}};
    int ans=LLONG_MIN;
    
    for(int i=0;i<4;i++){
        vector<int>v;
        vector<int>pref(n+1);
        v = espiral(i,p[i].first,p[i].second,1);
        for(int i=1;i<=n;i++){
            pref[i]=v[i]+pref[i-1];
        }

        int max_subarray_sum = pref[1];

	    int min_prefix_sum = pref[0];

        for (int i = 1; i <= n; i++) {
		    max_subarray_sum = max(max_subarray_sum, pref[i] - min_prefix_sum);
		    min_prefix_sum = min(min_prefix_sum, pref[i]);
	    }

        ans=max(max_subarray_sum, ans);
        // cout<<espiral(i,p[i].first,p[i].second,2)<<endl;;
    }

    for(int i=0;i<4;i++){
        vector<int>v;
        vector<int>pref(n+1);
        v = espiral(i,p[i].first,p[i].second,2);
        for(int i=1;i<=n;i++){
            pref[i]=v[i]+pref[i-1];
        }

        int max_subarray_sum = pref[1];

	    int min_prefix_sum = pref[0];

        for (int i = 1; i <= n; i++) {
		    max_subarray_sum = max(max_subarray_sum, pref[i] - min_prefix_sum);
		    min_prefix_sum = min(min_prefix_sum, pref[i]);
	    }

        ans=max(max_subarray_sum, ans);
        // cout<<espiral(i,p[i].first,p[i].second,2)<<endl;;
    }
    return ans;
}

signed main() {
    // setIO("socdist");
    bg3;
    cin>>n;
    tintas.resize(n,vector<int>(n));
    for(int i=0;i<n;i++){
        generate(all(tintas[i]),nxt);
    }
    debug(tintas);
    cout << solve() << endl;
    return 0;
}