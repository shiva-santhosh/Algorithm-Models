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

unordered_map<ll,bool> prime ;

// optimised prime_check
bool prime_check(ll m){

	if(m == 1)return false ;
	if(m == 2)return true ;
	if(m == 3)return true ;

	if(m%2 == 0)return false;
	if(m%3 == 0)return false;

	for(ll i =1 ;; i++){

		ll k1 = 6*i-1;
		ll k2 = 6*i+1;

		if(k1*k1 > m)break ;
		if(m%k1 == 0)return false ;
		if(k2*k2 > m)break ;
		if(m%k2 == 0)return false;
	}
	return true ;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t; cin >> t ;
	while(t--){
		ll n,m ; 
		cin >> m >> n;
		for(ll i = m ; i <= n ; i++){

			if(prime.find(i) != prime.end()){
				if(prime[i])cout << i << "\n" ;
				continue ;
			}
			if(prime_check(i)){
				prime[m] = true;
				cout << i << "\n" ;
			}
			else{
				prime[m] = false;
			}
		}
		cout << "\n" ;
	}
 	return 0;
}