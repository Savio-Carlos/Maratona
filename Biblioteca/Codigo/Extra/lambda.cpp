

auto reduce = [&](multiset<string> ms){
    multiset<int> mi;
    for (auto &s : ms) {
        if (s.size() > 1) {
            mi.insert(s.size());
            ans++;
        } 
        else mi.insert(s[0] - '0');
    }
    return mi;
};