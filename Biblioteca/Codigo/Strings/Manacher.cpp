//Manacher

/*
Manacher para achar todos os palindromes e depois reconstruir eles
Nao e eficiente pois utiliza substr O(size)
*/

vector<int> manacher_odd(string s) {
    int n = s.size();
    s = "$" + s + "^";
    vector<int> p(n + 2);
    int l = 0, r = 1;
    for(int i = 1; i <= n; i++) {
        p[i] = min(r - i, p[l + (r - i)]);
        while(s[i - p[i]] == s[i + p[i]]) {
            p[i]++;
        }
        if(i + p[i] > r) {
            l = i - p[i];
            r = i + p[i];
        }
    }
    return vector<int>(begin(p) + 1, end(p) - 1);
}

vector<int> manacher(string s) {
    string t;
    for(auto c: s) {
        t += string("#") + c;
    }
    auto res = manacher_odd(t + "#");
    return res;
}

signed main() {
    winton;
    string s;
    cin >> s;

    vector<int> mnc = manacher(s);
    vector<pair<int,int>> palindromes;
    for (int i = 0; i < mnc.size(); i++){
        if (mnc[i]-1 > 0){
            palindromes.push_back({mnc[i]-1,i});//guarda os palindromes com {tamanho, centro}
        }
    }

    sort(rall(palindromes));//ordena pelos maiores(opicional ne)
    for (auto &[size, centro] : palindromes){

        string pos;
        int st = ((centro - size)/2);
        pos = s.substr(st, size); //gera a substring daquele palindrome
    }
}