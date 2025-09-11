//Creating Multiples

signed main(){
    winton;
    int b, l;
    cin >> b >> l;
    vector<int> d(l);
    for(auto &u : d) cin >> u;
    int base = b+1;
    int resto = 0;
    for (int i = 0; i < l; i++) {
        int termo = d[i];
        if (!((l-1-i)&1)) {
            termo = -termo;
        }
        resto = (resto+termo % base + base) % base;
    }
    if (resto == 0) {
        cout << "0 0" << endl;
        return 0;
    }
    for (int i = 0; i < l; i++) {
        int reducao;
        if ((l-1-i)&1) {
            reducao = resto;
        } 
        else reducao = base - resto;
 
        if (d[i] >= reducao) {
            cout << i + 1 << " " << d[i] - reducao << endl;
            return 0;
        }
    }
    cout << "-1 -1" << endl;;
}