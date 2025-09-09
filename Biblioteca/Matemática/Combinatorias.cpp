const int MOD = 1e9+7;

int fastExpo(int base, int exp) {
    int res = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

int modInverse(int n) {
    return fastExpo(n, MOD - 2);
}

/**
 * @brief Calculates combinations C(n, k) or "n choose k".
 *
 * This function computes the number of ways to choose k items from a set of n items
 * without regard to the order of selection.
 * It uses the formula C(n, k) = n! / (k! * (n-k)!).
 * To avoid dealing with large intermediate factorials and potential overflow,
 * it uses the multiplicative formula: C(n, k) = (n * (n-1) * ... * (n-k+1)) / (k * (k-1) * ... * 1).
 *
 * @param n The total number of items to choose from.
 * @param k The number of items to choose.
 * @return The value of C(n, k) as a int. Returns 0 if k > n or k < 0.
 */
int combinations(int n, int k) {
    // Basic edge cases
    if (k < 0 || k > n) {
        return 0;
    }
    if (k == 0 || k == n) {
        return 1;
    }
    // Symmetry property: C(n, k) == C(n, n-k).
    // It's more efficient to compute with the smaller k.
    if (k > n - k) {
        k = n - k;
    }

    int res = 1;
    // Calculate the result using the optimized multiplicative formula.
    // The loop calculates (n * (n-1) * ... * (n-k+1)) / k!
    // By interleaving multiplication and division, we keep the intermediate numbers smaller.
    for (int i = 1; i <= k; ++i) {
        res = res * (n - i + 1) / i;
    }
    return res;
}
/**
 * @brief Calculates combinations C(n, k) modulo a prime number M.
 *
 * This is essential for problems where C(n, k) is too large to fit in standard
 * data types, but the result is required modulo M.
 * It uses the formula C(n, k) = n! / (k! * (n-k)!) mod M.
 * Division in modular arithmetic is performed by multiplying with the modular
 * multiplicative inverse.
 *
 * Pre-computation of factorials is used for efficiency if this function is called many times.
 *
 * @param n The total number of items.
 * @param k The number of items to choose.
 * @param M The modulus (must be a prime number).
 * @return The value of C(n, k) % M. Returns 0 if k > n or k < 0.
 */
int combinations_mod(int n, int k) {
    if (k < 0 || k > n) {
        return 0;
    }
    if (k == 0 || k == n) {
        return 1;
    }
    if (k > n / 2) {
        k = n - k;
    }
    // Using the formula: n! / (k! * (n-k)!) % M
    // which is (n! * modInverse(k!) * modInverse((n-k)!)) % M

    // This implementation calculates it directly to avoid large factorial arrays.
    int numerator = 1;
    for(int i = 0; i < k; i++) {
        numerator = (numerator * (n - i)) % MOD;
    }

    int denominator = 1;
    for(int i = 1; i <= k; i++) {
        denominator = (denominator * i) % MOD;
    }

    return (numerator * modInverse(denominator)) % MOD;
}
