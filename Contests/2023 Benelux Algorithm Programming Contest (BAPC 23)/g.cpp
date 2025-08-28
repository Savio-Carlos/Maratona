#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define minecraft cin.tie(0)->sync_with_stdio(0);
#define endl "\n"
// const ll MOD = 1e9+7;
// const ll INF = 2e5;

template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v) {
    for (size_t i = 0; i < v.size(); ++i) {
        os << v[i];
        if (i + 1 < v.size()) os << ' ';
    }
    return os;
}

template <typename T>
ostream &operator<<(ostream &os, const vector<vector<T>> &matrix) {
    for (size_t i = 0; i < matrix.size(); ++i) {
        os << matrix[i];
        if (i + 1 < matrix.size()) os << '\n';
    }
    return os;
}




pair<long double,long double> reta(pair<long double,long double> p1, pair<long double,long double>p2){
    long double dx,dy;
    dx = p1.first-p2.first;
    dy = p1.second-p2.second;
    // if(p1.first>=p2.first){
    //     dx = p1.first-p2.first;
    // } else {
    //     dx = p2.first-p1.first;
    // }
    // if(p1.second>=p2.second){
    //     dy = p1.second-p2.second;
    // } else {
    //     dy = p2.second-p1.second;
    // }
    return {dx,dy};
}


long double dis(pair<long double,long double>p1,pair<long double,long double>p2){
    return hypot(p1.second-p2.second,p1.first-p2.first);
}

long double angulo(vector<pair<long double,long double>> pontos){

    pair<long double,long double> r1 = reta(pontos[0],pontos[1]);
    pair<long double,long double> r2 = reta(pontos[1],pontos[2]);
    pair<long double,long double> r3 = reta(pontos[2],pontos[3]);
    pair<long double,long double> r4 = reta(pontos[3],pontos[0]);

    int res=0;

    long double ang1 = (r1.first * r4.first + r1.second * r4.second) / (dis(pontos[0],pontos[1]) * dis(pontos[3],pontos[0]));
    long double ang2 = (r1.first * r2.first + r1.second * r2.second) / (dis(pontos[0],pontos[1]) * dis(pontos[1],pontos[2]));
    long double ang3 = (r2.first * r3.first + r2.second * r3.second) / (dis(pontos[1],pontos[2]) * dis(pontos[2],pontos[3]));
    long double ang4 = (r3.first * r4.first + r3.second * r4.second) / (dis(pontos[2],pontos[3]) * dis(pontos[3],pontos[0]));


   return !ang1+!ang2+!ang3+!ang4;
   

}


int paralelos(vector<pair<long double,long double>> pontos){
    int qnt = 0;
    pair<long double,long double> r1 = reta(pontos[0],pontos[1]);
    pair<long double,long double> r2 = reta(pontos[3],pontos[2]);
    //cout<<r1.first/r1.second<<" "<<r2.first/r2.second<<endl;
    if(r1.first/r1.second == r2.first/r2.second) qnt++;
    r1 = reta(pontos[1],pontos[2]);
    r2 = reta(pontos[0],pontos[3]);
    //cout<<r1.first<<" "<<r1.second<<" "<<r2.first<<" "<<r2.second<<endl;
    //cout<<r1.first/r1.second<<" "<<r2.first/r2.second<<endl;
    if(r1.first/r1.second == r2.first/r2.second) qnt++;
    return qnt;
}

int lado(vector<pair<long double,long double>>pontos){
    int qnt=0;
    long double dis1 = dis(pontos[0],pontos[1]);
    long double dis2 = dis(pontos[1],pontos[2]);
    long double dis3 = dis(pontos[2],pontos[3]);
    long double dis4 = dis(pontos[3],pontos[0]);
    if(dis1 == dis2)qnt++;
    if(dis1 == dis3)qnt++;
    if(dis1 == dis4)qnt++;
    if(dis2 == dis3)qnt++;
    if(dis2 == dis4)qnt++;
    if(dis3 == dis4)qnt++;
    return qnt;
}


vector<long double> tamanho(vector<pair<long double,long double>> pontos){
    long double r1 = dis(pontos[0],pontos[1]);
    long double r2 = dis(pontos[1],pontos[2]);
    long double r3 = dis(pontos[2],pontos[3]);
    long double r4 = dis(pontos[3],pontos[0]);
    return {r1,r2,r3,r4};
}
 
signed main (){
     minecraft;
    vector<pair<long double,long double>> p(4);
    for(int i=0;i<4;i++){
        cin>>p[i].first>>p[i].second;
    }
    int para=paralelos(p);
    int ang=angulo(p);
    int lad=lado(p);
    //cout<<para<<" "<<ang<<" "<<lad<<endl;
    if(para == 2 && lad == 6 && ang == 4) cout<<"square"<<endl;
    else if (para == 2 && lad == 2 && ang == 4) cout<<"rectangle"<<endl;
    else if (para == 2 && lad == 6) cout<<"rhombus"<<endl;
    else if (para == 2 && lad == 2) cout<< "parallelogram"<<endl;
    else if (para == 1) cout<<"trapezium"<<endl;
    else if (lad == 2) cout<<"kite"<<endl;
    else cout<<"none"<<endl;


}