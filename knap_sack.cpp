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

ll dp[100003];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n,W ;cin >> n >> W ;
	ll w[n+3] , v[n+3] ;
	ll max_val = 0 ;
	for(int i = 1; i <= n ; i++ ){
		cin >> w[i] ;
		cin >> v[i] ;
		max_val+=v[i] ;
	} 
	for(int j = 0; j <= max_val ; j++){
		 dp[j] = LLONG_MAX; ;
	}

	dp[0] = 0 ;

	for(int i = 1 ;i <= n ; i++){
		for(int j = max_val; j >= 0; j--){

				if(dp[j] != LLONG_MAX){
					dp[j+v[i]] = min(dp[j]+w[i],dp[j+v[i]]) ;
				}

		}

	}
	ll ans = -1;
	for(int  i = max_val ; i >= 0; i--){
		if(dp[i] <= W) {
			ans = i ;
			break ;
		}
	}
	cout << ans ;

 	return 0;
}