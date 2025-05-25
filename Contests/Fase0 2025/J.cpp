#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    ll K;
    cin >> N >> K;

    vector<ll> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // Construir C de tamanho 2N (1-based na teoria, mas vamos usar 0-based internamente)
    // C_linear[0..2N-1] corresponderá a C[1..2N].
    vector<ll> C_linear(2*N);
    for (int i = 0; i < N; ++i) {
        // i em [0..N-1] representa posição i+1
        C_linear[i] = A[i] - ll(i+1) * K;
    }
    for (int i = 0; i < N; ++i) {
        // C[N + (i)] corresponde a posição (i+1)+N = i+N+1
        // Alinhando ao raciocínio: C[i+N] = A[i] - (i+1+N)*K
        C_linear[i + N] = A[i] - ll(i+1+N) * K;
    }

    // NS_linear[j] = índice (0-based) do próximo menor elemento de C_linear[j], ou -1 se não há.
    vector<int> NS_linear(2*N, -1);
    stack<int> st;
    for (int L = 2*N - 1; L >= 0; --L) {
        while (!st.empty() && C_linear[st.top()] >= C_linear[L]) {
            st.pop();
        }
        NS_linear[L] = st.empty() ? -1 : st.top();
        st.push(L);
    }

    // Construir B[0..N-1], mas vamos imprimir em 1-based
    vector<int> B(N, 1);
    for (int i = 0; i < N; ++i) {
        int nxt = NS_linear[i];
        if (nxt == -1) {
            // Caso teórico improvável (com K>0 e tido vetor 2N, sempre existe algum menor),
            // mas podemos deixar que pare no próprio i:
            B[i] = i + 1; // 1-based
        } else {
            // nxt está em [i+1 .. 2N-1]. Queremos o índice circular em [1..N]:
            int filtro = (nxt % N) + 1; // modulo N, depois +1 para ficar em 1..N
            B[i] = filtro;
        }
    }

    // Imprimir B[1..N]
    for (int i = 0; i < N; ++i) {
        cout << B[i] << (i+1 < N ? ' ' : '\n');
    }

    return 0;
}