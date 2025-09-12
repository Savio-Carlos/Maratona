// Prefix Sum
// O(N) - quase constante

vector<int> prefSum(vector<int> &arr) {
    int n = arr.size();
    
    vector<int> prefixSum(n);

    prefixSum[0] = arr[0];

    for (int i = 1; i < n; i++)
        prefixSum[i] = prefixSum[i - 1] + arr[i];
    
    return prefixSum;
}