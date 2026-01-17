#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'


template<typename T = int> struct frac {
	T num, den;
	template<class U, class V>
	frac(U num_ = 0, V den_ = 1) : num(num_), den(den_) {
		assert(den != 0);
		if (den < 0) num *= -1, den *= -1;
		T g = gcd(abs(num), den);
		num /= g, den /= g;
	}

	friend bool operator<(const frac& l, const frac& r) {
		return l.num * r.den < r.num * l.den;
	}
	friend frac operator+(const frac& l, const frac& r) {
		return {l.num*r.den + l.den*r.num, l.den*r.den};
	}
	friend frac operator-(const frac& l, const frac& r) {
		return {l.num*r.den - l.den*r.num, l.den*r.den};
	}
	friend frac operator*(const frac& l, const frac& r) {
		return {l.num*r.num, l.den*r.den};
	}
	friend frac operator/(const frac& l, const frac& r) {
		return {l.num*r.den, l.den*r.num};
	}
	friend ostream& operator<<(ostream& out, frac f) {
		out << f.num << '/' << f.den;
		return out;
	}
};

const int MAXN = 1e6 + 7;
int spf[MAXN];

void sieve() {
    for (int i = 1; i < MAXN; i++) spf[i] = i;

    for (int i = 2; i * i < MAXN; i++) {
        if (spf[i] == i) { 
            for (int j = i * i; j < MAXN; j += i)
                if (spf[j] == j) spf[j] = i;
        }
    }
}

void solve(){
    int n; cin >> n;
    vector<int> arr(n);
    map<frac<int>, int> mp;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        frac<int> tot(1, 1);
        while(x > 1){
            int p = spf[x];
            frac<int> k(1, p);
            frac<int> t(1, 1);
            tot = tot * (t-k);
            while(!(x%p)) x/=p;
        }
        mp[tot]++;
    }
   
    cout << mp.size() << endl;
}

signed main(){
    fastio;
    sieve();
    solve();
}