#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL);
using namespace std;
#define endl '\n'
#define ll long long
const int MAXL = 1e6+7;

void setIO(string name = "") {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	if (name.size()) {
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

signed main() { _
	setIO("traffic");
    int n; cin >> n;
    pair<int,int> entrance = {0, 1e9};
    pair<int,int> exit = {0, 1e9};   

    vector<tuple<string,int,int>> instructions(n);
    for ( auto&[type,mini,maxi] : instructions){
        cin >> type >> mini >> maxi;
    } 

    int e = 0;
    for (e = instructions.size()-1; e >= 0; e--){
        auto [type,mini,maxi] = instructions[e];
        if (type == "on"){
            entrance.first -= get<2>(instructions[e]);
            entrance.second -= get<1>(instructions[e]);
            entrance.first = max(entrance.first, 0);
        }
        else if (type == "off"){
            entrance.first += get<1>(instructions[e]);
            entrance.second += get<2>(instructions[e]);
            
        }
        else if(type == "none"){
            entrance.first = max(entrance.first,get<1>(instructions[e]));
            entrance.second = min(entrance.second,get<2>(instructions[e]));
        }
    }

    int s = 0;
    for (s = 0; s < instructions.size(); s++) {
        auto [type,mini,maxi] = instructions[s];
        if (type == "on") {
            exit.first += mini;        
            exit.second += maxi;     
        }
        else if (type == "off") {
            exit.first -= maxi;
            exit.second -= mini;
            exit.first = max(0, exit.first);
        }
        else if(type == "none") {
            exit.first = max(exit.first, mini);
            exit.second = min(exit.second, maxi);
        }
    }

    cout << entrance.first << " " << entrance.second << endl;
    cout << exit.first << " " << exit.second << endl;
}

/*
cout << "diffs: \n";
    cout << entrancediff1 << " " << entrancediff2 << endl;
    cout << exitdiff1<< " " << exitdiff2 << endl << endl;
    cout << "valores originais: \n";
    cout << entrance.first << " " << entrance.second << endl;
    cout << exit.first << " " << exit.second << endl;
     cout << "finais: \n";
    
*/