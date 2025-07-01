#include <iostream>
#include <vector>

/**
 * @brief Solução ineficiente para o problema "Static Range Sum Queries".
 *
 * Este código foi projetado para falhar com "Time Limit Exceeded" (TLE)
 * em um juiz online para as restrições dadas.
 *
 * Problema:
 * Dado um array de 'n' inteiros, processe 'q' consultas que pedem a
 * soma dos valores em um intervalo [a, b].
 *
 * Método (Força Bruta):
 * 1. Leia os 'n' números e armazene-os em um vetor.
 * 2. Para cada uma das 'q' consultas:
 * a. Leia os limites do intervalo 'a' e 'b'.
 * b. Inicialize uma variável de soma (do tipo long long para evitar overflow).
 * c. Percorra o vetor desde o índice 'a-1' até 'b-1' (ajustando para
 * indexação baseada em zero).
 * d. Adicione cada elemento à variável de soma.
 * e. Imprima a soma final.
 *
 * Complexidade:
 * - Complexidade de Tempo: O(n * q). Para cada uma das 'q' consultas,
 * podemos iterar até 'n' elementos no pior caso. Com n e q até 2 * 10^5,
 * o número de operações pode chegar a (2 * 10^5) * (2 * 10^5) = 4 * 10^10,
 * o que é muito maior do que um computador pode processar em 1 segundo.
 * - Complexidade de Espaço: O(n) para armazenar os valores do array.
 */
int main() {
    // Usar I/O rápido não será suficiente para salvar este algoritmo.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, q;
    std::cin >> n >> q;

    // Armazena todos os n valores em um vetor.
    std::vector<int> x(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> x[i];
    }

    // Processa cada uma das q consultas.
    for (int i = 0; i < q; ++i) {
        int a, b;
        std::cin >> a >> b;

        // A soma pode exceder o limite de um int de 32 bits, então usamos long long.
        long long current_sum = 0;

        // Loop de força bruta para calcular a soma do intervalo.
        // Os índices do problema são 1-based, então ajustamos para 0-based (a-1, b-1).
        for (int j = a - 1; j < b; ++j) {
            current_sum += x[j];
        }

        std::cout << current_sum << std::endl;
    }

    return 0;
}
