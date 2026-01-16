#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define endl '\n'

#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

map<string,int> weekday;
void init(){
    weekday["Mon"] = 1;
    weekday["Tue"] = 2;
    weekday["Wed"] = 3;
    weekday["Thu"] = 4;
    weekday["Fri"] = 5;
    weekday["Sat"] = 6;
    weekday["Sun"] = 7;
}

void print(int x, string s1, string s2){
    if(x > 1) cout << x << " " << s1 << "s" << s2 << " ";
    else cout << x << " " << s1 << s2 << " ";
}


signed main(){
    fastio;
    init();
    string week1, time1, week2, time2;
    cin >> week1 >> time1 >> week2 >> time2;
    int h1 = 0, m1 = 0, h2 = 0, m2 = 0, h3 = 0, m3 = 0, w1 = 0, w2 = 0, w3 = 0;
    m1 += time1[4] - '0';
    m1 += (time1[3] - '0') * 10;
    h1 += time1[1] - '0';
    h1 += (time1[0] - '0') * 10;

    m2 += time2[4] - '0';
    m2 += (time2[3] - '0') * 10;
    h2 += time2[1] - '0';
    h2 += (time2[0] - '0') * 10;

    if(week1 == week2 && time1 == time2) {
        cout << "7 days" << endl;
        return 0;
    }

    // cout << h1 << " " << m1 << " " << h2 << " " << m2 << endl;

    m3 = m2 - m1;
    if(m3 < 0) {
        m3 += 60;
        h3--;
    }

    h3 += h2 - h1;
    if(h3 < 0) {
        w3--;
        h3 += 24;
    }

    w3 += weekday[week2] - weekday[week1];
    if(w3 < 0) {
        w3 += 7;
    }

    // cout << week1 << " " << week2 << endl;
    // cout << weekday[week1] << " " << weekday[week2] << endl;


    if(w3 != 0 && h3 != 0 && m3 != 0){

        print(w3, "day", ",");
        print(h3, "hour", ",");
        print(m3, "minute", "");

    } else if(w3 != 0 && h3 != 0){

        print(w3, "day", " and");
        print(h3, "hour", "");

    } else if(w3 != 0 && m3 != 0){
        print(w3, "day", " and");
        print(m3, "minute", "");
    } else if (h3 != 0 && m3 != 0){

        print(h3, "hour", " and");
        print(m3, "minute", "");

    } else if (w3 != 0){

        print(w3, "day", "");

    } else if(h3 != 0){
        print(h3, "hour", "");
    } else if(m3 != 0){
        print(m3, "minute", "");
    }

    cout << endl;

}