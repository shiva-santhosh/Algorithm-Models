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

//can be used for all values of p which are not co-prime with 10 

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	//int n;cin >> n ;
	int p = 2019 ;
	unordered_map<int ,ll> m ;
	ll pow_10 = 1;
	ll ans = 0;
	ll rem = 0;
	string str;cin >> str;
	int n = str.size();
	m[0]++;

	for(int i = n-1; i >= 0; i--){

		int x = str[i]-'0';
		rem = (rem + pow_10*x)%p ;
		m[rem]++;
		pow_10 = (pow_10*10)%p;
		rem=rem%p;
	}

	for(auto x : m){
		//if(x.f == 0)continue;
		ans = ans + (x.s)*(x.s-1)/2;
	}

	cout << ans;

 	return 0;
}
