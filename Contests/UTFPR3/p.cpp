        #include <bits/stdc++.h>
        using namespace std;
        
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
        
        #define novo(x, y) vector<x>v(y); for(auto &w:v) cin >> w;
        
        #define all(x) x.begin(), x.end()
        #define rall(x) x.rbegin(), x.rend()
        #define bg3 ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(NULL);
        #define int long signed int long
        #define endl "\n"
        
        int nxt() {
            int x;
            cin >> x;
            return x;
        }
     
        signed main(){
            bg3;
            int n = nxt();
            for(int i = 1; i <= n; i++){
                int tam = n - i;
                for(int i = 0; i < tam; i++){
                    cout << " ";
                }
                int j = i;
                while(j){
                    if(j == 1) cout << "*";
                    else cout << "* ";
                    j--;
                }
                cout << endl;
            }
            return 0;
        }