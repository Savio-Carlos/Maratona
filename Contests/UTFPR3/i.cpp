#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define minecraft cin.tie(0)->sync_with_stdio(0);
#define endl "\n"
const ll MOD = 1e9+7;
const ll INF = 2e5;
 
// Generic printer for vector<T>
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v) {
    for (size_t i = 0; i < v.size(); ++i) {
        os << v[i];
        if (i + 1 < v.size()) os << ' ';
    }
    return os;
}
 
// Specialized printer for vector<vector<T>> (matrix)
template <typename T>
ostream &operator<<(ostream &os, const vector<vector<T>> &matrix) {
    for (size_t i = 0; i < matrix.size(); ++i) {
        os << matrix[i];
        if (i + 1 < matrix.size()) os << '\n';
    }
    return os;
}

vector<string> split_sentence(string sen) {
  
    // Create a stringstream object
    stringstream ss(sen);
    
    // Variable to hold each word
    string word;
    
    // Vector to store the words
    vector<string> words;
    
    // Extract words from the sentence
    while (ss >> word) {
      
        // Add the word to the vector
        words.push_back(word);
    }
    
    return words;
}
 
 
 
 
 
int main (){
    minecraft;
 
    ll t=1;
    //cin>>t;
 
    while(t--){
        
    ll n;
    cin>>n;

    cin.ignore();

    for (ll i = 0; i < n; i++){
       string s,res;

       getline(cin,s);

       vector<string> words = split_sentence(s);

       for(ll j = 0; j < words.size();j++){
        char c;
        c = words[j][0];

        if(islower(c)){
            res+=c-32;
        }
        else res+=c;

          
       }

       cout<<res<<endl;



    }
    


}
}
