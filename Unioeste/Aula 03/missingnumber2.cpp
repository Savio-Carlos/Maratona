#include <iostream>
#include <vector>
#include <numeric>

int main() {
    // Fast I/O is included, but it won't be enough to save this algorithm.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    // Store all n-1 numbers in a vector.
    std::vector<int> numbers(n - 1);
    for (int i = 0; i < n - 1; ++i) {
        std::cin >> numbers[i];
    }

    // Outer loop: check every number from 1 to n.
    for (int i = 1; i <= n; ++i) {
        bool found = false;
        // Inner loop: search for 'i' in the vector of given numbers.
        for (int j = 0; j < n - 1; ++j) {
            if (numbers[j] == i) {
                found = true;
                break; // Found it, no need to search further for this 'i'.
            }
        }

        // If after checking all the numbers, 'i' was not found, it's the missing one.
        if (!found) {
            std::cout << i << std::endl;
            return 0; // Exit after finding the missing number.
        }
    }

    return 0;
}