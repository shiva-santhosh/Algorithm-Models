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


//finding pure cycles

const ll N = 2*(1e5) + 7 ;
vector<int> vi [N] ; 
int vist[N] ;
int cycle = 0; 
int degree[N] ;
vector<int> comp ;

void dfs(int s,int i){
	vist[s] = 1 ;
	for(auto x : vi[s]){
		if(!vist[x]){
			dfs(x,s) ;
		}
		else{
			if(i!=x)cycle = 1 ;
		}
	}
	comp.pb(s) ;
}

bool check(){
	int count_edges= 0;
	int flag = 0 ;
	for(auto x1 : comp){
		count_edges+=vi[x1].size();
		if(degree[x1] != 2)flag=1; 
	}
	count_edges=count_edges/2 ;
	if(count_edges == comp.size() && !flag)return true ;

}



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,m;cin >> n >> m ;

	for(int i = 1 ; i <= m ; i++){
		int x,y;cin >> x >> y ;
		vi[x].pb(y) ; vi[y].pb(x) ;
		degree[x]++;degree[y]++;
	}
	int ans = 0 ;
	for(int i = 1 ; i <= n ; i++){
		if(!vist[i]){

			cycle = 0 ;
			dfs(i,-1) ;
			//for(auto x : comp)cout << x << " " ;
			//cout << comp.size()  << "\n" ;
			//cout << cycle << "\n";
			if(cycle){
				if(check())ans++;
			}
			comp.clear() ;

		}
	}
	cout << ans ;
 	return 0;
}