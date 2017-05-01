#define maxn 1000

vector <int> graph[maxn];
bool vis[maxn];

void dfs(int x) {
	vis[x] = true;
	for(int i = 0;i < graph[x].size();i++) {
		int y = graph[x][i];
		if(!vis[y]) dfs(y);
	}
}