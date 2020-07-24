#include <bits/stdc++.h>
using namespace std;

#define ll long long int 

ll phi( ll n ) {

	ll res = n ;
	for ( ll i = 2 ; i * i <= n ; i++){
		if( n % i == 0 ){
			while( n % i == 0 ) n = n / i ;
			res = res - res / i ;
		}
	}

	if(n > 1) res = res - res / n ; 
	return res ;
} 

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t ; cin >> t ;

    while ( t-- ) {
    	ll n ; cin >>  n ;
    	cout << phi(n) << "\n" ;
    }
    return 0;
}
