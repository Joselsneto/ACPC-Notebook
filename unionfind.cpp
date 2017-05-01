//O(log *) para cada vertice que adiciona
#define maxn 100000

int root[maxn];

void init() {
	for(int i = 0;i < maxn;i++) 
		root[i] = i;
}

int findset(int x) {
	if(root[x] == x) return x;
	return root[x] = findset(root[x]);
}