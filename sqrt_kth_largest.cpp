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

map<int,ll> m;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n,q;cin >> n >> q;
	vector<pair<ll,ll>> a;

	for(int i = 0; i < n ; i++){
		ll x;cin>>x;
		a.pb({x,i});
	}

	int count = 0;
	vector<int> rev;
	sort(all(a));
	for(auto x : a){
		m[x.s] = x.f ;
		rev.pb(x.s);
		count++;
	}
	int len = int(sqrt(n))+1 ;

	vector<int> b(len+1);
	vector<int> v[len+1];

	for(int i = 0; i < n ; i++){
		b[i/len] = rev[i];
		v[i/len].pb(rev[i]);
	}

	for(int i = 0; i < len ; i++){

		if(!v[i].empty())sort(all(v[i]));

	}

	while(q--){

		int l,r,k;
		cin >> l >> r >> k;

		l--;r--;
		int i = 0;
		int count = 0 ;

		for(; i < len; i++){

			int occ = upper_bound(v[i].begin(),v[i].end(),r) -lower_bound(v[i].begin(),v[i].end(),l);
			count = count + occ ;
			if(count >= k){
				count = count - occ;
				break;
			}

		}
		int ans;
		for(int j = (i)*len ; ; j++){
			if( l <= rev[j] && rev[j] <= r ){
				count++;
			}
			if(count == k){
				ans = rev[j];
				break;
			}
		}
		cout << m[ans] << "\n" ;

	}

 	return 0;
}