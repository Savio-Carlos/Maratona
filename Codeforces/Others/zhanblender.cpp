    #include <bits/stdc++.h>
    using namespace std;
    #define ll long long


    int main() {
        ll n, x, y, mini;
        int t;
        cin>> t;
        while (t--){
            cin >> n >> x >> y;
            mini = min (x,y);
            cout << (n+mini-1)/mini << endl;
        }
        
    }
   // ceil(n/mini)