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
        #define int unsigned long long
        #define endl "\n"
        
        int nxt() {
            int x;
            cin >> x;
            return x;
        }
     
        signed main(){
            bg3;
            int n = nxt(), p = nxt(), k = nxt();
            int cnt = 0;

            vector<int> v(25);
            for(int i = 0; i < 25; i++){
                v[i] = i+1;
            }
            // cout << v << endl;


            vector<int> ans;

            for(int i = 0; i < (1<<25); i++){
                int quantos_bits = __builtin_popcount(i);
                if (quantos_bits == p) {
                    cnt++;
                    if (cnt == k){
                        // cout << quantos_bits << endl;
                        for(int j = 0; j < 25; j++){
                            // cout << (1 << j) << endl;
                            if((1 << j) & i){
                                ans.push_back(v[j]);
                                // cout << v[j] << " ";
                            }
                        }
                        // cout << endl;
                    }
                }
                
            }

            reverse(all(ans));
            cout << ans << endl;
            return 0;
        }