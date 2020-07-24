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

const ll N = 5*(1e5) + 4 ;

ll tree1[2*N] ;
ll gcd[N] ;
ll phi[N] ;
ll n ;

void update(ll x, int k) {
	//cout << "Iamhere\n" ;
	//cout << n << " " << k << " " ;
	while(k <= n){
		//cout << "Iamhereinside\n" ;
		tree1[k]= (tree1[k] + x) ;
		//cout << tree1[k] << "\n" ;
		k = k + (k&-k) ;
	}
}

ll query(int k) {
	ll sum = 0; 
	while(k >= 1){
		sum = (sum + tree1[k]);
		k = k - (k&-k) ;
	}
	return sum ;
}

void calculate_phi(){
	for(int i = 1; i < N ; i++){
		phi[i] = i ;
	}
	for(int i = 2 ; i < N ; i++){
		if(phi[i] == i){
			for(int j = i ; j < N ; j = j + i){
				phi[j] = phi[j] / i ;
				phi[j] = phi[j] * (i-1) ;
			}
		}
	}
}

void calculate_gcd(){
	gcd[1] = 0;
	for(int i = 1 ; i < N ; i++){
		for(int j = i; j < N; j=j+i){
			gcd[j]= (gcd[j]+ (i*phi[j/i])) ;
		}
	}
	//for(int i = 1; i <= 5 ;i++) cout << phi[i] << " " ;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	calculate_phi() ;
	calculate_gcd() ;
	cin >> n ;
	ll a[n+3] ;
	for(int i =1 ; i<=n ;i++){
		cin >> a[i] ;
		update(gcd[a[i]],i) ;
	}
	//for(int i = 0; i < 5; i++)cout << gcd[i] << " " ;
 	int q ;cin >> q ;
	while(q--){
		ll x,y ; char c ;
		cin >> c >> x >> y ;
		if(c == 'C'){
			if(x == 1) {
				cout << (query(y)+mod)%mod << "\n" ;
			}
			else{
				cout << (query(y) -query(x-1) + mod)%mod << "\n" ;
			}
		}
		else{
			//cout << "abc" ;
			ll prev = gcd[a[x]] ;
			ll new_ = gcd[y] ;
			ll incr = new_ - prev ;
			a[x] = y ;
			//cout << "abcd1" ;
			update(incr,x) ;
		}
	}

 	return 0;
}