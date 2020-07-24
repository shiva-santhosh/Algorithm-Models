#include <bits/stdc++.h>
using namespace std;

#define ll long long int 

const ll N = 1e7+7 ;
const ll mod = 1e9+7 ; 
ll sum_prime[N] ;
ll f[N] ;
bitset<N> prime ;
ll fact[N] ;
ll phi[N] ;

// trick to remember a^b%m if b is very large to compute , then compute x = b%m-1 and then compute a^x;
// this follows from fermet's little theorem https://www.geeksforgeeks.org/find-abm-where-b-is-very-large/ ;
 
ll binary_power_mod(ll a, ll b , ll m) {

	ll res = 1 ;
	a = a % m;
	while(b){
			if( b & 1)
				res = res * a % m ;
			a = a * a % m;
			b = b >> 1 ;
	}
	return res ;
}

void sieve() {

	for( ll i = 1 ; i < N ;i++){
		phi[i] = i ;
		prime[i] = 1 ;
	}
	prime[1] = 0;
	for( ll i =2 ; i < N ; i++){
		if(phi[i] == i){
			for( ll j = i ; j < N ; j=j+i){
				phi[j] = phi[j]/i ;
				phi[j] *= (i-1) ;
				prime[j] = 0 ;
			}
			prime[i] = 1;
		}
	}
	ll count = 0;
	ll ans = 1;
	fact[0] = 1;
	fact[1] = 1;
	for( ll i = 1; i < N ;i++ ){
		if(prime[i]) count++ ;
		sum_prime[i] = count ;

		f[i] = sum_prime[i] - phi[i] ;
		if(f[i]<0)f[i] = 0;

		ans = ans * i  % (mod-1) ;
		fact[i] = ans ;
	}
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    sieve();
   // factorial() ; 
    ll t ; cin >> t;
    while(t--){
    	ll n ; cin >> n;
    	cout <<binary_power_mod(phi[n],fact[f[n]],mod) <<"\n";
    }
    return 0;
}
