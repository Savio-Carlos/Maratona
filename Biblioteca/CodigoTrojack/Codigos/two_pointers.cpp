// Two Pointers Technique
// O(N) - quase constante

bool twoSum(vector<int> &arr, int target){
    int left = 0, right = arr.size() - 1;
    while (left < right){
        int sum = arr[left] + arr[right];

        if (sum == target)
            return true;
        
        else if (sum < target)
            left++; 
      
        else
            right--; 
    }
  
    return false;
}