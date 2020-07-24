#include <bits/stdc++.h>
using namespace std;

#define ll long long int 

const int N=1e5+7;
ll dist[N];
vector< pair<int , int> > v[N];
ll parent[N];
bool vist[N];
ll n;

void dijsktra(){
	for(int i=1;i<=n;i++){
		dist[i]=LLONG_MAX;
		vist[i]=false;
	}
	set< pair< ll, ll > > s;
	s.insert({0,1});
	dist[1]=0;
	while(!s.empty()){
		pair< ll , ll > curr= *s.begin();
		s.erase(s.begin());
		ll u=curr.second;
		if(vist[u]) continue;
		vist[u]=true;
		//cout<<"u\n"<<u;
		for(auto x : v[u]){
			ll w=x.first; ll v1=x.second;
			if(dist[u]+w<dist[v1]){
				dist[v1]=dist[u]+w;
				parent[v1]=u;
				s.insert({dist[v1],v1});
			}
		}
	}
	if(parent[n]==0)cout<<"-1";
	else{
		ll x=n;
		stack <int> s;
		while(parent[x]!=0){
			s.push(x);
			x=parent[x];
		}
		cout<<"1 ";
		while(!s.empty()){
			cout<<s.top()<<" ";
			s.pop();;
		}

	}
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll m; cin >> n >> m;
    int x,y,w;
    while(m--){
    	cin >> x >> y >>w;
    	v[x].push_back({w,y});
    	v[y].push_back({w,x});
    }
    dijsktra();
    return 0;
}
