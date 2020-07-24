#include <bits/stdc++.h>
using namespace std;

#define ll long long int 

bitset <100000000>  prime ;

void sieve() { 

	for( ll i =1 ; i< 100000000 ; i++)
		prime[i] = 1;

	for( ll i = 2; i * i < 100000000 ; i++) {
		if ( prime[i] ){
			//v.push_back(i) ;
			for( ll j = i*i ; j < 100000000 ; j = j + i )
				prime[j] =  0;
		}
	}
	ll count =0 ;
	for( ll i = 2 ; i < 100000000 ; i++) {

		if (prime[i]){
			count++ ;
			if(count%100 == 1)
				printf("%lld\n",i );
		}
	}
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    sieve() ;
    return 0;
}