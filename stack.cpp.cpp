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


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t ; cin >> t ;
	while(t--){

		int n ; cin >> n ;
		int A[n] ;
		for(int i = 0 ; i < n ; i++)cin >>A[i] ;
		stack<int> s ;
		vector<int> v(n);
		for(int i = n-1 ; i >= 0; i--){
	        while(!s.empty() && A[s.top()] < A[i]){
	            v[s.top()] = A[i];
	            s.pop();
	        }
	        s.push(i);
	    } 
	    vector<int> ans(n) ;
	    for(int i = n-1 ; i >= 0 ; i--){
	    	ans[i] = v[i] - i + 1;
	    } 
	    for(auto x : v)cout << x << " " ;
	    cout << "\n" ;

	}
 	return 0;
}