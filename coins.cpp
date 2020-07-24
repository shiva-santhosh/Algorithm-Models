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

double dp[3000][3000] ;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n ; cin >> n ;
	vector<double> vi(n+1) ;

	for(int i = 1 ; i <= n ; i++){
		cin >> vi[i] ;
	}

	dp[0][0] = 1.0 ;

	// dp is all about how you are dividing the subproblem, if you
	// get it , then you got it 

	for(int i = 1; i <= n ; i++){
		for(int j = 0; j <= i ; j++) {

			if( j == 0){
				dp[i][j] = dp[i-1][j]*(1.0-vi[i]);
			}
			else{
				dp[i][j] = dp[i-1][j-1]*vi[i] +dp[i-1][j]*(1.0-vi[i]) ;
			}

		}
	}

	double ans = 0.0 ;

	for(int i = (n+1)/2 ; i <= n ; i++)ans+=dp[n][i] ;

	cout << setprecision(11) << ans ;

 	return 0;
}