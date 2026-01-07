#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    map<long long, vector<long long>> byX;
    
    for (int i = 0; i < n; i++) {
        long long x, y;
        cin >> x >> y;
        byX[x].push_back(y);
    }
    
    // Sort each group by y-coordinate
    for (auto& [x, ys] : byX) {
        sort(ys.begin(), ys.end());
    }
    
    vector<long long> xs;
    for (auto& [x, ys] : byX) {
        xs.push_back(x);
    }
    
    vector<pair<long long, long long>> polygon;
    
    // Strategy:
    // Upper boundary: teeth pointing up at y >= 2 level
    // Lower boundary: straight line at y = 1, visiting any points with y=1
    //
    // For points with y=1, we DON'T include them in the upper trace (since they're below baseline)
    // Instead, we include them in the lower trace going right-to-left
    
    // Upper trace (left to right)
    polygon.push_back({xs.front(), 1});  // bottom-left corner
    polygon.push_back({xs.front(), 2});  // up to teeth level
    
    for (int i = 0; i < (int)xs.size(); i++) {
        long long x = xs[i];
        auto& ys = byX[x];
        
        if (i > 0) {
            polygon.push_back({x, 2});
        }
        
        // Only add points with y >= 2 on upper trace
        for (long long y : ys) {
            if (y >= 2) {
                polygon.push_back({x, y});
            }
        }
        
        polygon.push_back({x + 1, 2});
    }
    
    // Right edge: go down to y=1
    polygon.push_back({xs.back() + 1, 1});
    
    // Lower trace (right to left): visit points with y=1
    for (int i = (int)xs.size() - 1; i >= 0; i--) {
        long long x = xs[i];
        auto& ys = byX[x];
        
        for (long long y : ys) {
            if (y == 1) {
                polygon.push_back({x, 1});
            }
        }
    }
    
    // Left edge: connect back to start
    polygon.push_back({xs.front(), 1});
    
    // Remove consecutive duplicates
    vector<pair<long long, long long>> result;
    for (auto& p : polygon) {
        if (result.empty() || result.back() != p) {
            result.push_back(p);
        }
    }
    
    // Remove last if equals first
    if (result.size() > 1 && result.front() == result.back()) {
        result.pop_back();
    }
    
    cout << result.size() << "\n";
    for (auto& [x, y] : result) {
        cout << x << " " << y << "\n";
    }
    
    return 0;
}