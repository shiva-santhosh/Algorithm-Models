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

const int N = 2*1e5+3 ;
int n;
vector<int> graph[N] ;
vector<int> ans ;

//good application to know about the transpose graph and also 
//about multisource bfs.

void multisource_bfs(vector<int> &s ,vector<int> &dest){

		vector<int> d(n+3,INT_MAX) ;
		queue<int> q ;
		for(auto x : s) {
			d[x] = 0 ;
			q.push(x) ;
		}
		while(!q.empty()){
			int v = q.front() ;
			q.pop() ;
			for(auto x : graph[v]) {
				if(d[x] == INT_MAX) {
					d[x] = d[v] + 1 ;
					q.push(x) ;
				}
			}
		}
		for(auto x : dest){
			if(d[x] != INT_MAX){
				ans[x] = d[x] ;
			}
		}
}



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	vector<int> a(n+2) ;
	vector<int> odd,even;
	for(int i = 1 ; i <= n ; i++){
		cin >> a[i] ;
		if(a[i]&1)odd.pb(i) ;
		else even.pb(i) ;
	}

	//constructing the transpose graph  
	for(int i = 1; i <= n ; i++){
		if((i-a[i]) >= 1) graph[i-a[i]].pb(i) ;
		if((i+a[i]) <= n ) graph[i+a[i]].pb(i) ;
	}

	ans = vector<int> (n+2,-1) ;

	multisource_bfs(odd,even) ;
	multisource_bfs(even,odd) ;

	for(int i = 1 ; i <= n ; i++)cout << ans[i] << " " ;

 	return 0;
}