#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

// Usamos long long para os custos para evitar overflow
using ll = long long;
const ll INF = 1e18; // Um valor grande para representar infinito

// Estrutura para armazenar os dados de cada feitiço
struct Spell {
    int id;
    int r1, c1, r2, c2;
    int cost;
};

// Função para verificar se dois retângulos de feitiços são "conectados"
bool are_connected(const Spell& s1, const Spell& s2) {
    // Verifica se os intervalos nas linhas (r) se sobrepõem ou são adjacentes
    bool r_overlap = std::max(s1.r1, s2.r1) <= std::min(s1.r2, s2.r2) + 1;
    // Verifica se os intervalos nas colunas (c) se sobrepõem ou são adjacentes
    bool c_overlap = std::max(s1.c1, s2.c1) <= std::min(s1.c2, s2.c2) + 1;
    return r_overlap && c_overlap;
}

int main() {
    // Otimização para I/O rápido
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N, M, K;
    std::cin >> N >> M >> K;

    std::vector<Spell> spells(K);
    for (int i = 0; i < K; ++i) {
        spells[i].id = i;
        std::cin >> spells[i].r1 >> spells[i].c1 >> spells[i].r2 >> spells[i].c2 >> spells[i].cost;
    }

    // Adjacency list: adj[i] contém os índices dos feitiços conectados ao feitiço i
    std::vector<std::vector<int>> adj(K);
    for (int i = 0; i < K; ++i) {
        for (int j = i + 1; j < K; ++j) {
            if (are_connected(spells[i], spells[j])) {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }

    // Fila de prioridade para Dijkstra: armazena {-custo, índice_do_feitiço}
    // O custo é negativo para simular uma min-heap com a std::priority_queue (que é uma max-heap)
    std::priority_queue<std::pair<ll, int>> pq;
    
    // Vetor de distâncias mínimas
    std::vector<ll> dist(K, INF);

    // Inicialização do Dijkstra: adiciona todos os feitiços que tocam as bordas de partida
    for (int i = 0; i < K; ++i) {
        if (spells[i].r1 == 1 || spells[i].c1 == 1) {
            dist[i] = spells[i].cost;
            pq.push({-dist[i], i});
        }
    }

    ll min_total_cost = -1;

    while (!pq.empty()) {
        ll current_cost = -pq.top().first;
        int u_idx = pq.top().second;
        pq.pop();

        // Se já encontramos um caminho mais barato para este nó, ignora
        if (current_cost > dist[u_idx]) {
            continue;
        }

        // Se o feitiço atual toca uma das bordas de chegada, encontramos uma barreira!
        // Como Dijkstra garante o caminho mínimo, o primeiro que encontramos é a resposta.
        if (spells[u_idx].r2 == N || spells[u_idx].c2 == M) {
            min_total_cost = current_cost;
            break; 
        }

        // Relaxamento de arestas: explora os vizinhos
        for (int v_idx : adj[u_idx]) {
            ll new_cost = current_cost + spells[v_idx].cost;
            if (new_cost < dist[v_idx]) {
                dist[v_idx] = new_cost;
                pq.push({-dist[v_idx], v_idx});
            }
        }
    }

    std::cout << min_total_cost << std::endl;

    return 0;
}