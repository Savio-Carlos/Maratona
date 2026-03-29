#include <iostream>
#include <vector>

using namespace std;

int main(){

    vector<int> trees;
    vector<int> record;

    int q; cin >> q;

    for (int i = 0; i < q; i++){

        int x; cin >> x;
        int h; cin >> h;

        if (x == 1){
            trees.push_back(h);
        }else if (x == 2){
            for (int s = 0; s < trees.size(); s++){
                if (trees[s] <= h){
                    trees[s] = 0;
                }
            }
        }

        int r = 0;

        for (int t : trees){
            if (t > 0){
                r++;
            }
        }
        record.push_back(r);
    }

    for (auto i : record){
        cout << i << "\n";
    }
}