//Phi Function

//quantos numeros sao coprimos com N de 1 ate N
int phi[MAX];

void precomputePHI(){
    for (int i = 0; i < MAX; i++)
        phi[i] = i;

    for (int i = 2; i < MAX; i++) {
        if (phi[i] == i) {
            for (int j = i; j < MAX; j += i)
                phi[j] -= phi[j] / i;
        }
    }
}