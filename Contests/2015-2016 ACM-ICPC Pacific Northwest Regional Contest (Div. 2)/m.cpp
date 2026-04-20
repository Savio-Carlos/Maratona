#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define int long long
#define ld long double
#define endl '\n'

#define winton ios_base::sync_with_stdio(false),cin.tie(0)

signed main(){
    winton;
    int n;
    cin >> n;
    vector<int> num(100), mark(100, 0);
    iota(all(num), 1);

    while(n--){
        string s;
        int x;
        cin >> s >> x;
        if (s == "SUBTRACT"){
            for (int i = 0; i < 100; i++){
                num[i] -= x;
                if (num[i] < 0) mark[i] = 1;
            }
        }
        else if (s == "ADD"){
                for (int i = 0; i < 100; i++){
                num[i] += x;
            }
        }
        else if (s == "MULTIPLY"){
                for (int i = 0; i < 100; i++){
                num[i] *= x;
            }
        }
        else {
            for (int i = 0; i < 100; i++){
                if (num[i] % x != 0) mark[i]=1;
                num[i] /= x;
            }
        }
    }
    cout << accumulate(all(mark), 0LL) << endl;
}

