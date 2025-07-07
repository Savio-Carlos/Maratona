#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define minecraft cin.tie(0)->sync_with_stdio(0);
#define endl "\n"
const ll MOD = 1e9+7;
const ll INF = 2e5;
 
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
 
 
 
 
 
int main (){
    minecraft;
 
    ll t=1;
    //cin>>t;
 
    while(t--){
        
    string s,m,k;

    cin>>s>>m;

    k+=s;
    k+=m;
    
    if(k.size()%2==0){
        cout<<"MATCH"<<endl;
    }
    else cout<<"NO MATCH"<<endl;

}
}
