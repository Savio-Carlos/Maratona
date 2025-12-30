#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

struct Team{
    int pending = 0;
    int accepted = 0;
    bool torcendo = false;
};

void ac_sort(vector<Team> &t){
    sort(rall(t),
        [](const Team &x, const Team &y){ return x.accepted < y.accepted; });
}

void pend_sort(vector<Team> &t){
    sort(all(t),
        [](const Team &x, const Team &y){ return x.pending < y.pending; });
}

void trocar(vector<Team> &t, int idx, int qnt){
    while(qnt--){
        swap(t[idx], t[idx-1]);
        idx--;
    }
}

signed main(){
    // fastio;
    int n, m, r, pending_count = 0;
    cin >> n >> m >> r;
    vector<Team> v(n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            char a;
            cin >> a;
            if(a == 'A') v[i].accepted++;
            else if(a == 'P') {
                v[i].pending++;
                pending_count++;
            }
        }
    }

    // ac_sort(v);
    v[r-1].torcendo = true;




    // for(int i = 0; i < n; i++){
    //     cout << v[i].accepted << " " << v[i].pending << endl;
    // }

    for(int i = 0; i < pending_count; i++){
        int j = n-1;
        while(v[j].pending == 0){
            j--;
        }

        string lixo, s;
        cin >> lixo >> s;
        int ypslons = 0;
        for(int k = 0; k < s.size(); k++){
            if(s[k] == 'y') ypslons++;
        }

        // cout << j << " " << ypslons << endl;

        v[j].pending--;

        if(ypslons == 0) continue;

        trocar(v, j, ypslons-3);

        

        // cout << 'i' << endl;
    }

    for(int i = 0; i < n; i++){
        if(v[i].torcendo) cout << i + 1 << endl;
    }
}