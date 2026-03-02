#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)

using u64 = uint64_t;
using u128 = __uint128_t;

u64 power(u64 base, u64 exp, u64 mod) {
    u64 res = 1;
    base %= mod;
    while (exp > 0) {
        if (exp % 2 == 1) res = (u128)res * base % mod;
        base = (u128)base * base % mod;
        exp /= 2;
    }
    return res;
}

bool miller_rabin(u64 n) {
    if (n < 2) return false;
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0) return false;

    u64 d = n - 1;
    int s = 0;
    while (d % 2 == 0) {
        d /= 2;
        s++;
    }

    static const u64 bases[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
    for (u64 a : bases) {
        if (n <= a) break;
        u64 x = power(a, d, n);
        if (x == 1 || x == n - 1) continue;
        bool composite = true;
        for (int r = 1; r < s; r++) {
            x = (u128)x * x % n;
            if (x == n - 1) {
                composite = false;
                break;
            }
        }
        if (composite) return false;
    }
    return true;
}

bool is_prime(long long n) {
    return miller_rabin((u64)n);
}

bool is_square(long long n) {
    if (n < 0) return false;
    long long r = (long long)sqrtl(n);
    while ((u128)(r + 1) * (r + 1) <= (u128)n) r++;
    while ((u128)r * r > (u128)n) r--;
    return r * r == n;
}

vector<long long> primes;
void sieve() {
    int max_p = 1000000;
    vector<bool> is_p(max_p + 1, true);
    is_p[0] = is_p[1] = false;
    for (int p = 2; p * p <= max_p; p++) {
        if (is_p[p]) {
            for (int i = p * p; i <= max_p; i += p)
                is_p[i] = false;
        }
    }
    for (int p = 2; p <= max_p; p++) {
        if (is_p[p]) primes.push_back(p);
    }
}

long long count_divisors(long long X) {
    long long ans = 1;
    for (long long p : primes) {
        if (p * p > X) break;
        if (X % p == 0) {
            long long cnt = 0;
            while (X % p == 0) {
                cnt++;
                X /= p;
            }
            ans *= (cnt + 1);
        }
    }
    if (X > 1) {
        if (is_prime(X)) {
            ans *= 2;
        } else if (is_square(X)) {
            ans *= 3;
        } else {
            ans *= 4;
        }
    }
    return ans;
}

void solve() {
    long long n;
    if (!(cin >> n)) return;
    vector<long long> A(n);
    for (int i = 0; i < n; i++) cin >> A[i];
    sort(A.begin(), A.end());

    long long M = A.back();
    long long ans_X = -1, ans_D = -1;
    int valid_count = 0;

    // Candidate 1
    long long C1_X = M;
    if (count_divisors(C1_X) == n + 1) {
        bool ok = true;
        for (long long x : A) {
            if (C1_X % x != 0) {
                ok = false; break;
            }
        }
        if (ok) {
            long long C1_D = -1;
            for (long long d : A) {
                if (!binary_search(A.begin(), A.end(), C1_X / d)) {
                    C1_D = C1_X / d;
                    break;
                }
            }
            if (C1_D == -1) {
                long long r = (long long)sqrtl(C1_X);
                while ((u128)(r + 1) * (r + 1) <= (u128)C1_X) r++;
                while ((u128)r * r > (u128)C1_X) r--;
                C1_D = r;
            }
            ans_X = C1_X; ans_D = C1_D;
            valid_count++;
        }
    }

    // Candidate 2
    if (A[0] == 1 && n >= 2) {
        u128 X2_inf = (u128)A[1] * M;
        if (X2_inf <= 1000000000000000000ULL) {
            long long C2_X = (long long)X2_inf;
            if (count_divisors(C2_X) == n + 1) {
                bool ok = true;
                for (long long x : A) {
                    if (C2_X % x != 0) {
                        ok = false; break;
                    }
                }
                if (ok) {
                    long long C2_D = C2_X;
                    ans_X = C2_X; ans_D = C2_D;
                    valid_count++;
                }
            }
        }
    }

    if (valid_count == 1) {
        cout << ans_X << " " << ans_D << "\n";
    } else {
        cout << "*\n";
    }
}

int main() {
    fastio;
    sieve();
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}
