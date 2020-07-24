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

const int k = 1e5+3

int dp[101][k] ;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int a[103] ;
	int n,k;cin >> n >> k ;
	for(int i = 1; i <= n ; i++)cin >> a[i] ;

	for(int i = 1; i <= n ; i++){
		for(int j = 1; j <= k; j++){
			
		}
	}

 	return 0;
}