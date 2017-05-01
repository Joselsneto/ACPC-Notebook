#define maxn 100000

int st[4*maxn];
int v[maxn];

void build(int no,int l,int r) {
	if(l == r) {
		st[no] = v[l];
		return;
	}
	int mid = (l+r)/2;
	build(no*2,l,mid);
	build(no*2+1,mid+1,r);
	st[no] = st[no*2]+st[no*2+1];
}

int query(int no,int l,int r,int i,int j) {
	if(l > j || r < i)
		return 0;
	if(l >= i && r <= j)
		return st[no];
	int mid = (l+r)/2;
	return query(no*2,l,mid,i,j) + query(no*2+1,mid+1,r,i,j);
}

void update(int no,int l,int r,int value,int pos) {
	if(l > pos || r < pos)
		return;
	if(l == r) {
		st[no] = value;
		return;
	}
	int mid = (l+r)/2;
	update(no*2,l,mid,value,pos);
	update(no*2+1,mid+1,r,value,pos);
}