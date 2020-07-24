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

const int N = 1e5 +1;

int dp[N] ;
vector<int> vi[N] ;

int vist[N] ;

void dfs(int i) {
	vist[i] = 1 ;
	for(auto x : vi[i]){
		if(!vist[x])dfs(x) ;
		dp[i] = max(dp[i],dp[x]+1);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,m ; cin >> n >> m ;
	for(int i = 0; i < m ; i++){
		int x,y;cin >> x >> y ;
		vi[x].pb(y) ;
	}
	for(int i = 1 ; i <= n ; i++){
		if(!vist[i])dfs(i) ;
	}
	int max1 = -1;
	for(int i = 1; i <= n ; i++){
		//cout << dp[i] << " " ;
		max1 = max(dp[i],max1) ;
	}
	cout << max1 ;
 	return 0;
}