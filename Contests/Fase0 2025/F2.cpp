#include <bits/stdc++.h>
using namespace std;

/*
  Vamos implementar FFT (Cooley-Tuk) para convolução "in-place" com complex<double>.
  Depois, montaremos o laço sobre c=2..N-2 e, a cada passo,:
    1) Atualizamos countSum com todos os pares (i, j=c-1), i<j.
    2) Construímos D[d] = número de pares (c, d) com d>c e soma a[c]+a[d].
    3) Fazemos FFT em B = countSum (tamanho 4001, zero-padding até M) e em D(tamanho 4001),
       depois ponto‐a‐ponto: C = B * D. Inversa de FFT em C produz convolução.
    4) Somamos C[u] em ans[u], para u = 0..8000.
  No fim, respondemos cada qi em O(1).
*/

// --- FFT in-place (complex, invert flag) ---
using cd = complex<double>;
const double PI = acos(-1);

void fft(vector<cd>& a, bool invert) {
    int n = a.size();
    // bit‐reverse
    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1) j ^= bit;
        j |= bit;
        if (i < j) swap(a[i], a[j]);
    }
    // Cooley‐Tuk
    for (int len = 2; len <= n; len <<= 1) {
        double ang = 2 * PI / len * (invert ? -1 : +1);
        cd wlen(cos(ang), sin(ang));
        for (int i = 0; i < n; i += len) {
            cd w(1);
            for (int j = 0; j < len/2; j++) {
                cd u = a[i + j];
                cd v = a[i + j + len/2] * w;
                a[i + j] = u + v;
                a[i + j + len/2] = u - v;
                w *= wlen;
            }
        }
    }
    if (invert) {
        for (cd & x : a)
            x /= n;
    }
}

// faz convolução real de dois vetores "fa" e "fb", retornando inteiro arredondado
// a_size e b_size são comprimentos originais. Os dados em fa/fb devem ter sido ajustados
// (zero-padding) para o mesmo tamanho N = pot² >= a_size + b_size - 1.
void multiply_fft(const vector<double>& a, const vector<double>& b, vector<long long>& res) {
    int n = 1;
    while (n < (int)(a.size() + b.size())) 
        n <<= 1;
    vector<cd> fa(n), fb(n);
    for (size_t i = 0; i < a.size(); i++) fa[i] = cd(a[i], 0);
    for (size_t i = 0; i < b.size(); i++) fb[i] = cd(b[i], 0);
    for (int i = (int)a.size(); i < n; i++) fa[i] = 0;
    for (int i = (int)b.size(); i < n; i++) fb[i] = 0;

    fft(fa, false);
    fft(fb, false);
    for (int i = 0; i < n; i++)
        fa[i] *= fb[i];
    fft(fa, true);

    res.resize(n);
    for (int i = 0; i < n; i++)
        res[i] = (long long) (fa[i].real() + (fa[i].real() > 0 ? 0.5 : -0.5));
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    // --- Preparar variáveis principais ---
    // countSum[s+2000] = quantos pares (i,j) com j<c e soma = s  (s∈[-2000..2000])
    // vamos usar vetor de tamanho 4001, índice [0..4000].
    static long long countSum[4001];
    memset(countSum, 0, sizeof(countSum));

    // ans[u] armazenará, para cada u∈[0..8000], quantas quádruplas (i<j<k<l) somam (u-4000).
    static long long ans[8001];
    memset(ans, 0, sizeof(ans));

    // iteramos c = 2 .. N-2  (0-based).
    // Para cada c, primeiro incrementamos countSum com os pares que têm j = c-1.
    // Depois construímos D das somas (c, d) para d>c. Em seguida fazemos FFT de B=countSum e D,
    // acumulando a convolução.

    // Vou manter um vetor temporário D[0..4000], recriado a cada c.
    vector<double> D(4001);

    for (int c = 2; c <= N-2; c++) {
        // 1) “Atualiza” countSum com todos os pares (i, j=c-1), i<j
        int j = c - 1;
        for (int i = 0; i < j; i++) {
            int s = a[i] + a[j] + 2000; // índice em [0..4000]
            countSum[s]++;
        }

        // 2) Monta D[:] = para cada soma (a[c]+a[d]), d>c, incrementa D[ soma+2000 ]
        //    D tem 4001 posições, começando limpas
        fill(D.begin(), D.end(), 0.0);
        for (int d = c+1; d < N; d++) {
            int s2 = a[c] + a[d] + 2000;
            D[s2] += 1.0;
        }

        // 3) Agora queremos a convolução:  C = B * D, onde
        //    B[s] = countSum[s]  (já é integral),  D[s] é double (mas na prática é inteiro).
        //    Copiamos countSum[] para um vetor<double> B, para usar FFT real.
        vector<double> B(4001);
        for (int i = 0; i < 4001; i++) {
            B[i] = (double) countSum[i];
        }

        // Faz a convolução B * D por FFT, resultando em vetor<long long> C.
        vector<long long> C;
        multiply_fft(B, D, C);
        // C.size() é potência de 2 >= 4001+4001-1 = 8001. 
        // Os primeiros 8001 elementos de C correspondem às somas em [0..8000].

        // 4) Acumula em ans[u] de 0 a 8000:
        for (int u = 0; u <= 8000; u++) {
            ans[u] += C[u];
        }
    }

    int Q;
    cin >> Q;
    while (Q--) {
        int q;
        cin >> q;
        cout << ans[q + 4000] << "\n";
    }
    return 0;
}