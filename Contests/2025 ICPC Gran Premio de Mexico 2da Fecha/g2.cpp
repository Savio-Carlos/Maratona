#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define endl '\n'
#define ll long long
#define ld long double

struct Point {
    ll x, y, z;
};

// Define os semiplanos para o sort polar exato
// Half 0: y > 0 ou (y == 0 e x > 0)
// Half 1: y < 0 ou (y == 0 e x < 0)
int half(ll dx, ll dy) {
    if (dy > 0 || (dy == 0 && dx > 0)) return 0;
    return 1;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << fixed << setprecision(10);

    int n;
    ld h_in;
    if (!(cin >> n >> h_in)) return 0;

    // 1. Leitura e remoção de ilhas na EXATA mesma posição (mantém maior Z)
    map<pair<ll, ll>, ll> best;
    for (int i = 0; i < n; i++) {
        ld x, y, z;
        cin >> x >> y >> z;
        // Multiplica por 100 para transformar em inteiro exato sem perder 2 casas decimais
        ll X = llround(x * 100.0L);
        ll Y = llround(y * 100.0L);
        ll Z = llround(z * 100.0L);
        
        if (best.count({X, Y})) best[{X, Y}] = max(best[{X, Y}], Z);
        else best[{X, Y}] = Z;
    }

    ld cx, cy;
    cin >> cx >> cy;
    ll CX = llround(cx * 100.0L);
    ll CY = llround(cy * 100.0L);

    vector<Point> points;
    for (auto [pt, Z] : best) {
        if (pt.first == CX && pt.second == CY) continue; // Cookie não pode ser ilha
        // Translação imediata: O Cookie vira a origem (0,0)
        points.push_back({pt.first - CX, pt.second - CY, Z});
    }

    // 2. Polar Sort Exato: Usa apenas __int128_t (NUNCA double ou atan2)
    sort(points.begin(), points.end(), [&](const Point& a, const Point& b) {
        int ha = half(a.x, a.y);
        int hb = half(b.x, b.y);
        if (ha != hb) return ha < hb; // Semiplanos diferentes
        
        __int128_t cr = (__int128_t)a.x * b.y - (__int128_t)a.y * b.x;
        if (cr != 0) return cr > 0; // Cross product desempata angularmente
        
        // Empate perfeito de ângulo: tanto faz a ordem de distância aqui
        return a.x * a.x + a.y * a.y < b.x * b.x + b.y * b.y;
    });

    // 3. Extração das alturas únicas para a Busca Binária Discreta
    vector<ll> zes;
    for (const auto& p : points) zes.push_back(p.z);
    sort(all(zes));
    zes.erase(unique(all(zes)), zes.end());

    // 4. Função de Validação (A Joia da Coroa)
    auto check = [&](ll mid) -> bool {
        auto cross = [&](const Point& a, const Point& b) -> __int128_t {
            return (__int128_t)a.x * b.y - (__int128_t)a.y * b.x;
        };
        auto dot = [&](const Point& a, const Point& b) -> __int128_t {
            return (__int128_t)a.x * b.x + (__int128_t)a.y * b.y;
        };

        // Filtra ilhas afundadas
        vector<Point> temp;
        for (const auto& p : points) {
            if (p.z >= mid) temp.push_back(p);
        }

        if (temp.size() < 3) return false;

        // --- O CÓDIGO QUE CORRIGE O WA 7 (RADIAL DEDUPLICATION) ---
        // Só queremos UMA ilha por direção (raio). Várias ilhas no mesmo ângulo não formam triângulo.
        vector<Point> uniq;
        for (const auto& p : temp) {
            if (uniq.empty()) {
                uniq.push_back(p);
            } else {
                Point last = uniq.back();
                // Estão no mesmo raio? (Produto Vetorial = 0 e Mesma Direção)
                if (cross(last, p) == 0 && dot(last, p) > 0) continue; // Ignora duplicatas radiais
                uniq.push_back(p);
            }
        }
        
        // Cuidado com o "Wrap-Around" do círculo: o último e o primeiro podem estar no mesmo raio
        while (uniq.size() >= 2) {
            Point first = uniq[0];
            Point last = uniq.back();
            if (cross(last, first) == 0 && dot(last, first) > 0) {
                uniq.pop_back();
            } else {
                break;
            }
        }
        // ------------------------------------------------------------

        int m = (int)uniq.size();
        if (m < 3) return false;

        // Duplica o array de pontos únicos para simular o círculo
        vector<Point> arr(2 * m);
        for (int i = 0; i < m; i++) {
            arr[i] = uniq[i];
            arr[i + m] = uniq[i];
        }

        vector<int> R(m);
        int j = 0;
        
        // Two-Pointers O(M) sobre os raios únicos
        for (int i = 0; i < m; i++) {
            j = max(j, i);
            while (j + 1 < i + m) {
                Point a = arr[i];
                Point b = arr[j + 1];
                __int128_t cr = cross(a, b);
                
                // Como já removemos colineares exatos do mesmo lado, 
                // qualquer cr <= 0 significa que passou de 180 graus ou bateu exatamente em 180 graus.
                if (cr > 0) j++;
                else break;
            }
            R[i] = j;
        }

        // Simulação dos 3 saltos. Se conseguirmos dar a volta (>= i + m), o triângulo existe!
        for (int i = 0; i < m; i++) {
            int step1 = R[i];
            int step2 = R[step1 % m] + (step1 / m) * m; // Avança mantendo as voltas do círculo
            int step3 = R[step2 % m] + (step2 / m) * m;
            
            if (step3 >= i + m) return true;
        }

        return false;
    };

    if (zes.empty()) {
        cout << -1 << endl;
        return 0;
    }

    // 5. Busca Binária Discreta
    int l = 0, r = zes.size() - 1;
    int best_idx = -1;

    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (check(zes[mid])) {
            best_idx = mid;
            l = mid + 1; // Água mais alta = menos tempo esperado
        } else {
            r = mid - 1; // Precisa baixar a água
        }
    }

    // 6. Resposta Final
    if (best_idx == -1) {
        cout << -1 << endl;
    } else {
        ld best_mid = (ld)zes[best_idx] / 100.0L;
        cout << max<ld>(0.0L, h_in - best_mid) << endl; // Se h_in for menor, já está pronto (0 horas)
    }

    return 0;
}