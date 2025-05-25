#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
const int MAX = 2e5+7;
const int INF = INT_MAX;

int countSum[4001], ans[8001];;

const double PI = acos(-1);

void fft(vector<complex<double>>& a, bool invert, int n, const vector<int>& rev) {
    for(int i = 0; i < n; i++) {
        if(i < rev[i]) 
            swap(a[i], a[rev[i]]);
    }
    for(int len = 2; len <= n; len <<= 1) {
        double ang = 2 * PI / len * (invert ? -1 : +1);
        complex<double> wlen(cos(ang), sin(ang));
        for(int i = 0; i < n; i += len) {
            complex<double> w(1);
            int half = len >> 1;
            for(int j = 0; j < half; j++) {
                complex<double> u = a[i + j];
                complex<double> v = a[i + j + half] * w;
                a[i + j] = u + v;
                a[i + j + half] = u - v;
                w *= wlen;
            }
        }
    }
    if(invert) for(int i = 0; i < n; i++)a[i] /= n;
}
vector<int> convolution(const vector<double>& A, const vector<double>& B) {
    int szA = (int)A.size();
    int szB = (int)B.size();
    int need = szA + szB - 1;
    int n = 1, log_n = 0;
    while(n < need) {
        n <<= 1;
        log_n++;
    }
    vector<int> rev(n);
    for(int i = 0; i < n; i++) {
        rev[i] = 0;
        for(int j = 0; j < log_n; j++) {
            if(i & (1 << j))
                rev[i] |= 1 << (log_n - 1 - j);
        }
    }
    vector<complex<double>> FA(n), FB(n);
    for(int i = 0; i < szA; i++) FA[i] = complex<double>(A[i], 0);
    for(int i = szA; i < n; i++) FA[i] = complex<double>(0, 0);
    for(int i = 0; i < szB; i++) FB[i] = complex<double>(B[i], 0);
    for(int i = szB; i < n; i++) FB[i] = complex<double>(0, 0);
    fft(FA, false, n, rev);
    fft(FB, false, n, rev);
    for(int i = 0; i < n; i++)
        FA[i] *= FB[i];
    fft(FA, true, n, rev);
    vector<int> res(need);
    for(int i = 0; i < need; i++)
        res[i] = (int) llround(FA[i].real());
    return res;
}

signed main() {
    winton;
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    vector<double> D(4001);
    for(int c = 2; c <= n - 2; c++) {
        int j = c - 1;
        for(int i = 0; i < j; i++) {
            int s = arr[i] + arr[j] + 2000;
            countSum[s]++;
        }
        fill(D.begin(), D.end(), 0.0);
        for(int d = c + 1; d < n; d++) {
            int s2 = arr[c] + arr[d] + 2000;
            D[s2] += 1.0;
        }
        vector<double> B(4001);
        for(int i = 0; i < 4001; i++) {
            B[i] = (double) countSum[i];
        }
        vector<int> C = convolution(B, D);
        for(int u = 0; u <= 8000; u++) {
            ans[u] += C[u];
        }
    }
    int q;
    cin >> q;
    while(q--) {
        int a;
        cin >> a;
        cout << ans[a + 4000] << endl;
    }
}