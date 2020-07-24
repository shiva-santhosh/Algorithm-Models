#include <bits/stdc++.h>
using namespace std;
/******************************************
* AUTHOR : PANDRAVISAM SHIVA SANTHOSH *
* Handle : santhosh_80 *
* INSTITUTION : IIT Palakkad *
******************************************/
#define ll long long int 
#define rep(i,a,b) for(int i=a;i<b;i++)
#define repj(j,a,b) for(int j=a;j<b;j++)
#define pii pair<int,int>
#define all(v) (v).begin(),(v).end()
#define pb push_back
#define f first
#define s second

const ll mod = 1000000007;
const ll N = 1<<20 + 5;

/*

check(i) -> b&(1<<i)
set(i) -> b|(1<<i)
unset(i) -> b | ~(1<<i) 
count(x) -> __bultin_popcount(x)

*/

ll dp[N];
int a[21][21];


void reset(int n){
	rep(i,0,n)dp[i]=0;
}


int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t; cin >> t;
	while(t--){

		int n;cin >> n;
		rep(i, 0, n){
			repj(j, 0, n){
				cin >> a[i][j];
			}
		}

		dp[0]=1;
		int maxval = 1<<n;

		rep(i, 0, maxval){
			int num = __builtin_popcount(i);
			repj(j, 0, n){
				if(a[num][j] == 1 && !(i&(1<<j)) ){

					dp[i|(1<<j)] = dp[i|1<<j] + dp[i];

				}
			}
		}
		cout << dp[maxval-1] << "\n";
		reset(maxval);
	}
 	return 0;
}