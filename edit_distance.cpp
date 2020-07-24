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

int dp[3000][3000] ;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t ; cin >> t;
	while(t--) {

		string s1,s2;
		cin >> s1 >> s2 ;
		int n1 = s1.length(),n2 =s2.length() ;

		for(int i = 0; i < n1; i++){
			for(int j = 0; j < n2; j++){
				dp[i][j] = INT_MAX ;
			}
		}

		for(int i = 0; i < n1 ; i++){
			for(int j = 0; j < n2 ; j++){

				if(i == 0 && j == 0){
					if(s1[i] == s2[j])dp[i][j] = 0;
					else dp[i][j]=1;
					continue ;
				}

				if( i == 0){
					int c = 1 ;
					if(s1[i] == s2[j])c=0;
					dp[i][j] = min(dp[i][j-1]+1, j+c);
					continue ;
				}

				if(j == 0) {
					int c = 1 ;
					if(s1[i] == s2[j])c=0;
					dp[i][j] = min(dp[i-1][j]+1, i+c);
					continue ;
				}
				int c = 1;
				if(s1[i] == s2[j])c = 0;
				dp[i][j] = min (dp[i][j-1]+1, min(dp[i-1][j]+1,dp[i-1][j-1]+c)) ;

			}
		}
		cout << dp[n1-1][n2-1] << "\n" ;
	}
 	return 0;
}