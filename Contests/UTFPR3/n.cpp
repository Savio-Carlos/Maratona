#include <iostream>
#include <algorithm>
using namespace std;

const long long MOD = 998244353;

long long mod_pow(long long base, long long exp = MOD-2) {
    long long result = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp & 1) 
            result = (result * base) % MOD;
        base = (base * base) % MOD;
        exp >>= 1;
    }
    return result;
}

int main() {
    long long a, b;
    cin >> a >> b;

    long long inv2 = mod_pow(2);
    long long inv6 = mod_pow(6);

    long long n = a % MOD;
    long long m = b % MOD;
    long long mn_val = min(a, b);
    long long mn_mod = mn_val % MOD;

    long long part1 = (n * (n+1)) % MOD;
    part1 = part1 * inv2 % MOD;
    long long part2 = (m * (m+1)) % MOD;
    part2 = part2 * inv2 % MOD;
    long long total_rect = part1 * part2 % MOD;

    long long term1 = (mn_val + 1) % MOD;
    term1 = term1 * n % MOD;
    term1 = term1 * m % MOD;

    long long term2 = mn_mod;
    term2 = term2 * ((mn_val + 1) % MOD) % MOD;
    term2 = term2 * ((2 * mn_val + 1) % MOD) % MOD;
    term2 = term2 * inv6 % MOD;

    long long temp = mn_mod;
    temp = temp * ((mn_val + 1) % MOD) % MOD;
    temp = temp * inv2 % MOD;

    long long term3 = n * temp % MOD;
    long long term4 = m * temp % MOD;

    long long squares = (term1 + term2) % MOD;
    squares = (squares - term3 + MOD) % MOD;
    squares = (squares - term4 + MOD) % MOD;

    long long ans = (total_rect - squares + MOD) % MOD;

    cout << ans << endl;

    return 0;
}