// Sparse Table
//
// Resolve RMQ
//
// Complexidades:
// build - O(n log(n))
// query - O(1)

namespace sparse {
	int m[LOG+1][MAX], n;
	void build(int n2, int* v) {
		n = n2;
		for (int i = 0; i < n; i++) m[0][i] = v[i];
		for (int j = 1; (1<<j) <= n; j++) for (int i = 0; i+(1<<j) <= n; i++)
			m[j][i] = min(m[j-1][i], m[j-1][i+(1<<(j-1))]);
	}
	int query(int a, int b) {
		int j = __builtin_clz(1) - __builtin_clz(b-a+1);
		return min(m[j][a], m[j][b-(1<<j)+1]);
	}
}

template <typename T>
struct SparseTable {
	vector<vector<T>> m;
	
	SparseTable(vector<T>& v) {
		int n = v.size();
		int max_log = 32 - __builtin_clz(n);
		m.assign(max_log, vector<T>(n));
		for (int i = 0; i < n; i++) m[0][i] = v[i];
		for (int j = 1; j < max_log; j++) {
			for (int i = 0; i + (1<<j) <= n; i++) {
				m[j][i] = min(m[j-1][i], m[j-1][i+(1<<(j-1))]);
			}
		}
	}
	
	T query(int a, int b) {
		int j = __builtin_clz(1) - __builtin_clz(b-a+1);
		return min(m[j][a], m[j][b-(1<<j)+1]);
	}
};

// Sparse Table para Bitmasks
// Utiliza OR bit a bit (|) para combinar conjuntos ou atributos de um intervalo.
// Muito util para problemas com restricoes pequenas (ex: K <= 64), permitindo
// substituir K Sparse Tables por apenas 1 (ex: usando unsigned long long).
template <typename T>
struct SparseTableMask {
	vector<vector<T>> m;
	
	SparseTableMask(vector<T>& v) {
		int n = v.size();
		int max_log = 32 - __builtin_clz(n);
		m.assign(max_log, vector<T>(n));
		for (int i = 0; i < n; i++) m[0][i] = v[i];
		for (int j = 1; j < max_log; j++) {
			for (int i = 0; i + (1<<j) <= n; i++) {
				m[j][i] = (m[j-1][i] | m[j-1][i+(1<<(j-1))]);
			}
		}
	}
	
	T query(int a, int b) {
		int j = __builtin_clz(1) - __builtin_clz(b-a+1);
		return (m[j][a] | m[j][b-(1<<j)+1]);
	}
};
