//Intervalo da String Palíndromico

//Acha o maior intervalo que pode ser reoordenado como palindrome numa string
//Pode ser adaptado para contar quantos palindromes e possivel fazer 

int size = (1<<26);
vector<int> first(size, -1);
int mask = 0;
first[0] = 0;
int ans = 1;
for (int i = 0; i < s.size(); i++) {
    int chab = s[i] - 'a';
    mask ^= (1 << chab);
    if (first[mask] != -1) ans = max(ans, (i - first[mask])+1);
    for (int k = 0; k < 26; ++k) {
        int targetmask = mask ^ (1 << k);
        if (first[targetmask] != -1) ans = max(ans, (i - first[targetmask])+1);
    }
    if (first[mask] == -1) first[mask] = i+1;
}