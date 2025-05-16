#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define int long long
#define ld long double
const int MAXL = 1e9+7;
 
int pa(int n, int a, int b){
    return n*(a+b)/2;
}
 
bool checkSquare(int x){
    int r = (int) sqrt(x);
    return r * r == x;
}
signed main(){_
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> perm(n);
        int pa2 = pa(n,1,n);
        if (checkSquare(pa2)){cout << "-1" << endl; continue;}
        
        for(int i = 1; i <= n; i++){
            perm[i-1] = i;
        }
        swap(perm[0], perm[1]);
 
        int pfx = perm[0];
        for (int i = 1; i < n; i++){
            pfx += perm[i];
            if (i < n - 1 && checkSquare(pfx)){
                int temp = perm[i];
                perm[i] = perm[i + 1];
                perm[i + 1] = temp;
                pfx = pfx - temp + perm[i];
                
            }
        }
        for (int i : perm)cout << i << " ";
        cout << endl;
    }
}
