#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>

using namespace std;

using ll = long long;
const int MAX = 200005;
const ll INF = 1e18; // Usado para representar o elemento neutro da operação de máximo

// --- Início da Segment Tree (modificada para MÁXIMO) ---
namespace seg {
	ll tree[4 * MAX];
    int n_nodes;

	void build(int n, ll v[]) {
        n_nodes = n;
		function<void(int, int, int)> build_recursive = 
            [&](int i, int l, int r) {
			if (l == r) {
				tree[i] = v[l];
				return;
			}
			int mid = l + (r - l) / 2;
			build_recursive(2 * i, l, mid);
			build_recursive(2 * i + 1, mid + 1, r);
			// MODIFICAÇÃO: Usar max() em vez de soma
			tree[i] = max(tree[2 * i], tree[2 * i + 1]);
		};
		build_recursive(1, 0, n - 1);
	}

	void update(int node_idx, ll val) {
		function<void(int, int, int)> update_recursive = 
            [&](int i, int l, int r) {
			if (l == r) {
				tree[i] = val;
				return;
			}
			int mid = l + (r - l) / 2;
			if (node_idx <= mid) {
				update_recursive(2 * i, l, mid);
			} else {
				update_recursive(2 * i + 1, mid + 1, r);
			}
			// MODIFICAÇÃO: Usar max() em vez de soma
			tree[i] = max(tree[2 * i], tree[2 * i + 1]);
		};
		update_recursive(1, 0, n_nodes - 1);
	}

	ll query(int ql, int qr) {
		function<ll(int, int, int)> query_recursive = 
            [&](int i, int l, int r) -> ll {
			if (ql > r || qr < l) {
				// MODIFICAÇÃO: Retornar 0, pois os valores dos nós são >= 1.
                // Um valor "negativo infinito" seria o elemento neutro ideal.
				return 0;
			}
			if (ql <= l && r <= qr) {
				return tree[i];
			}
			int mid = l + (r - l) / 2;
			ll left_res = query_recursive(2 * i, l, mid);
			ll right_res = query_recursive(2 * i + 1, mid + 1, r);
			// MODIFICAÇÃO: Usar max() em vez de soma
			return max(left_res, right_res);
		};
		return query_recursive(1, 0, n_nodes - 1);
	}
}
// --- Fim da Segment Tree ---

// --- Início do HLD (adaptado para MÁXIMO) ---
namespace hld {
	vector<int> g[MAX];
	int pos[MAX], sz[MAX];
	ll peso[MAX]; // Alterado para ll para suportar valores grandes
    int pai[MAX];
	int h[MAX];
    ll v[MAX]; // Array para a Segment Tree
    int t;

	// Usando a implementação de build HLD original solicitada
	void build_hld(int k, int p = -1, int f = 1) {
		v[pos[k] = t++] = peso[k]; 
		sz[k] = 1;
		for (auto& i : g[k]) {
			if (i == p) continue;
			pai[i] = k;
			h[i] = (i == g[k][0] ? h[k] : i);
			build_hld(i, k, f); 
			sz[k] += sz[i];

			if (g[k][0] == p || sz[i] > sz[g[k][0]]) {
				swap(i, g[k][0]);
			}
		}
		if (p*f == -1) build_hld(h[k] = k, -1, t = 0);
	}

	void build(int root, int n) {
		t = 0;
		build_hld(root);
		seg::build(n, v);
	}

	ll query_path(int a, int b) {
		ll res = 0; // O elemento neutro para o máximo
		while (h[a] != h[b]) {
			if (pos[a] < pos[b]) swap(a, b);
			// MODIFICAÇÃO: Combina resultados com max()
			res = max(res, seg::query(pos[h[a]], pos[a]));
			a = pai[h[a]];
		}
		if (pos[a] > pos[b]) swap(a, b);
		// MODIFICAÇÃO: Combina o resultado final com max()
		res = max(res, seg::query(pos[a], pos[b]));
		return res;
	}
    
    // NOVA FUNÇÃO: Atualiza o valor de um único nó
    void update_node(int node, ll value) {
        peso[node] = value;
        seg::update(pos[node], value);
    }
}
// --- Fim do HLD ---

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, q;
	cin >> n >> q;

	for (int i = 1; i <= n; ++i) {
		cin >> hld::peso[i];
	}

	for (int i = 0; i < n - 1; ++i) {
		int u, v_node;
		cin >> u >> v_node;
		hld::g[u].push_back(v_node);
		hld::g[v_node].push_back(u);
	}

	// Construir a HLD e a Segment Tree a partir do nó 1
	hld::build(1, n);

	for (int i = 0; i < q; ++i) {
		int type;
		cin >> type;
		if (type == 1) {
			int s;
            ll x;
			cin >> s >> x;
            hld::update_node(s, x);
		} else {
			int a, b;
			cin >> a >> b;
			cout << hld::query_path(a, b) << (i == q - 1 ? "" : " ");
		}
	}
	cout << endl;

	return 0;
}

