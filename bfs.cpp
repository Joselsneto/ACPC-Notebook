#define maxn 1000

vector <int> graph[maxn];
int dist[maxn];

void bfs(int s) {
	memset(dist,INF,sizeof dist);
	dist[s] = 0;
	queue <pair <int,int> > fila;
	fila.push( make_pair(0,s) );
	while(!fila.empty()) {
		int d = fila.front().first;
		int x = fila.front().second;
		fila.pop();
		for(int i = 0;i < graph[x].size();i++) {
			int y = graph[x][i];
			if(dist[y] > d + 1) {
				dist[y] = d+1;
				fila.push( make_pair(d+1,y) );
			}
		}
	}
}