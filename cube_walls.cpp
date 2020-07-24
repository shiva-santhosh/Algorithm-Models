#include <bits/stdc++.h>
using namespace std;
/******************************************
* AUTHOR : PANDRAVISAM SHIVA SANTHOSH *
* Handle : santhosh_80 *
* INSTITUTION : IIT Palakkad *
******************************************/
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

const ll sep = 1e10;


ll prefix_function(vector<int> &v1,vector<int> &v2) {

		if(v1.size() == 0)return v2.size()+1 ;

		int n1 = v1.size();
		int n2 = v2.size() ;

		vector<int> prefix(n1+n2+3,0) ;
		int ans = 0 ;

		vector<ll> v;

		for(int i = 0; i < n1; i++){
			v.pb(v1[i]) ;
		}
		v.pb(sep) ;
		for(int i = 0; i < n2; i++){
			v.pb(v2[i]) ;
		}

		for(int i = 1; i < v.size(); i++) {
			int j = prefix[i-1] ;
			while( j>0 && v[i] != v[j]) {
					j = prefix[j-1] ;
			}
			if(v[i] == v[j])j++ ;
			prefix[i] = j ;
		}

		for(int i = n1+1; i < v.size() ; i++){
			if(prefix[i] == n1)ans++;
		}

    	return ans ;
}	

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n1,n2 ; cin >> n2 >> n1 ;
	vector<int > v2,v1 ; 
	for(int i = 0; i < n2 ; i++){
		int x; cin >> x ;
		v2.pb(x) ;
	}
	for(int i = 0 ; i< n1 ; i++){
		int x; cin >> x ;
		v1.pb(x) ;
	}
	vector<int> v1i,v2i ;
	for(int i = 1; i < n2; i++)v2i.pb(v2[i]-v2[i-1]);
	for(int i = 1; i < n1; i++)v1i.pb(v1[i]-v1[i-1]);
	cout << prefix_function(v1i,v2i) ;
 	return 0;
}





















