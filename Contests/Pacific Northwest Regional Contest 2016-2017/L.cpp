#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
const int MAXN = 1e3+7;
const int MOD = 1e9+7;

// Function to check if rectangles can form a valid arrangement
bool canFormSquare(int a, int b, int c, int d, int e, int f, int side) {
    // Try all orientations of each rectangle
    vector<pair<int, int>> rects = {{a, b}, {c, d}, {e, f}};
    
    // Try all permutations of rectangles
    sort(all(rects)); // Sort to generate permutations
    
    do {
        // For each rectangle, try both orientations (width/height can be flipped)
        for (int mask = 0; mask < 8; mask++) {
            int w1 = (mask & 1) ? rects[0].second : rects[0].first;
            int h1 = (mask & 1) ? rects[0].first : rects[0].second;
            
            int w2 = (mask & 2) ? rects[1].second : rects[1].first;
            int h2 = (mask & 2) ? rects[1].first : rects[1].second;
            
            int w3 = (mask & 4) ? rects[2].second : rects[2].first;
            int h3 = (mask & 4) ? rects[2].first : rects[2].second;
            
            // Try arrangements where rectangles form a square
            
            // Arrangement 1: All three in a row
            if (w1 + w2 + w3 == side && h1 == side && h2 == side && h3 == side)
                return true;
            
            // Arrangement 2: All three in a column
            if (h1 + h2 + h3 == side && w1 == side && w2 == side && w3 == side)
                return true;
            
            // Arrangement 3: Two on top, one on bottom
            if (w1 + w2 == side && h1 == h2 && h1 + h3 == side && w3 == side)
                return true;
            
            // Arrangement 4: One on top, two on bottom
            if (w1 == side && h1 + h2 == side && h1 + h3 == side && w2 + w3 == side && h2 == h3)
                return true;
            
            // Arrangement 5: Two on left, one on right
            if (h1 + h2 == side && w1 == w2 && w1 + w3 == side && h3 == side)
                return true;
            
            // Arrangement 6: One on left, two on right
            if (h1 == side && w1 + w2 == side && w1 + w3 == side && h2 + h3 == side && w2 == w3)
                return true;
            
            // Arrangement 7: L-shaped arrangement
            if (w1 == side && h2 == side - h1 && w2 + w3 == side && h3 == h1 && w3 == side - w2)
                return true;
            
            // Arrangement 8: Another L-shaped arrangement
            if (h1 == side && w2 == side - w1 && h2 + h3 == side && w3 == w1 && h3 == side - h2)
                return true;
        }
    } while (next_permutation(all(rects)));
    
    return false;
}

signed main() {
    winton;
    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    
    // Calculate total area
    int totalArea = a * b + c * d + e * f;
    
    // Check if total area can form a square
    int side = sqrt(totalArea);
    
    if (side * side != totalArea) {
        cout << "NO" << endl;
        return 0;
    }
    
    // Try all possible arrangements
    if (canFormSquare(a, b, c, d, e, f, side)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    
    return 0;
}