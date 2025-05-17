#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
const int MAX = 2e5+14;

int arr[MAX], total[MAX]; 
map<pair<int,int>, int> answers;
vector<vector<int>> graph;

struct node{
    map<int,int> freq;
    int sum;  
};

node dfs(int v, int p){
    node cur;
    cur.sum = 0;
    cur.freq[arr[v]] = 1;
    for (auto u : graph[v]){
        if (u == p) continue;
        node filho = dfs(u,v);
        if (filho.freq.size() > cur.freq.size()) swap(filho,cur);
        for (auto [c,q] : filho.freq){
            cur.freq[c] += q;
        }
    }
    cur.sum = 0;
    //cout << p << " -> " << v << endl;
    for (auto [c,q] : cur.freq){
        cur.sum += q * (total[c] - q);
       // cout << "soma: " << cur.sum << " cor: " << c << " qtd: " << q  << " total[c]: " << total[c]<< endl;
    }
    answers[{p,v}] = cur.sum;
    return cur;
}

signed main(){
    winton;
    int n;  
    cin >> n;
    graph.resize(n);
    vector<pair<int,int>> edges(n-1);
    for (int i = 0; i < n; i++){
        cin >> arr[i];  
        total[arr[i]]++;
    } 
    for(int i = 0; i < n-1; i++){
        int a,b;
        cin >> a >> b;
        graph[--a].push_back(--b);
        graph[b].push_back(a);
        edges[i] = {a,b};
    }
    dfs(0,-1);
    for (int i = 0; i < n-1; i++){
        cout << max(answers[edges[i]], answers[{edges[i].second, edges[i].first}]) << " ";
    }

}