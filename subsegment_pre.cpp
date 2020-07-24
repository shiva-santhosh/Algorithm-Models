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

vector<int> segment_sum(vector<int> &a){

	int n = a.size() ;
	vector<int> pre(n+1,0) ;

	for(int i = 0 ; i < n ; i++){
	
		int count = 0 ;
		for(int j = i; j < n; j++){
			i = j ;
			if(a[j] == 1)count++;
			else break;
		}

		int k = count ;
		//cout << k << " ";

		for(int i1 = 1; i1 <= k ; i1++){
			pre[i1] += count ;
			count--; 
		}

	}
	//cout << "\n" ;
	return pre;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll n,m,k ;cin >> n >> m >> k ;
	vector<int> a,b ;

	for(int i = 0; i < n ; i++){
		int x; cin >> x ;
		a.pb(x) ;
	}

	for(int i = 0; i < m ; i++){
		int x; cin >> x ;
		b.pb(x) ;
	}
	
	ll ans = 0 ;
	vector<int> suma = segment_sum(a) ;
	vector<int> sumb = segment_sum(b) ;

	//sfor (auto x : suma) cout << x << "  " ;

	for(int i = 1 ; i <= n ; i++){
		if( k % i == 0 && (k/i) <= m  ) {
			ans = ans + (suma[i]*sumb[k/i]) ;
		}
	}

	cout << ans ; 
 	return 0;
}