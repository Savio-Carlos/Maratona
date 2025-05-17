#include <bits/stdc++.h>
#define ll long long
#define maxn 500500
#define pii pair<int,int>
#define pb push_back
#define debug
using namespace std;

vector<int> L[maxn];
int dis[3][maxn];

void dfs(int x,int id,int p=-1){
	for(int i : L[x]){
		if(i == p || dis[id][i] > 0) continue;
		dis[id][i] = 1 + dis[id][x];
		dfs(i,id,x);
	}
}

int cont(int x,int d,int p){
	if(d == 0) return 1;
	int r = 0;
	for(int i : L[x])
		if(i != p)
			r += cont(i,d-1,x);
	return r;
}

int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n-1;i++){
		int a,b;
		scanf("%d%d",&a,&b), a--, b--;
		L[a].pb(b);
		L[b].pb(a);
	}
	dfs(0,0);
	int A = 0;
	for(int i=0;i<n;i++)
		if(dis[0][i] > dis[0][A])
			A = i;
	dfs(A,1);
	int B = 0;
	for(int i=0;i<n;i++)
		if(dis[1][i] > dis[1][B])
			B = i;
	dfs(B,2);
	vector<int> cent;
	for(int i=0;i<n;i++)
		if(dis[1][i] + dis[2][i] == dis[1][B] && abs(dis[1][i]-dis[2][i]) <= 1){
			cent.pb(i);
			debug("cent %d\n",i);
		}
	int diam = dis[1][B];
	ll ans = 0;
	for (auto u : cent) cout << u << " oi ";
	if(cent.size() == 1){
		cout << "entrou no if" << endl;
		ll sum = 0;
		for(int i : L[cent[0]]){
			ll u = cont(i,diam/2-1,cent[0]);
			debug("aqui u %lld\n",u);
			cout << "u: " << u << endl;
			ans -= (u*u-u)/2;
			sum += u;
		}
		ans += (sum*sum-sum)/2;
		printf("%d\n%lld\n",diam+1,ans);
		return 0;
	}
	else {
		ll A = cont(cent[0],diam/2,cent[1]);
		ll B = cont(cent[1],diam/2,cent[0]);
		
		printf("%d\n%lld\n",diam+1,A*B);
		
	}
	

}
