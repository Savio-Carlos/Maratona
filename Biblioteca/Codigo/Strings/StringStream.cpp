//StringStream

vector<string> split_sentence(string s){
    stringstream ss(s);

    string word;

    vector<string> v;

    while(getline(ss, word, ' ')){
        v.push_back(word);
    }
    return v;
}