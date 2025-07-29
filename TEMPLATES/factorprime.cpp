vector<int> factorize(int x){
    vector<int> primes;
    int p = x;
    for (p = 2; p*p <= n; p++){
        while(x%p == 0){
            x/=p;
            primes.push_back(p);
        } 
    }
    if (x > 1)primes.push_back(p);
    return primes;
}

