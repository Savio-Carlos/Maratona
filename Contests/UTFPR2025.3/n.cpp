#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define fastio ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);

vector<pair<int,int>> chutes = {{1,4}, {1,9}, {1,14}, {2,5}, {2,10}, {3,1}, {3,6}, {3,11}, {4,2}, {4,7}, {4,12}, 
{5,3}, {5,8}, {5,13}, {6,4}, {6,9}, {6,14}, {7,5}, {7,10}, {8,1}, {8,6}, {8,11}, {9,2}, {9,7}, {9,12}, {10,3}, {10,8}, 
{10,13}, {11,4}, {11,9}, {11,14}, {12,5}, {12,10}, {13,1}, {13,6}, {13,11}, {14,2}, {14,7}, {14,11}};

signed main(){
    // fastio;
    bool achou = false;
    int i = 0;
    while(!achou){
        auto [x,y] = chutes[i];
        cout << "? " << x << " " << y << endl;
        string ans;
        cin >> ans;
        if (ans == "A"){
            achou = true;
            break;
        } 
        i++;
    }   
    auto [x,y] = chutes[i];
    bool d = true, e = true, c = true, b = true;
    for (int i = x-1; i > 0 && e == true; i--){
        if (!e) break;
        cout << "? " << i << " " << y << endl;
        string ans;
        cin >> ans;
        if (ans == "BOOM") return 0;
        // cout << "e" << i << endl;
        if (ans == "E"){
            e = false;
            break;
        } 
    }

        for (int i = y-1; i > 0 && c; i--){
            if (!c) break;
        cout << "? " << x << " " << i << endl;
        string ans;
        cin >> ans;
        // cout << "c" << i << endl;
        if (ans == "BOOM") return 0;
        if (ans == "E"){
            c = false;
            break;
        } 
    }

    for (int i = x+1; i < 15 && d; i++){
        if (!d) break;
        cout << "? " << i << " " << y << endl;
        string ans;
        cin >> ans;
        // cout << "d" << i << endl;
        if (ans == "BOOM") return 0;
        if (ans == "E"){
            d = false;
            break;
        } 
    }

    for (int i = y+1; i < 15 && b; i++){
        if (!b) break;
        cout << "? " << x << " " << i << endl;
        string ans;
        cin >> ans;
        // cout << "b" << i << endl;
        if (ans == "BOOM") return 0;
        if (ans == "E"){
            b = false;
            break;
        } 
    }

}