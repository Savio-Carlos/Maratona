//aqui foi com matriz mas pode ser um vector normal

vector<vector<int>> grid(n);
vector<int> todos;
for (int i = 0; i < n; i++){
    int k;
    cin >> k;
    grid[i].resize(k);
    for (int j = 0; j < k; j++){
        cin >> grid[i][j];
        todos.push_back(grid[i][j]);
    }
}
//compressao de coordenada
sort(all(todos));
todos.erase(unique(all(todos)), todos.end());
int m = todos.size();
vector<vector<int>> comp(n);
for (int i = 0; i < n; i++){
    comp[i].resize(grid[i].size());
    for (int j = 0; j < grid[i].size(); j++){
        comp[i][j] = lower_bound(all(todos), grid[i][j]) - todos.begin();
    }
}