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

int dp[3003][3003] ;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s,t ; cin >> s >> t ; 
	s = " " + s ; t = " " + t ; 
	int n = s.length(), m = t.length() ;
	int parent[m] ;
	for(int i = 1; i < n ; i++){
		for(int j = 1; j < m ;j++){

				if(s[i] == t[j]) {
					dp[i][j] = dp[i-1][j-1] + 1 ;
				}
				else{
					if(dp[i-1][j] > dp[i][j-1] ) {
						dp[i][j] = dp[i-1][j] ;
					}
					else{
						dp[i][j] = dp[i][j-1] ;
					}
				}
		}
	}

	int i, j; 
	i = n-1; j = m-1; 
	stack<char> s1;

	while(1) {

		if( i < 1  ||  j < 1)break ;
		if(s[i] == t[j] ){
			s1.push(s[i]) ;
			i=i-1;j=j-1;
			continue ;
		}
		else{
			if(i >= 1 && j >=1){
				if(dp[i-1][j] > dp[i][j-1])i=i-1;
				else j=j-1;
			}
		}
	} 

	while(!s1.empty()){
		cout << s1.top() ;
		s1.pop();
	}

 	return 0;
}