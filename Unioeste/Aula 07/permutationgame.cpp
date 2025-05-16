#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL);
using namespace std;
#define endl '\n'
#define int long long
const int MAXL = 1e6+7;

int solve (vector<int> &arr, vector<int> &per, int start, int k){
    int cur = per[start];
    int sum = arr[start];
    int maior = sum*k;
    k--;
    while(k > 0 && cur!=start){
        maior = max(maior, sum+arr[cur]*k);
        sum+=arr[cur];
        cur = per[cur];
        k--;
    }
    return maior;
}


signed main() {_
    int t;
    cin >> t;
    while(t--){
        int n, k, bd, sh;
        
        cin >> n >> k >> bd >> sh;
        vector<int> arr(n);
        vector<int> per(n);

        for (int i = 0; i < n; i++){
            cin >> per[i];
            per[i]--;
        }
        for (int i = 0; i < n; i++){
            cin >> arr[i];
        }

        int scorebd = solve(arr,per,bd-1,k);
        int scoresh = solve(arr,per,sh-1,k);

        if (scorebd > scoresh) cout << "Bodya" << endl;
        else if (scorebd < scoresh) cout << "Sasha" << endl;
        else cout << "Draw" << endl;
    }


}