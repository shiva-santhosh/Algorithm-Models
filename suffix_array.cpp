#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
/******************************************
* AUTHOR : PANDRAVISAM SHIVA SANTHOSH *
* Handle : santhosh_80 *
* INSTITUTION : IIT Palakkad *
******************************************/
#define ll long long int 
#define pii pair<int,int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vll vector<long long >
#define umap unordered_map
#define all(v) (v).begin(),(v).end()
#define pb push_back
#define eb emplace_back
#define f first
#define s second
#define inf LLONG_MAX
#define neg_inf LLONG_MIN
#define next_line cout << "\n"
#define what_is(x) cerr << #x << " is " << x << "\n";
#define rep(i,a,b) for(int i = a; i < b; i++)
#define repj(j,a,b) for(int j = a; j < b; j++)

inline void read0(auto &v, int n) {
	for(int i = 0; i < n; i++){cin >> v[i];}
}
inline void read1(auto &v, int n) {
	for(int i = 1; i <= n; i++){cin >> v[i];}
}
inline void out0(auto &v, int n) {
	for(int i = 0; i < n; i++){cout << v[i] << " ";}
}
inline void out1(auto &v, int n){
	for(int i = 1; i <= n; i++){cout << v[i] << " ";}
}
inline void auto_print(auto &v){
	for(auto x: v)cout << x << " ";
}

const ll mod = 1000000007;
const ll N = 1e6;


// This is O(n*logn)


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s; cin >> s;
	s+='$';
	int n = s.length();
	vector<int> p (n+1),c(n+1);
	vector<pair<char,int>> a(n);
	rep(i,0,n){
		a[i] = {s[i],i};
	}
	sort(all(a));
	rep(i,0,n){
		p[i] = a[i].s;
	}
	c[p[0]]=0;
	rep(i,1,n){
		if(a[i].f == a[i-1].f){
			c[p[i]] = c[p[i-1]];
		}
		else{
			c[p[i]] = c[p[i-1]]+1;
		}
	}
	int k = 0;
	while( (1<<k) < n){
		
		vector<pair<pii,int> > b(n);
		rep(i,0,n){
			b[i] = { { c[i], c[(i+(1<<k))%n] }, i};
		}
		sort(all(b));
		rep(i,0,n){
			p[i]=b[i].s;
		}
		c[p[0]]=0;
		rep(i,1,n){
			if(b[i].f == b[i-1].f){
				c[p[i]] = c[p[i-1]];
			}
			else{
				c[p[i]] = c[p[i-1]]+1;
			}
		}
		k++;;
	}
	rep(i,0,n){
		cout << p[i] << " ";
	}
	return 0;
}