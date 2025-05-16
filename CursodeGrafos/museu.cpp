#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

const int MAX_S = 1000;
const int INF = numeric_limits<int>::max();

struct Edge {
    int to;
    int time;
};

int main() {
    int S, C;
    cin >> S >> C;

    vector<int> room_time(S + 1);
    for (int i = 1; i <= S; ++i) {
        cin >> room_time[i];
    }

    vector<Edge> graph[MAX_S + 1];
    for (int i = 0; i < C; ++i) {
        int I, F, T;
        cin >> I >> F >> T;
        graph[I].push_back({F, T});
    }

    int min_time = INF;

    for (int start = 1; start <= S; ++start) {
        vector<int> dist(S + 1, INF);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        dist[start] = 0; // starting point cost
        pq.push({0, start});

        while (!pq.empty()) {
            auto [current_dist, current] = pq.top();
            pq.pop();

            // If we reached the starting room again with a valid path
            if (current != start && current_dist + room_time[current] < min_time) {
                min_time = current_dist + room_time[current];
            }

            for (const Edge& edge : graph[current]) {
                int next = edge.to;
                int next_dist = current_dist + edge.time;

                // Only consider moving to a new room
                if (next != start && next_dist + room_time[next] < dist[next]) {
                    dist[next] = next_dist + room_time[next];
                    pq.push({dist[next], next});
                }
            }
        }
    }

    cout << min_time << endl;

    return 0;
}
