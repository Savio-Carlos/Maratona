// Generate all permutations
// O(N! * N)

vector<int> permutation;

for (int i = 0; i < n; i++) {
    permutation.push_back(i);
}

do {
// process permutation
} while (next_permutation(permutation.begin(),permutation.end()));
