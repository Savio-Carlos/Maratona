#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define int long long
#define ld long double

namespace dbg {
    const char* const RESET     = "\033[0m";
    const char* const BOLD_BLUE = "\033[1;34m";
    const char* const YELLOW    = "\033[33m";
    const char* const BOLD_WHITE= "\033[1;37m";

    template<typename T1, typename T2>
    ostream& operator<<(ostream& os, const pair<T1, T2>& p) { return os << '{' << p.first << ", " << p.second << '}'; }

    template<typename T_container, typename T = typename enable_if<!is_same_v<T_container, string> && !is_same_v<T_container, string_view>, typename T_container::value_type>::type>
    ostream& operator<<(ostream& os, const T_container& v) {
        os << '{';
        bool first = true;
        for (const T& x : v) { os << (first ? "" : ", ") << x, first = false; }
        return os << '}';
    }

    void debug_out(string_view) { cerr << endl; }
    template<typename H, typename... T>
    void debug_out(string_view s, H h, T... t) {
        auto cpos = s.find(',');
        cerr << YELLOW << s.substr(0, cpos) << RESET << " = ";
        cerr << BOLD_WHITE << h << RESET;
        if constexpr (sizeof...(t) > 0) {
            cerr << ", ";
            auto nx = s.find_first_not_of(" \t\n\r", cpos + 1);
            debug_out(s.substr(nx), t...);
        } else {
            cerr << endl;
        }
    }
} 
using namespace dbg;

#define DEBUG

#if defined(DEBUG)
    #define winton (void)0
    #define debug(...) cerr << BOLD_BLUE << "[" << __func__ << ":" << __LINE__ << "]" << RESET << " "; debug_out(#__VA_ARGS__, __VA_ARGS__)
#else
    #define winton ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
    #define debug(...) (void)0
#endif

const int mod = 1e9 + 7;
 
// C -> B -> A
int caseCBA(int A, int B, int C, int AB, int AC, int BC, int ABC, int k) {
 int cntA = (A + k - 1) / k;
 int cntB = (B + k - 1) / k;
 int cntC = (C + k - 1) / k;
 int ans = cntA + cntB + cntC;
 int remA = cntA * k - A;
 int remB = cntB * k - B;
 int remC = cntC * k - C;
 debug(cntA, cntB, cntC, ans, remA, remB, remC);
 // cerr << ans << " " << remA << " " << remB << " " << remC << endl;
 A = 0;
 B = 0;
 C = 0;
 // do with A and B
 // every c remaining goes to fill AC or BC
 // use for BC first, this means im just trying to find the minimum number of B washes
 int needC = min(BC, remC);
 BC -= needC;
 remC -= needC;
 
 int needB = min(BC, remB);
 BC -= needB;
 remB -= needB;
 if(BC > 0) // still need more B, how many?
 {
  int cntBC = (BC + k - 1) / k;
  ans += cntBC;
  remB += cntBC * k - BC;  
 }
 // BC = 0;
 int needABC = min(ABC, remC);
 ABC -= needABC;
 remC -= needABC;
 
 int needABC2 = min(ABC, remB);
 ABC -= needABC2;
 remB -= needABC2;
 
 int needAC = min(AC, remC);
 AC -= needAC;
 remC -= needAC;
 
 int needAB = min(AB, remB);
 AB -= needAB;
 remB -= needAB;
 
 int left = AB + AC + ABC;
 int needA = min(left, remA);
 remA -= needA;
 left -= needA;
 ans += (left + k - 1) / k;
 // cerr << "Final: " << ans << endl;
 return ans;
}
 
// case CAB
int caseCAB(int A, int B, int C, int AB, int AC, int BC, int ABC, int k) {
 return caseCBA(B, A, C, AB, BC, AC, ABC, k);
}
 
//      CBA
// case ABC, swap A with C
int caseABC(int A, int B, int C, int AB, int AC, int BC, int ABC, int k) {
 return caseCBA(C, B, A, BC, AC, AB, ABC, k);
}
 
//      CBA
// case ACB, A vira C, C vira B, B vira A
int caseACB(int A, int B, int C, int AB, int AC, int BC, int ABC, int k) {
 return caseCBA(C, A, B, AC, BC, AB, ABC, k);
}
 
//      CBA
// case BCA, swap B, C
int caseBAC(int A, int B, int C, int AB, int AC, int BC, int ABC, int k) {
 return caseCBA(A, C, B, AC, AB, BC, ABC, k);
}
 
//      CBA
// case BAC, B vira C, A vira B, C vira A
int caseBCA(int A, int B, int C, int AB, int AC, int BC, int ABC, int k) {
 return caseCBA(B, C, A, BC, AB, AC, ABC, k);
}
 
 
main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
 
 int t;
 cin >> t;
 while(t--) {
  int k;
  int A, B, C, AB, AC, BC, ABC;
  cin >> k >> A >> B >> C >> AB >> BC >> AC >> ABC;
  int ans = min({
   caseCBA(A, B, C, AB, AC, BC, ABC, k),
   caseCAB(A, B, C, AB, AC, BC, ABC, k),
   caseABC(A, B, C, AB, AC, BC, ABC, k),
   caseACB(A, B, C, AB, AC, BC, ABC, k),
   caseBAC(A, B, C, AB, AC, BC, ABC, k),
   caseBCA(A, B, C, AB, AC, BC, ABC, k)
  });
  cout << ans << endl;
 
 }
}