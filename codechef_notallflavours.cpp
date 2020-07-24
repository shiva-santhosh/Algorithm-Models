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
		int n,k; cin >> n >> k ;
		vector<int> a ;
		for(int i =0 ;i < n ; i++){
			int x; cin >> x ;
			a.pb(x) ;
		}
		int i = 0 , j = 1 ;
		int max_length = 1 ;
		set<int> s ; 
		map<int,int> m ;
		s.insert(a[i]) ; m[a[i]]++;
		int flag = 0 ;
		while(j < n){

			if( !flag ){
				if(m[a[j]] == 0 ) s.insert(a[j]) ; 
				m[a[j]]++ ;
			}

			if(s.size() != k ){
				max_length = max (max_length ,j-i+1) ;
				j++;
				flag = 0 ;
			}
			else{
				m[a[i]]--;
				if(m[a[i]] == 0)s.erase(s.find(a[i])) ;
				i++;
				flag = 1 ;
			}
		}

		cout << max_length << "\n"  ;
	}
 	return 0;
}