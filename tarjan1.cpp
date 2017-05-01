#define maxn 10000

int dfs_num[maxn],dfs_low[maxn]; //reset(dfs_num,-1),reset(dfs_low,0);
bool vis[maxn];
vector <int> graph[maxn];
int cnt = 0,cnt2 = 0;//cnt = um auxiliar, cnt2 = quantidade de componentes fortemente conexo
vector <int> S;

void tarjan(int x) {
	dfs_low[x] = dfs_num[x] = cnt++;
	S.push_back(x);
	vis[x] = true;
	for(int i = 0;i < graph[x].size();i++) {
		int v = graph[x][i];
		if(dfds_num == -1)
			tarjan(v);
		if(vis[v])
			dfs_low[x] = min(dfs_low[x],dfs_low[v]);
	}

	if(dfs_low[x] == dfs_num[x])  {
		cnt2++;
		while(1) {
			int v = S.back();
			S.pop_back();
			vis[v] = false;
			if(u == v) break;
		}
	}
}

int main() {
	for(int i = 0;i < n;i++) {
		if(dfs_num[i] == -1) tarjan(i);
	}
}