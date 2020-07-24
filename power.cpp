#include <bits/stdc++.h>
using namespace std;


#define ll long long int 


// computing a^b

ll binary_power(ll a, ll b) {

	ll res = 1 ;
	while(b){
			if( b & 1)
				res = res * a ;
			a = a * a ;
			b = b >> 1 ;
	}
	return res ;
}

// computing a^b % m

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

// calculating nth fibonacci number in O(log(n)) complexity

ll fibonacci( ll n) {

		ll f[4] = { 0 , 1 , 1, 1} ; // fibonaci matrix

		ll r[4] = { 1 , 0 , 0, 1} ; // identity matrix

		ll t1 ,t2 ,t3 ,t4 ;

		while(n){

				if( n & 1){

					t1 = r[0] * f[0] + r[1] * f[2] ;
					t2 = r[0] * f[1] + r[1] * f[3] ;
					t3 = r[2] * f[0] + r[3] * f[2] ;
					t4 = r[2] * f[1] + r[3] * f[3] ;
					r[0] = t1;
					r[1] = t2 ;
					r[2] = t3 ;
					r[3] = t4 ;

				}

				t1 = f[0] * f[0] + f[1] * f[2] ;
				t2 = f[0] * f[1] + f[1] * f[3] ;
				t3 = f[2] * f[0] + f[3] * f[2] ;
				t4 = f[2] * f[1] + f[3] * f[3] ;

				f[0] = t1;
				f[1] = t2 ;
				f[2] = t3 ;
				f[3] = t4 ;

				n = n >> 1;
		}
		return r[2] ;

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll res =binary_power( 4 , 2) ;
    ll res1=binary_power_mod( 100 , 10 , 1000000007) ;
    for(int i = 0 ; i < 10 ; i++ ){
    ll f5 = fibonacci(i) ;
    cout << f5 << "\n";
	}
    return 0;
}
