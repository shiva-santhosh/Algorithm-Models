#include <iostream>
using namespace std;

#define ll long long int

int main() {
	
	ll ans[101] ;
	ans[0] = 0;
	for(int i = 1; i <= 100 ; i++){
		ans[i] = i*i
		ans[i] += ans[i-1] ; 
	}
		
	while(1){
		ll n ; cin >> n ;
		if(n==0)break;
		cout <<ans[n] << "\n" ;
	}

	return 0;
}