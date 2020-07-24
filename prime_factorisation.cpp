#include <bits/stdc++.h>
using namespace std;

#define ll long long int 

vector< pair <ll , ll > > prime_factorisation(ll n) {
	vector< ll > v ;
	vector< pair< ll , ll> > v1;

	ll count = 0;
	while(n%2 == 0 ) {
		v.push_back(2) ;
		count++ ;
		n=n/2;
	}
	if(count != 0)
	v1.push_back({2,count}) ;

	for( ll i = 3 ; i*i <= n ; i=i+2) {
		count =0;
		while(n%i == 0 ) {
			v.push_back(i) ;
			count++ ;
			n=n/i;
		}
		if( count != 0)v1.push_back({i,count}) ;
	}
	if( n > 1) v1.push_back({n,1}) ;

	return v1 ;
}



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while(1){
    	ll n ; cin >> n ;
    	if(n == 0 )break ;
    	vector< pair< ll , ll > > v1 = prime_factorisation(n);
    	for(auto x : v1) {
    		cout << x.first << "^" << x.second <<  " " ;
    	}
    	cout << "\n" ;
    }
    return 0;
}
