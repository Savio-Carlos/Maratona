#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
#define debug(x) cout << #x << " = " << x << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";
const int MAX = 2e5+7;
const int INF = LLONG_MAX;
/*
a ideia e guardar a posicao de cada valor da permutacao em cada um dos dois arrays
para cada um desses valores eu vejo se nos dois vetores o vizinho a direita e a esquerda sao iguais
se algum vizinho for igual a gente vai indo ate serem iguais
isso para a esquerda e direita de ambos os vetores
nisso eu acho o intervalo igual
ai eu calculo o resultado
importante ter um vetor de visitados para garantir que nao vou rever o mesmo subarray mas comecando em valores diferentes
*/
int visited[MAX];

signed main(){
    winton; 
    int n, f, s;
    cin >> n >> f >> s;
    vector<int> p(n), q(n);
    map<int,int> mpq, mpp;
    for (int i = 0; i < n; i++){
        cin >> p[i];
        mpp[p[i]] = i;
    }
    for (int i = 0; i < n; i++){
        cin >> q[i];
        mpq[q[i]] = i;
    }
    int ans = INF;
    for (int i = 1; i <= n; i++){
        if (visited[i]) continue;
        visited[i] = 1;
        int lcima = mpp[i], rcima = mpp[i];
        int lbaixo = mpq[i], rbaixo = mpq[i];
        while((lcima > 0 && lbaixo > 0) && (p[lcima-1] == q[lbaixo-1])){
            lcima--;
            lbaixo--;
            visited[p[lcima]] = visited[q[lbaixo]] = 1;
        }
        while((rcima < n-1 && rbaixo < n-1) && (p[rcima+1] == q[rbaixo+1])){
            rcima++;
            rbaixo++;
            visited[p[rcima]] = visited[q[rbaixo]] = 1;
        }
        int cfrodo = lbaixo*f + lcima*f;
        int csam = (n-rbaixo-1)*s + (n-rcima-1)*s;
        ans = min(ans, max(cfrodo, csam));
    }
    cout << ans << endl;

}