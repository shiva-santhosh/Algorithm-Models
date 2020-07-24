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


void multiply(vector<vector<int>> &mat1, vector<vector<int>> &mat2, vector<vector<int>> &res) 
{ 
    int i, j, k; 
    int N = mat1[0].size() ; 
    for (i = 0; i < N; i++) 
    { 
        for (j = 0; j < N; j++) 
        { 
            res[i][j] = 0; 
            for (k = 0; k < N; k++) 
                res[i][j] = (res[i][j] + mat1[i][k] * mat2[k][j]) % mod; 
        } 
    } 
} 
// recurrence for f(n) = f(n-1)+f(n-2)+f(n-1)*f(n-2) ;

vector<vector<int>> modified_fibonacci( ll n) {

		vector<vector<int>> f ={ {1,1,1},
								 {1,0,0},
								 {0,1,0}
									} ;

		vector<vector<int>> res = {{1,0,0},
								   {0,1,0},
								   {0,0,1}
									} ;

		while(n){

				if( n & 1){
					vector<vector<int>> temp(3,vector<int>(3,0)) ;
					multiply(res,f,temp) ;
					res = temp; 
				}

				vector<vector<int>> temp(3,vector<int>(3,0)) ;
				multiply(f,f,temp) ;
				f = temp ;

				n = n >> 1;
		}
		return res;

}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t; cin >> t ;
	while(t--){
		ll n,p,q;cin >> p >>q >> n;
		vector<vector<int>> res = modified_fibonacci(n) ;
		for(int i = 0; i < 3 ; i++){
			for(int j = 0; j < 3; j++){
				cout << res[i][j] << " ";
			}
			cout  << "\n" ;
		}
		ll prod = (p*q)%mod ;
		ll a1 = res[0][0] ; ll a2 = res[0][1] ; ll a3 = res[0][2] ;
		ll final_ans = ( (a1*q)%mod + (a2*p)%mod + (a3*prod)%mod ) % mod ;
		cout << final_ans << "\n" ;
	}
 	return 0;
}