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


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll n,I; cin >> n >> I ;
	ll k1 = 0;
	vector<ll> vi ;
	unordered_map<ll,ll> h ;

	for(int i = 0; i < n ; i++){
		ll x ; cin >> x ;
		h[x]++ ;
	}

	ll sum =  n;
	ll sum1 = 0 ;

	for(auto x : h) {
		vi.pb(x.first) ;
		k1++;
	}

	//cout << k1 << " " ;

	int req_bits  = (I*8)/n ;
	if(req_bits >= 20){
		cout << "0" ;
		return 0 ;
	}


	ll k = long (pow(2,req_bits))  ;

	//cout << k << " ";
	sort(all(vi)) ;
	
	if(k1 <= k ) {
		cout << 0 ;
		return 0 ;
	}

	ll min1  = INT_MAX ;

	for(int i = 0; i < k; i++){
		sum1 += h[vi[i]] ;
	}
	//cout << sum1 << " " ;

	min1 = min(n-sum1,min1) ;
	int i = 0; int j = k ;

	while(j < k1) {
		sum1-=h[vi[i]] ;
		sum1+=h[vi[j]] ;
		min1 = min(n-sum1,min1) ;
		i++;j++;
	}

	cout << min1 ;
 	return 0;
}