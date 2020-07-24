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
void couting_sort(vi &p, vi &c){
	int n = p.size();
	vi count(n,0);
	vi p_new(n);
	vi pos(n);
	for(auto x: c){
		count[x]++;
	}
	pos[0]=0;
	rep(i,1,n){
		pos[i]=pos[i-1]+count[i-1];
	}
	for(auto x : p){
		int i = c[x];
		p_new[pos[i]] = x;
		pos[i]++;
	}
	p = move(p_new);
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s; cin >> s;
	s+='$';
	int n = s.length();
	vi p (n),c(n);
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
		
		rep(i,0,n){
			p[i] = (p[i]-(1<<k)+n)%n;
		}
		couting_sort(p,c);
		vi c_new(n);
		c_new[p[0]] = 0;
		rep(i,1,n){
			pii prev = {c[p[i-1]], c[(p[i-1]+(1<<k))%n]};
			pii now = {c[p[i]], c[(p[i]+(1<<k))%n]};

			if(prev == now){
				c_new[p[i]] = c_new[p[i-1]];
			}
			else{
				c_new[p[i]] = c_new[p[i-1]]+1;
			}
		}
		c=move(c_new);
		k++;;
	}
	int t; cin >> t;
	while(t--){

		string s1; cin >> s1;
		int n1 = s1.length();

		int low = 0, high = n-1;
		int l = 0, r = 0;
		while(low <= high){
			int mid = (low+high)/2;
			string dummy;
			int i = p[mid];

			repj(j,0,n1){
				dummy+=s[(i+j)%n];
			}

			if(dummy <= s1){
				if(dummy == s1){
					r=mid;
				}
				low = mid+1;
			}
			else{
				high = mid -1;
			}
		}
		low = 0,high = n-1;

		while(low <= high){
			int mid = (low+high)/2;
			string dummy;
			int i = p[mid];

			repj(j,0,n1){
				dummy+=s[(i+j)%n];
			}

			if(dummy >= s1){
				if(dummy == s1){
					l=mid;
				}
				high = mid-1;
			}
			else{
				low = mid+1;
			}
		}
		
		if(l==0 && r==0){
			cout << "0\n";
			continue;
		}
		cout << (r-l)+1 << "\n";
	}
	return 0;
}