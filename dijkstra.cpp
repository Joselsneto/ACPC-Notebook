#define maxn 1000

vector < pair<int,int> > graph[maxn];
int dist[maxn];

void dijkstra(int s) {
	memset(dist,INF,sizeof dist);
	dist[s] = 0;
	priority_queue < pair <int, int> > fila;
	fila.push( make_pair(0,s) );
	while(!fila.empty()) {
		int d = -fila.top().first;
		int x = fila.top().second;
		fila.pop();
		if(dist[x] < d) continue;
		for(int i = 0;i < graph[x].size();i++) {
			int y = graph[x][i].first;
			int t = graph[x][i].second;
			if(dist[y] > d + t) {
				dist[y] = d+t;
				fila.push( make_pair(-dist[y],y) );
			}

		}
	} 
}