#define maxn 100000

int st[4*maxn];
int lz[4*maxn];
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

void prop(int no, int l, int r, int mid) {
    st[no * 2] += lz[no] * (mid - l + 1);
    st[no * 2 + 1] += lz[no] * (r - (mid + 1) + 1);
    lz[no * 2] += lz[no];
    lz[no * 2 + 1] += lz[no];
    lz[no] = 0;
}

int query(int no,int l,int r,int i,int j) {
	if(l > j || r < i)
		return 0;
	if(l >= i && r <= j) 
		return st[no];
	int mid = (l+r)/2;
	prop(no,l,r,mid);
	return query(no*2,l,mid,i,j) + query(no*2+1,mid+1,r,i,j);
}

void update(int no,int l,int r,int i,int j,int value) {
	if(l > j || r < i)
		return;
	if(l == r) {
		st[no] = (r-l-1) * value;
		lz[no] += value;
		return;
	}
	int mid = (l+r)/2;
	prop(no,l,r,mid);
	update(no*2,l,mid,i,j,value);
	update(no*2+1,mid+1,r,i,j,value);
}