#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> v(n);

    int maior_impar = -1;

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        if(v[i] % 2 && v[i] > maior_impar) maior_impar = v[i];
    }

    if(maior_impar == -1){
        cout << -1 << endl;
        return 0;
    }

    sort(v.begin(), v.end());    
    bool aconteceu = false;

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if(v[i] % 2 == 0){
            ans ++;
            if(v[i] > maior_impar){
                aconteceu = true;
            }
            maior_impar += v[i];
        }
    }
    
    cout << ans + aconteceu << endl;

}