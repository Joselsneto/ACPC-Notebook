struct node {
	int x,y,w;
	node() {};
	node(int _x, int _y,int _w) {
		x=_x,y=_y,w=_w;
	}
	bool operator < (const node sx) const {
		return w<sx.w;
	}
};

vector <node>graph;
#define maxn 100000
int root[maxn];

int findset(int x) {
	if(root[x]==x)
		return x;
	return root[x]=findset(root[x]);
}

void initset() {
	for(int i = 0;i<maxn;i++)
		root[i]=i;
}

int main() {
	initset();
	sort(graph.begin(),graph.end());
	vector <int> tree[maxn];
	int mst = 0;
	for(int i = 0;i < graph.size();i++) {
		int x = graph[i].x;
		int y = graph[i].y;
		int w = graph[i].w;

		int fx = findset(x);
		int fy = findset(y);

		if(fx != fy) {
			root[fx] = fy;
			mst += w;
			tree[x].push_back(y);
		}	
	}
}