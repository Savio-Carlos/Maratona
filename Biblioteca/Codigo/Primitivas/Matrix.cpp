struct matrix : vector<vector<int>> {
    int n, m;

    matrix(int n_, int m_, bool ident = false) : vector<vector<int>>(n_, vector<int>(m_, 0)), n(n_), m(m_) {
        if (ident) {
            assert(n == m);
			for (int i = 0; i < n; i++) (*this)[i][i] = 1;
		}
	}

    matrix(const vector<vector<int>>& c) : vector<vector<int>>(c),
    n(c.size()), m(c[0].size()) {}

    matrix operator*(const matrix &a) const {
        assert(m == a.n);
        matrix res(n, a.m);
        for (int i = 0; i < n; i++){
            for (int j = 0; j < a.m; j++){
                for (int k = 0; k < m; k++){
                    res[i][j] = (res[i][j] + ((*this)[i][k] * a[k][j]) % MOD) % MOD;
                }
            }
        }
        return res;
    }

    matrix operator^(int e) const {
        matrix res(n,n,true);
        matrix base = *this;
        while (e) {
            if (e&1) res = res * base;
            base = base * base;
            e >>= 1;
        }
        return res;
    }
};