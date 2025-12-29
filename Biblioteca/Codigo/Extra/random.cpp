#include <random>
#include <chrono>

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
uniform_int_distribution<long long> dist(0, n);//valores min e max

int x = dist(rng);
