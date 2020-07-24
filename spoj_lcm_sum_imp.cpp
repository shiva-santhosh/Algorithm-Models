#include <bits/stdc++.h>
using namespace std;

#define ll long long int 

// refer : https://www.geeksforgeeks.org/prime-factorization-using-sieve-olog-n-multiple-queries/
// refer : https://forthright48.com/spoj-lcmsum-lcm-sum/

const ll N = 1000003 ;
ll phi[N] ;
ll res[N] ;

void sieve() {

	for( ll i = 1 ; i < N ;i++)phi[i] = i ;

	for( ll i =2 ; i < N ; i++){
		if(phi[i] == i){
			for( ll j = i ; j < N ; j=j+i){
				phi[j] = phi[j]/i ;
				phi[j] *= (i-1) ;
			}
		}
	}
	res[1] = 1 ; 
	for( ll i =1 ; i < N ; i++){
			for( ll j = i ; j < N ; j=j+i){
				res[j] = res[j] + i*phi[i] ;
			}
	}
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    sieve() ;
    ll t ; cin >> t; 
    while( t-- ){

    	ll n ; cin >> n ;
    	ll ans = (res[n] + 1)*n;
    	ans /= 2;
    	cout << ans << "\n" ; 

    }
    return 0;
}
