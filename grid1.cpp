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

ll dp[1003][1003] ;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,m ; cin >> n >> m ;
	char a[1003][1003] ;
	for(int i = 1; i <= n ; i++){
		for(int j = 1; j <= m ; j++){
			cin >> a[i][j];
		}
	}
	dp[1][1] = 1 ;
	for(int i = 1; i <= n ; i++){
		for(int j = 1; j <= m ; j++){

			if( i == 1 && j==1)continue ;

			if(a[i][j] == '.'){

				if(j == 1) {
					dp[i][j] = dp[i-1][j] ;
				}
				else if ( i == 1){
					dp[i][j] = dp[i][j-1] ;
				}
				else{
					dp[i][j] = (dp[i][j-1]+dp[i-1][j])%mod ;
				}

			}
			else{
				dp[i][j] = 0;
			}

			//cout <<dp[i][j] << " " ;

		}
		//cout << "\n" ;
	}
	cout << dp[n][m] ;
  	return 0;
}