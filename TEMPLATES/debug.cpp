#define debug(x) cout << #x << " = " << x << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";

// Generic printer for vector<T>
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v) {
    for (size_t i = 0; i < v.size(); ++i) {
        os << v[i];
        if (i + 1 < v.size()) os << ' ';
    }
    return os;
}

// Specialized printer for vector<vector<T>> (matrix)
template <typename T>
ostream &operator<<(ostream &os, const vector<vector<T>> &matrix) {
    for (size_t i = 0; i < matrix.size(); ++i) {
        os << matrix[i];
        if (i + 1 < matrix.size()) os << '\n';
    }
    return os;
}
