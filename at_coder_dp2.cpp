#include <bits/stdc++.h>
using namespace std;

#define ll long long int 

const ll N = 2e5+7 ;
ll dp[N] ;

ll min_cost(ll h[] , ll n , ll k){
	if( n <= 0 ){
		dp[0] = 0 ;
		return dp[0] ;
	}
	
	if(	dp[n] != -1) return dp[n] ;

	if( n == 1 ) {
		dp[1] = 0;
		return dp[1] ;
	}
	if( n == 2 ) {
		dp[2] = abs(h[2] - h[1]) ;
		return dp[2] ;
	}
	if(n <= k) {

		ll min1 = LONG_MAX ;
		for(int i = 1 ; i <n ; i++){
			min1 = min ( min1 , min_cost(h , n - i , k) + abs(h[n] - h[n-i]) ) ;
		} 
		dp[n] = min1 ;
		return dp[n] ;

	}
	ll min2 = LONG_MAX ;
	for(int i = 1 ; i <= k ;i++  ){
		min2 = min(min_cost(h,n-i,k) + abs(h[n] - h[n-i]) ,min2) ;
	}
	dp[n] = min2 ;
	return dp[n] ;
}


void solve(ll n , ll k) {
	ll h[n+2] ;
	for(int i = 1; i <= n ; i++ ){
		cin >> h[i] ;
	} 
	memset(dp , -1 , sizeof(dp) ) ;
	cout << min_cost(h,n,k) ;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n , k ; cin >> n >> k ; 
    solve(n,k) ;
    return 0;
}
