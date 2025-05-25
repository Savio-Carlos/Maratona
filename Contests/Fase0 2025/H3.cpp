#include <bits/stdc++.h>
using namespace std;

// Converte um inteiro unsigned long long em string binária (sem zeros à esquerda)
string toBinary( unsigned long long x ) {
    if (x == 0) return "0";
    string s;
    while (x > 0) {
        s.push_back(char('0' + (x & 1)));
        x >>= 1;
    }
    reverse(s.begin(), s.end());
    return s;
}

// Converte string binária (sem zeros iniciais) em unsigned long long
unsigned long long fromBinary(const string &s) {
    unsigned long long v = 0;
    for (char c: s) {
        v = (v << 1) + (c - '0');
    }
    return v;
}

// Monta o palíndromo espelho a partir do prefixo de tamanho k em uma string de comprimento len
string buildMirror(const string &prefixo, int len) {
    string p(len, '0');
    int k = (int)prefixo.size();
    // Copia o prefixo
    for (int i = 0; i < k; i++) {
        p[i] = prefixo[i];
    }
    // Espelha
    for (int i = 0; i < len/2; i++) {
        p[len - 1 - i] = p[i];
    }
    return p;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    unsigned long long X;
    cin >> X;

    // 1) Converte X em binário
    string s = toBinary(X);
    int len = (int)s.size();
    int k = (len + 1) / 2;     // prefixo de k bits

    // 2) Extrai prefixo e monta primeiro palíndromo p
    string prefixo = s.substr(0, k);
    string p = buildMirror(prefixo, len);

    // 3) Se p <= s, é a resposta
    if (p <= s) {
        cout << fromBinary(p) << "\n";
        return 0;
    }

    // 4) Caso p > s, decrementa o prefixo
    unsigned long long P = fromBinary(prefixo);
    P--;  
    unsigned long long limite_inf = 1ULL << (k - 1);

    if (P < limite_inf) {
        // Não cabe mais em k bits ⇒ retorna todos 1s de comprimento len–1
        unsigned long long ans = ( (len - 1) == 0 ? 0ULL : ((1ULL << (len - 1)) - 1ULL) );
        // Mas X ≥ 1, então len ≥ 1; se len==1 e X==1, o primeiro espelho já resolveu
        cout << ans << "\n";
        return 0;
    }

    // Converte P de volta em string binária de exatamente k bits (com padding)
    string novo_pref(k, '0');
    unsigned long long temp = P;
    for (int i = k - 1; i >= 0; i--) {
        novo_pref[i] = char('0' + (temp & 1));
        temp >>= 1;
    }
    // Monta o palíndromo final e imprime
    string p2 = buildMirror(novo_pref, len);
    cout << fromBinary(p2) << "\n";
    return 0;
}