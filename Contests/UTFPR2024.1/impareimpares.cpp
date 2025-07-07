#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ll N, ans1 = 0, ans2 = 0, imparmaior1 = 0, imparmaior2 = 0, nimpar = 0;
    cin >> N;
    vector<ll> arr(N);
    vector<ll> arr1(N);
    vector<ll> arr2(N);

    for (int i = 0; i < N; i++){
        cin >> arr[i];
        arr1[i] = arr2[i] = arr[i];
        if (arr[i] %2 != 0){
            nimpar++;
            imparmaior1 = max(imparmaior1,arr[i]);
            imparmaior2 = max(imparmaior2,arr[i]);
        }
    }
    if (nimpar == 0) {
        cout << "-1" << endl;
        return 0;
    }

    sort(arr1.rbegin(),arr1.rend());
    sort(arr2.begin(),arr2.end());

    for (int i = 0; i < N; i++){
        if (arr1[i] %2 == 0 && arr1[i] < imparmaior1){
            arr1[i] += imparmaior1;
      
            ans1++;
            imparmaior1 = arr1[i];
        }
        else if (arr1[i] %2 == 0 && arr1[i] > imparmaior1){
          
            imparmaior1+=arr1[i];
            arr1[i] += imparmaior1;
            ans1+=2;
            imparmaior1 = arr1[i];
        }
    }
        for (int i = 0; i < N; i++){
        if (arr2[i] %2 == 0 && arr2[i] < imparmaior2){
            arr2[i] += imparmaior2;
            ans2++;
            imparmaior2 = arr2[i];
        }
        else if (arr2[i] %2 == 0 && arr2[i] > imparmaior2){
          
            imparmaior2+=arr2[i];
            arr2[i] += imparmaior2;
            ans2+=2;
            imparmaior2 = arr2[i];
        }
    }
    //cout << ans1 << " " << ans2 << endl;
    cout << min(ans1,ans2) << endl;

}
