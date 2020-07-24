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

//dp[n][k][p]
ll dp[52][1507] ;
vector<int> v[52] ;
int n,k,p ;

void init(){
	for(int i = 0; i <= 50; i++){
		for(int j = 0; j <= 1507; j++){
			dp[i][j] = -1;
		}
		v[i].clear() ;
	}
}

ll solve(int i,int pl){

	if(pl == 0)return 0 ;
	if(pl < 0) return LLONG_MIN ;
	if(i > n)return LLONG_MIN ;

	if(dp[i][pl] != -1)return dp[i][pl] ;

	ll ans =  0;
	ll prefix_sum = 0;
	for(int j = 0 ; j <= k ; j++){
		prefix_sum = prefix_sum + v[i][j] ;
		ans = max(ans,prefix_sum+solve(i+1,pl-j));
	}
	dp[i][pl] = ans ;
	return dp[i][pl] ;
}



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t ; cin >> t ;
	int casenum = 1;
	while(t--){
		init();
		cin >> n >> k >> p;
		for(int i = 1; i <= n ; i++){
			v[i].pb(0) ;
			for(int j = 1; j <= k ;j++){
				int x;cin >> x;
				v[i].pb(x); 
			}
		}
		cout << "Case #" << casenum << ": ";
		ll max_ans = solve(1,p) ;
		cout << max_ans << "\n" ;
		casenum++;
	}
 	return 0;
}