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

// This is a nlogn solution


// Not working should fix it

// Remember this is not for strictly increasing if
// we want strictly increasing keep greater sign 
// instead of greater than or equal to

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t ; cin >> t ;
	while(t--){
		int n ; cin >> n ;
		vector<ll> vi ;
		for(int i = 0 ; i < n ; i++){
			 ll x ;cin >> x ;
			 vi.pb(x) ;
		}
		vector<ll> temp;
		vector<ll> ans(n) ;

		temp.pb(vi[0]) ;
		ans[0] = 1 ;

		for(int i = 1 ; i < n ;i++){

			if(temp.back() <= vi[i]){
				temp.pb(vi[i]) ;
				ans[i] = temp.size() ;
			}
			else{
				int index = lower_bound(temp.begin(),temp.end(),vi[i]) - temp.begin() ;
				temp[index] = vi[i] ;
				ans[i] = index+1;
			}

		}
		
		cout << temp.size() << "\n" ;
	}
 	return 0;
}