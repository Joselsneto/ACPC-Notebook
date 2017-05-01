#define maxn 2000
#define logn 20
 
vector<int> g[maxn];
int h[maxn];
int pai[maxn][logn];
int n;
 
void dfs(int x, int p) {
    pai[x][0] = p;
    for (int i = 0; i < g[x].size(); i++) {
        int y = g[x][i];
        if (y == p) continue;
        h[y] = h[x] + 1;
        dfs(y, x);
    }
}
 
void calc() {
    for (int j = 1; j < logn; j++) {
        for (int i = 1; i <= n; i++) {
            int p1 = pai[i][j - 1];
            int p2 = pai[p1][j - 1];
            pai[i][j] = p2;
        }
    }
}
 
int lca(int x, int y) {
    if (h[x] < h[y]) swap (x, y);
    int d = h[x] - h[y];
    for (int i = 0; i < logn; i++)
        if (d&(1<<i))
            x = pai[x][i];
 
    if (x == y) return x;
 
    for (int i = logn - 1; i >= 0; i--)
        if (pai[x][i] != pai[y][i]) {
            x = pai[x][i];
            y = pai[y][i];
        }
    return pai[x][0];
}