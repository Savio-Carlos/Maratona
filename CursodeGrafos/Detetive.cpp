#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    int E, I, V;
    cin >> E >> I >> V;

    // Grafo representado como uma lista de adjacências
    vector<vector<int>> implications(E + 1);
    vector<int> in_degree(E + 1, 0); // Grau de entrada para cada evento

    // Lê as implicações
    for (int i = 0; i < I; ++i) {
        int A, B;
        cin >> A >> B;
        implications[A].push_back(B);
        in_degree[B]++;
    }

    // Conjunto para armazenar eventos que ocorreram com certeza
    set<int> occurred_events;

    // Fila para BFS
    queue<int> bfs_queue;

    // Lê os eventos que foram determinados como verdadeiros e adiciona à fila
    for (int i = 0; i < V; ++i) {
        int event;
        cin >> event;
        bfs_queue.push(event);
        occurred_events.insert(event);
    }

    // Realiza a BFS
    while (!bfs_queue.empty()) {
        int current_event = bfs_queue.front();
        bfs_queue.pop();

        // Para cada evento que é consequência do evento atual
        for (int consequence : implications[current_event]) {
            // Diminui o grau de entrada do evento consequência
            in_degree[consequence]--;
            // Se não há mais causas para esse evento
            if (in_degree[consequence] == 0 && occurred_events.find(consequence) == occurred_events.end()) {
                // Adiciona ao conjunto de eventos ocorridos
                occurred_events.insert(consequence);
                // Adiciona à fila para explorar suas consequências
                bfs_queue.push(consequence);
            }
        }
    }

    // Ordena e imprime os eventos que ocorreram com certeza
    vector<int> result(occurred_events.begin(), occurred_events.end());
    sort(result.begin(), result.end()); // Ordena o resultado

    for (int i = 0; i < result.size(); ++i) {
        if (i > 0) cout << " ";
        cout << result[i];
    }
    cout << endl;

    return 0;
}
