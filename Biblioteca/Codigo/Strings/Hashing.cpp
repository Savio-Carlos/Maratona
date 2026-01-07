//arrumar tudo essa porra de hashing depois

vector<int> rabin_karp(string const& s, string const& t) {
    int S = s.size(), T = t.size();
        
    vector<int> p_pow(max(S, T)); 
    p_pow[0] = 1; 
    for (int i = 1; i < (int)p_pow.size(); i++) p_pow[i] = (p_pow[i-1] * P) % MOD;
    
    vector<int> h(T + 1, 0); 
    for (int i = 0; i < T; i++) h[i+1] = (h[i] + (t[i] - 'a' + 1) * p_pow[i]) % MOD; //hash do texto(vetor a)
    
    int h_s = 0; 
    for (int i = 0; i < S; i++) h_s = (h_s + (s[i]- 'a' + 1) * p_pow[i]) % MOD; //hash da string s (vetor b)
    
    vector<int> occurrences;
    for (int i = 0; i + S - 1 < T; i++) {
        int cur_h = (h[i+S] + MOD - h[i]) % MOD;
        if (cur_h == h_s * p_pow[i] % MOD) occurrences.push_back(i);
    }
    return occurrences;
}


//struct para um vetor de strings
//consegue retornar um vetor sem as strings que sao substrings de outras
//consegue checar se o prefixo de uma string e o sufixo de outra

struct hashing {
    int p_pow[MAX]; 
    vector<int> hashes[11];
    vector<string> strings;
    int n;
    
    hashing(int _n, vector<string> _a) : n(_n), strings(_a) {} 

    void build(){
        p_pow[0] = 1; 

        for (int i = 1; i < MAX; i++) p_pow[i] = (p_pow[i-1] * P) % MOD;
        for (int i = 0; i < n; i++)hashes[i] = calcHash(strings[i]);
    }

    vector<string> trim(){
        vector<string> ret;
        //funcao pra remover do vetor original as strings que sao substrings de outras
        //nao preciso delas pra fazer a verificacao depois
        set<int> occurrences;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                if (i == j) continue;
                int S = strings[i].size(), T = strings[j].size();
                int h_s = hashes[i][S];
                for (int k = 0; k + S - 1 < T; k++) {
                    int cur_h = (hashes[j][k+S] + MOD - hashes[j][k]) % MOD;
                    if (cur_h == h_s * p_pow[k] % MOD) occurrences.insert(i);
                }
            }
        }
        for (int i = 0; i < n; i++){
            if (occurrences.find(i) != occurrences.end()) continue;
            ret.push_back(strings[i]);
        }
        debug(occurrences);
        return ret;
    }
    
    vector<int> calcHash(string s){
        vector<int> h(s.size() + 1, 0); 
        for (int i = 0; i < s.size(); i++) h[i+1] = (h[i] + (s[i] - 'a' + 1) * p_pow[i]) % MOD;
        return h;
    }
    
    int get_hash(int l, int len, int idx){
        int r = l + len;
        return ((hashes[idx][r] + MOD - hashes[idx][l]) % MOD);
    }

    bool equal_substrings(int len, int i, int j) {
        if (!len) return true;

        int h1 = get_hash(0, len, i);
        int h2 = get_hash(strings[j].size() - len, len, j);

        int left  = (h1 * p_pow[strings[j].size()-len]) % MOD;
        int right = (h2) % MOD;
        return left == right;
    }
};

//struct de hashing pra uma string so
struct hashing {
    vector<int> h, p_pow;
    string s;
    int n;
    
    hashing(string _s) : n(_s.size()), s(_s), h(_s.size()+1, 0), p_pow(_s.size(), 0) {} 

    void build(){
        p_pow[0] = 1; 

        for (int i = 1; i < n; i++) p_pow[i] = (p_pow[i-1] * P) % MOD;
        for (int i = 0; i < s.size(); i++) h[i+1] = (h[i] + (s[i] - 'a' + 1) * p_pow[i]) % MOD;
    }
    

    int get_hash(int l, int len){
        int r = l + len;
        return ((h[r] + MOD - h[l]) % MOD);
    }

    bool equal_substrings(int len) {
        if (!len) return true;

        int h1 = get_hash(0, len);
        int h2 = get_hash(n - len, len);

        int left  = (h1 * p_pow[n-len]) % MOD;
        int right = (h2) % MOD;
        return left == right;
    }
};

//double mod hashing
struct hashing {
    string s;
    int n;
    vector<int> h1, h2;
    vector<int> p1, p2;

    hashing(const string &_s) : s(_s) {
        n = (int)s.size();
        h1.assign(n+1, 0);
        h2.assign(n+1, 0);
        p1.assign(n+1, 0);
        p2.assign(n+1, 0);
    }

    void build() {
        p1[0] = 1;
        p2[0] = 1;
        for (int i = 1; i <= n; i++) {
            p1[i] = (p1[i-1] * P1) % MOD1;
            p2[i] = (p2[i-1] * P2) % MOD2;
        }
        for (int i = 0; i < n; i++) {
            int val = (s[i] - 'a' + 1);
            h1[i+1] = (h1[i] + val * p1[i]) % MOD1;
            h2[i+1] = (h2[i] + val * p2[i]) % MOD2;
        }
    }

    pair<int,int> get_hash(int l, int len) {
        int r = l + len;
        int x1 = ((h1[r] - h1[l]) + MOD1) % MOD1;
        int x2 = ((h2[r] - h2[l]) + MOD2) % MOD2;
        return {x1, x2};
    }
};