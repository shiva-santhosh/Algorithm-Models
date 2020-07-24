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
#define Sl(x) scanf("%lld",&(x))
#define Pl(x) printf("%lld\n",(x))
#define pb push_back
#define f first
#define s second

const ll N = 1003 ;

vector<int> graph[N] ;
vector<int> parent(N,-1) ;
vector<int> level(N,0) ;
vector<vector<int> > P(N,vector<int>(20,-1));

void preprocess_tree(int n){
	for(int i = 1 ; i <= n ; i++){
		P[i][0] = parent[i] ;
	}
	for(int j = 1; j < 20 ; j++){
		for(int i = 1; i <= n ; i++){
			if(P[i][j-1] !=-1){
				P[i][j] = P[P[i][j-1]][j-1];
			}
		}
	}
}

int find_lca(int u,int v){

	if(level[u] < level[v]){
		swap(u,v) ;
	}
	int dist = level[u] - level[v] ;
	while(dist > 0){
		int r = log2(dist) ;
		u = P[u][r] ;
		dist = dist - (1<<r) ;
 	}
 	if( u == v)return u ;

 	for(int j = 19; j >= 0 ; j--){
 		if(P[u][j] != -1 && P[u][j] != P[v][j]){
 			u = P[u][j] ;
 			v = P[v][j] ;
 		}
 	}
 	return parent[u] ;
}

void dfs(int s, int p){

	for(auto x : graph[s]) {
		if(x != p){
			//parent[x] = s ;
			level[x] = level[s] + 1 ;
			dfs(x,s);
		}
	}
}

void init(){
	for(int i = 1; i < N ; i++){
		graph[i].clear() ;
		parent[i] = -1;
		level[i] = 0;
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t; cin >> t ;
	int case_num = 1 ; 
	while(t--){
		init() ;
		int n ; cin >> n ;
		//cout << "abc\n" ;
		for(int i = 1; i <= n ; i++){
			int n1 ; cin >> n1 ;
			for(int j = 0; j < n1 ; j++){
				int x; cin >> x ;
				parent[x] = i ;
				graph[x].pb(i) ;
				graph[i].pb(x) ;
			}
		}
		//cout << "abc1\n" ;
		for(int i = 1; i <= n ; i++){
			if(parent[i] == -1){
				dfs(i,-1) ;
				parent[i] = i ;
			}
		}
		preprocess_tree(n) ;
		int q; cin >> q ;
		cout << "Case " << case_num << ":" << "\n" ;
		while(q--){
			int u,v ; cin >> u >> v ;
			cout << find_lca(u,v) << "\n" ;
		}
		case_num++;
	}
 	return 0;
}

