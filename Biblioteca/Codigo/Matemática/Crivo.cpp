//Sieve

vector<int> primes;

void sieve() {
    vector<bool> is_prime(MAX + 1, true);
    is_prime[0] = false;
    is_prime[1] = false;
    for (int p = 2; p * p <= MAX; ++p) {
        if (is_prime[p]) {
            for (int multiple = p * p; multiple <= MAX; multiple += p) {
                is_prime[multiple] = false;
            }
        }
    }
    for (int i = 2; i <= MAX; ++i) {
        if (is_prime[i]) {
            primes.push_back(i);
        }
    }
}
