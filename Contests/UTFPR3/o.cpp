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
            for(int i = 0; i < n; i++) cout << "*";
            cout << endl;

            for(int i = 0; i < n-2; i++){
                cout << "*";
                for(int j = 0; j < n-2; j++){
                    if(i == j || i + j == n-2-1) cout << "*";
                    else cout << " ";
                }
                cout << "*";
                cout << endl;
            }



            for(int i = 0; i < n; i++) cout << "*";
            cout << endl;
            return 0;
        }