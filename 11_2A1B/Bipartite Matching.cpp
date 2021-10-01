// |maximum matching| = |minimum vertex cover|
// (x_i, y_j) -> g[i].push_back(j)
vector<int> g[1007];
int nx, mx[1007], my[1007];
bool used[1007];
bool dfs(int x) {
    used[x] = true;
    for (int i:g[x]) {
        if (my[i] < 0 || !used[my[i]] && dfs(my[i])) {
            my[mx[x] = i] = x;
            return true;
        }
    }
    return false;
}
int bipartite_matching() {
    int res = 0;
    memset(mx, -1, sizeof(mx));
    memset(my, -1, sizeof(my));
    for (int i = 1; i <= nx; i++) {
        memset(used, 0, sizeof(used));
        if (dfs(i)) res++;
    }
    return res;
}
