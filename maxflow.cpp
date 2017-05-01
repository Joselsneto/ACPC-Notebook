#define maxn 110
 
int s, t;
int flow[maxn][maxn];
vector<int> g[maxn];
int pai[maxn];
 
bool bfs() {
    queue<int> q;
    q.push(s);
    memset(pai,-1,sizeof pai);
    pai[s] = -2;
    while (!q.empty()) {
        int x = q.front(); q.pop();
        for (int i = 0; i < g[x].size(); i++) {
            int y = g[x][i];
            if (pai[y] == -1 && flow[x][y]) {
                pai[y] = x;
                q.push(y);
                if (y == t) return true;
            }
        }
    }
    return false;
}
 
int maxflow() {
    int total = 0;
    while (bfs()) {
        int f = INF;
        int x = t;
        while (x != s) {
            f = min(f, flow[pai[x]][x]);
            x = pai[x];
        }
        x = t;
        while (x != s) {
            flow[pai[x]][x] -= f;
            flow[x][pai[x]] += f;
            x = pai[x];
        }
        total += f;
    }
    return total;
}