#define maxn 10000

vector <int> graph[maxn];
int dfs_low[maxn],dfs_num[maxn],parent[maxn],dfsnumbercount,dfsroot,rootchildren;
bool articulation_vertex[maxn];
vector <pair <int,int> > pontes;
vector <int> pontos;
int V;

void dfs(int u) {
	dfs_low[u] = dfs_num[u] = dfsnumbercount++;
	for(int i = 0;i < graph[u].size();i++) {
		int v = graph[u][i];
		if(!dfs_num[v]) {
			parent[v] = u;
			if(u == dfsroot) rootchildren++;

			dfs(v);

			if(dfs_low[v] >= dfs_num[u])
				articulation_vertex[u] = true;
			if(dfs_low[v] > dfs_num[u])
				pontes.push_back( make_pair(u,v) );
			dfs_low[u] = min(dfs_low[u], dfs_low[v]);
		}
		else if(v != parent[u]) {
			dfs_low[u] = min(dfs_low[u],dfs_low[v]); 
		}
	}
}

int main() {
	dfsnumbercount = 0;
	memset(dfs_num,0,sizeof dfs_num);
	memset(dfs_low,0,sizeof dfs_low);
	//Pontes
	for(int i = 0;i < V,i++) {
		if(!dfs_num[i]) {
			dfsroot = i;
			rootchildren = 0;
			dfs(i);
			articulation_vertex[dfsroot] = (rootchildren > 1);
		}
	}
	//Pontos de Articulação
	for(int i = 0;i < V;i++)
		if(articulation_vertex[i])
			pontos.push_back(i);
	return 0;
}