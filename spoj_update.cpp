#include <bits/stdc++.h>
using namespace std;

#define ll long long int 

// Very cool technique ;
// updating a range in a array 

void solve() {
	ll n ; ll u  ;
	cin >> n >> u ;
	ll a[n+3] ;
	memset(a , 0 , sizeof(a) ) ;
	while( u-- ) {
		ll val , l , r ;
		cin >> l >> r >> val ;
		a[l]+=val ;
		a[r+1]-=val ;
	}
	ll count = 0;
	for( int i = 0 ; i < n ; i++ ){
		count+=a[i] ;
		a[i] = count ;
		cout << a[i] << " " ;
	}
	ll q ;
	cin >> q ;
	while ( q-- ) {
		ll i ; cin >> i ;
		cout << a[i] << "\n" ;
	} 
}

int main()
{
	int t ; cin >> t ;
	while(t--) {
    	solve() ;
    }
    return 0;
}


