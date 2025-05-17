#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
const int MAXS = 1e5+7;

int n, m;
int bit[2][MAXS];

void upd(int d, int x){
    for (; x < MAXS; x += (x&-x)){
        bit[d][x]++;
    }
}

void reset(int d, int x){
    for (; x < MAXS; x += (x&-x)){
        bit[d][x]--;
    }
}

int sum(int d, int x){
    int ans = 0;
    for(; x > 0; x -= (x&-x)){
        ans += bit[d][x];
    }
    return ans;
}

int qry(int l, int r, int d){
    return sum(d,r) - sum(d, l-1); 
}

signed main () {
    winton;
    cin >> n >> m;
    int q;
    cin >> q;
    int countR[MAXS], countC[MAXS];
    while(q--){
        char a;
        cin >> a;
        if (a == 'A'){
            int r, c;
            cin >> r >> c;
            if (!countR[r]){
                upd(0, r);
            }
            if (!countC[c]){
                upd(1, c);
            }
            countC[c]++;countR[r]++;
        }
        else if (a == 'R'){
            int r, c;
            cin >> r >> c;
            countR[r]--;countC[c]--;
            if (!countR[r]){
                reset(0, r);
            }
            if (!countC[c]){
                reset(1, c);
            }
        }
        else if(a == 'Q'){
            int x1,x2,y1,y2;
            cin >> x1 >> y1 >> x2 >> y2;
            int expectedX = x2-x1+1;
            int expectedY = y2-y1+1;
            int realX = qry(x1,x2,0);
            int realY = qry(y1,y2,1);
            if ((expectedX - realX) > 0 && (expectedY - realY) > 0){
                cout << "N" << endl;
            }
            else cout << "S" << endl;
        }
    }

}