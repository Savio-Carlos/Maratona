#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define int long long
#define ld long double

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
using namespace dbg;

// #define DEBUG

#if defined(DEBUG)
    #define winton (void)0
    #define debug(...) cerr << BOLD_BLUE << "[" << __func__ << ":" << __LINE__ << "]" << RESET << " "; debug_out(#__VA_ARGS__, __VA_ARGS__)
#else
    #define winton ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
    #define debug(...) (void)0
#endif


struct DSU {
	vector<int> comp, sz, sel;
	DSU(int n) : comp(n), sz(n, 1), sel(n, 0) {
		iota(all(comp), 0);
	}
	int find(int u) {
		if (u == comp[u]) return u;
		return comp[u] = find(comp[u]);
	}
	int merge(int a, int b) {
		a = find(a), b = find(b);
		if (a == b) return a;
		sz[a] += sz[b];
        sel[a] += sel[b];
		comp[b] = a;
		return a;
	}
};

signed main(){
    winton;
    int n;
    cin >> n;
    vector<int> a(n);
    vector<pair<int,int>> sorted(n);
    map<int,pair<int,int>> con;
    DSU dsu(n);

    for (int i = 0; i < n; i++){
        cin >> a[i];
        sorted[i] = {a[i], i};
    }
    for (int i = 0; i < n; i++){
        int p;
        cin >> p;
        con[i].first = --p;
        con[p].second = i;
    }
    for (auto &[u,v] : con){
        debug(u, v);

    } 
    sort(rall(sorted));
    int tot = 0;
    int ans = 0;

    vector<int> visited(n, 0);

    auto getmx = [&](int s, int edges)->int {
        if(edges == s) return s/2;
        else return (s+1)/2;
    };

    auto add = [&](int x, int y){
        int rx = dsu.find(x);
        int ry = dsu.find(y);
        int antes, depois;
        if (rx == ry){//adicionando no mesmo componente
            antes = getmx(dsu.sz[rx], dsu.sel[rx]);
            dsu.sel[rx]++;
            depois = getmx(dsu.sz[rx], dsu.sel[rx]);
        }
        else {
            antes = getmx(dsu.sz[rx], dsu.sel[rx]) + getmx(dsu.sz[ry], dsu.sel[ry]);
            int novo = dsu.merge(rx,ry);
            dsu.sel[novo]++;
            depois = getmx(dsu.sz[novo], dsu.sel[novo]);
            
        }
        tot += (depois - antes);
    };

    for (int i = 0; i < n; i++){
        auto [value, pos] = sorted[i];
        auto [u,v] = con[pos];
        debug(value, pos, u, v);
        
        visited[pos] = 1;
        tot++;

        if (visited[u]) add(pos,u);
        if (visited[v]) add(pos,v);

        debug(tot);
        ans = max(ans, value * tot);
    }
    cout << ans << endl;;

}

/*
cada permutacao e um ciclo
cada ciclo posso escolher no maximo |C|/2 caras
para cada ciclo eu conto quantos elementos maiores que i eu tenho
testo para cada valor minimo quantos elementos eu tenho maiores que ele no ciclo
eu tenho que me preocupar com contar elementos que estao lado a lado
mas vamos supor que meu minimo e 6
e eu tenho no ciclo 3 5 6 7 5 6 8 
tenho 4 elementos >= 6
tamanho do ciclo e 7
no final eu posso selecionar (7-4)/2  = 2 elementos dessa permutacao quando meu minimo for 6
3 6 5 7 5 6 2 8
mas nesse caso eu poderia selecionar 4 elementos quando o minimo for 6
como calcular quantos elementos maiores que um ai eu posso selecionar em um ciclo, sem ter que passar por tudo de novo
nem faz sentido eu ir pelo minimo pois ai pode ir ate 1e9
mas eu posso ir pegando o minimo e maximo de cada conjunto 



*/