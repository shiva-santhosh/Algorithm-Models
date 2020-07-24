#include <bits/stdc++.h>
using namespace std;
/******************************************
* AUTHOR : PANDRAVISAM SHIVA SANTHOSH *
* Handle : santhosh_80 *
* INSTITUTION : IIT Palakkad *
******************************************/
#define ll long long int 
#define rep(i,a,b) for(int i=a;i<b;i++)
#define pii pair<int,int>
#define all(v) (v).begin(),(v).end()
#define pb push_back
#define f first
#define s second

const ll mod = 1000000007;
const ll N = 1e5+5;

int seg[4*N];
int lazy[4*N];
vector<bool> marked(4*N,false);

void push(int v){
	seg[2*v]=lazy[v];
	seg[2*v+1]=lazy[v];
	lazy[2*v] = lazy[v];
	lazy[2*v+1]=lazy[v];
	lazy[v]=0;
	marked[v]=false;
}




void construct(vector<int> &b,int tl,int tr,int v){

	if(tl == tr){
		seg[v] = b[tl];
		return;
	}
	int mid = (tl+tr)/2;

	construct(b,tl,mid,2*v);
	construct(b,mid+1,tr,2*v+1);
	seg[v] = 0;
	return;
}

int query(int tl,int tr,int l,int r,int v){

	if(l>r)return INT_MIN;
	if(l == tl && r == tr){
		return seg[v];
	}
	if(marked[v])push(v);
	int mid=(tl+tr)/2;
	return max( query(tl,mid,l,min(mid,r),2*v) , query(mid+1,tr,max(mid+1,l),r,2*v+1) );
}	

void update(vector<int> &a,int tl,int tr,int l,int r,int v,int off){

	if(l > r)return;
	if(l == tl && tr == r){
		marked[v] = true;
	}

	int mid = (l+r)/2;
	if(marked[v])push(v,off);
	update(a,tl,mid,l,min(mid,r),2*v,off);
	update(a,mid+1,tr,max(mid+1,l),r,2*v+1,off);
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,m;cin >> n >> m;
	vector<int> a(n);
	vector<int> b(n);
	rep(i,0,n)cin>>a[i];
	rep(i,0,n)cin>>b[i];
	construct()
	while(m--){
		int t;cin >> t;
		if(t == 2){
			int x;cin >> x;
			x--;
			cout << query(0,n-1,x,x,1) << "\n";
		}
		else if(t == 1){
			int x,y,k;
			cin >> x >> y >> k;
			x--;y--;
			int off = (y-x);
			update(a,0,n-1,y,y+k-1,off);

		}
	}
 	return 0;
}