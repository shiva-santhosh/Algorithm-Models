#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
/******************************************
* AUTHOR : PANDRAVISAM SHIVA SANTHOSH *
* Handle : santhosh_80 *
* INSTITUTION : IIT Palakkad *
******************************************/
typedef tree<int,null_type,less<int>,rb_tree_tag,
tree_order_statistics_node_update> indexed_set;
#define ll long long int 
#define mod 1000000007
#define rep(i,a,b) for(int i=a;i<b;i++)
#define pii pair<int,int>
#define all(v) (v).begin(),(v).end()
#define S(x) scanf("%d",&(x))
#define P(x) printf("%d\n",(x))
#define Sl(x) scanf("%lld",&(x))
#define Pl(x) printf("%lld\n",(x))
#define pb push_back
#define f first
#define s second

const ll N = 200009 ;
const ll W = -5 * (1e10) ;

struct node{
	ll sum,prefix,suffix,ans ;
} ;

node seg[N] ;

node combine(node a,node b){
	node res ;

	if(a.sum == W)return b ;
	if(b.sum == W)return a ;

	res.sum = a.sum + b.sum ;
	res.prefix = max(a.prefix, a.sum+b.prefix) ;
	res.suffix = max(b.suffix, a.suffix+b.sum) ;
	res.ans = max( max(a.ans,b.ans), a.suffix+b.prefix )  ;
	return res ;
}

node make_node(ll x) {

	node dummy ;
	dummy.sum = x ;
	dummy.prefix = dummy.suffix =  dummy.ans = x ;
	return dummy ;
}

void construct(vector<ll> &vi, int tl, int tr,int vertex){

	if(tl == tr){
		seg[vertex] = make_node(vi[tl]) ;
		return ;
	}
	int tm = (tl+tr)/2 ;

	construct(vi,tl,tm,2*vertex) ;
	construct(vi,tm+1,tr,2*vertex+1) ;

	seg[vertex] = combine(seg[2*vertex],seg[2*vertex+1]);

}

node query(int tl,int tr,int l, int r, int vertex){

	if( l > r) return make_node(W) ;
	if( l == tl && r == tr) {
		return seg[vertex] ;
	}

	int tm = (tl+tr)/2 ;

	node a = query(tl, tm, l, min(r,tm), 2*vertex) ;
	node b = query(tm+1, tr, max(tm+1,l), r, 2*vertex+1) ;

	return combine(a,b) ;

}

void update(int tl,int tr,int index,int new_val,int vertex){

	if(tl == tr){
		seg[vertex] = make_node(new_val) ;
		return ;
	}

	int tm = (tl+tr)/2 ;

	if(tm >= index){
		update(tl, tm, index, new_val, 2*vertex) ; 
	}
	else{
		update(tm+1,tr, index, new_val, 2*vertex+1) ;
	}

	seg[vertex] = combine(seg[2*vertex],seg[2*vertex+1]) ;

}



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n ; cin >> n ;
	vector<ll> vi ;
	for(int i = 0; i < n ; i++){
		ll x ; cin >> x ;
		vi.pb(x) ;
	}
	construct(vi,0,n-1,1) ;
	ll q ; cin >> q ;
	while(q--){

		int x,l,r ;
		cin >> x >> l >> r ;

		if(x == 0){
			vi[l-1] = r ;
			update(0,n-1,l-1,r,1) ;
		}
		else{
			cout << query(0,n-1,l-1,r-1,1).ans << "\n";
		}
	}
 	return 0;
}