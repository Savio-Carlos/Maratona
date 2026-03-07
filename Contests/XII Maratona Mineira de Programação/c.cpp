#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define fastio ios_base::sync_with_stdio(false),cout.tie(0),cin.tie(0)

int m(int l, int r){
    return (r - l)/2 +l;
}

/*
A joga a maior carta
sum1 += a.back()
jogada do B:
    if(b.back() > sum1) sum2 += b.back()
    else sum2 += b.front()
    se a maior carta do B for maior q a do A, jogue a maior
    else jogue a menor
jogada do C:
    se sum1 > sum2
        sum1 += c.front()
    else sum1 += c.back()
jogada do D:
    se sum2 + b.back() > sum1 
        sum2 += b.back()
    else sum2 += b.front()

*/

map<string, int> mp1 = {
    {"4P", 15},
    {"7C", 14},
    {"AE", 13},
    {"7O", 12},
};

map<char, int> mp2 = {
    {'3', 11},
    {'2', 10},
    {'A', 9},
    {'K', 8},
    {'J', 7},
    {'Q', 6},
    {'7', 5},
    {'6', 4},
    {'5', 3},
    {'4', 2},
};

signed main(){
    fastio;
    vector<vector<int>> vec(4);
    vector<deque<int>> v(4);
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 3; j++){
            string s; cin >> s;
            //if(s == "7O") cout << "ue\n";
            if(s == "4P" || s == "7C" || s == "AE" || s == "7O"){
                //cout << mp1[s] << " ";
                vec[i].push_back(mp1[s]);
            }else{
                //cout << mp2[s[0]] << " ";
                vec[i].push_back(mp2[s[0]]);
            }
        }
        //cout << endl;
    }

    for(int i = 0; i < 4; i++){
        sort(vec[i].begin(), vec[i].end());
        for(auto u : vec[i]){
            //cout << u << " ";
            v[i].push_back(u);
        }
        //cout << endl;
    }

    // for(int i = 0; i < 4; i++){
    //     for(auto u : vec[i]){
    //         cout << u << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;

    for(int j = 0; j < 3; j++){
        int mx = 0;
        //A
        int sum1 = v[0].back(), sum2 = 0;
        v[0].pop_back();
        //cout << sum1 << " ";
        //B
        int k = 0;
        if(v[1].back() <= sum1){
            k = v[1].front();
            sum2 = v[1].front();
            v[1].pop_front();
        }else{
            k = v[1].back();
            sum2 = v[1].back();
            v[1].pop_back();
        }
        //cout << k << " ";
        //C
        if(sum1 > sum2 || (sum1 < sum2 && v[2].back() <= sum2)){
            k= v[2].front();
            sum1 = max(sum1, v[2].front());
            v[2].pop_front();
        }else{
            k = v[2].back();
            sum1 = max(sum1, v[2].back());
            v[2].pop_back();
        }
        //cout << k << " ";
        //D
        if(sum2 > sum1 || (sum2 < sum1 && v[3].back() <= sum1)){
            k = v[3].front();
            sum2 = max(sum2, v[3].front());
            v[3].pop_front();
        }else{
            k = v[3].back();
            sum2 = max(sum2, v[3].back());
            v[3].pop_back();
        }

        //cout << k << endl;

        if(sum1 == sum2) cout << 0;
        else if(sum1 > sum2) cout << 1;
        else cout << 2;

        if(j == 2) cout << endl;
        else cout << " ";
    }
}

/*
A joga a maior carta
sum1 += a.back()
jogada do B:
    if(b.back() > sum1) sum2 += b.back()
    else sum2 += b.front()
    se a maior carta do B for maior q a do A, jogue a maior
    else jogue a menor
jogada do C:
    se sum1 > sum2
        sum1 += c.front()
    else sum1 += c.back()
jogada do D:
    se sum2 + b.back() > sum1 
        sum2 += b.back()
    else sum2 += b.front()

*/
