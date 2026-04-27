#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define int long long
#define ld long double
#define endl '\n'

#define winton ios_base::sync_with_stdio(false),cin.tie(0)

const int MAX = 2e5+7;

signed main(){
    winton;
    int n;
    cin >> n;
    vector<int> fi(n+1, 0);
    for (int i = 2; i <= n; i++){
        int p;
        cin >> p;
        fi[p]++;
    }
    fi[0] = 1;

    vector<int> groups;
    for (int i = 0; i <= n; i++){
        // cout << "fi: " << fi[i] << " ";
        if (fi[i])groups.push_back(fi[i]);
    }
    
    int mn = groups.size();
    int mx = n;
    // cout << mn << " " << mx << endl;
    
    int ans = 0;
    int m = groups.size();
    int l = mn, r = mx;
    sort(rall(groups));//todoos os grupos

    auto check = [&] (int mid) -> bool{
        /*
        vou colocar as fofocas sempre pelo maior grupo
        se esse grupo tem tamanha 6, e meu mid e 3, e esse e o primeiro dia desses 3
        entao esse boato vai se espalhar 2 vezes, totalizando 3 caras sabidos
        como isso e menor que 6, retorna falso
        */
       
        int need = 0;
        for (int i = 0; i < m; i++){
            int sabido = mid - i;
            need += max<int>(0, groups[i] - sabido);
        }
        return need+m <= mid;

    };

    while (l <= r){
        int mid = l + (r-l)/2;//number of days
        if (check(mid)){
            ans = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }
    
    cout << ans << endl;
}