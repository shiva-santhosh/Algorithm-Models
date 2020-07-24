#include <bits/stdc++.h>
using namespace std;
/******************************************
* AUTHOR : PANDRAVISAM SHIVA SANTHOSH *
* Handle : santhosh_80 *
* INSTITUTION : IIT Palakkad *
******************************************/
#define ll long long int
#define rep(i,a,b) for(int i=a;i<b;i++)
#define pii pair<ll,ll>
#define all(v) (v).begin(),(v).end()
#define pb push_back
#define f first
#define s second

const ll mod = 1000000007;
const ll N = 4*(1e5)+5;
ll seg[N];
ll lazy[N];

void push(ll v,ll l,ll r){

	ll mid = (l+r)/2;

	lazy[2*v]+=lazy[v];
	seg[2*v]+=(mid-l+1)*lazy[v];

	lazy[2*v+1]+=lazy[v];
	seg[2*v+1]+=(r-mid)*lazy[v];

	lazy[v]=0;
}

void update(ll v,ll l,ll r,ll ql,ll qr,ll val){
	if(ql > qr)return;
	if(l == ql && r == qr){
		lazy[v]+=val;
		seg[v]+=val*(r-l+1);
		return;
	}
	ll mid = (l+r)/2;
	push(v,l,r);
	update(2*v,l,mid,ql,min(mid,qr),val);
	update(2*v+1,mid+1,r,max(mid+1,ql),qr,val);
	seg[v] = seg[2*v+1] + seg[2*v]; 
}
ll query(ll v,ll l,ll r,ll ql,ll qr){
	if(ql > qr)return 0;
	if(l == ql && r == qr){
		return seg[v];
	}
	push(v,l,r);
	ll mid = (l+r)/2;
	return query(2*v,l,mid,ql,min(mid,qr))+query(2*v+1,mid+1,r,max(mid+1,ql),qr);

}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll t;cin >> t;
	while(t--){
		ll n,c;cin >> n >> c;
		while(c--){
			ll x;cin >> x;
			if(x == 0){
				ll p,q,v;
				cin >> p >> q >> v;
				update(1,1,n,p,q,v);
			}
			else{	
				ll p,q;cin >> p >> q;
				cout << query(1,1,n,p,q) << "\n";
			}
		}
		//for(ll i = 1; i <= 24 ; i++)cout <<seg[i] << " ";
		for(int i = 1; i <= 4*n; i++){
			seg[i] = 0;
			lazy[i] = 0;
		}
	}
 	return 0;
}