//compressao de coordenada para vector

vector<int> v(n);
vector<int> todos;
for (int i = 0; i < n; i++){
    cin >> v[i];
    todos.push_back(v[i]);
}

sort(all(todos));
todos.erase(unique(all(todos)), todos.end());
int m = todos.size();

auto comp = [&](int x) {
    return (lower_bound(all(todos), x) - todos.begin());
};

vector<int> comp(n);
for (int i = 0; i < n; i++){
    comp[i] = lower_bound(all(todos), v[i]) - todos.begin();
}
