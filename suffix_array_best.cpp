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


// p array contains the sorted suffix array

// c array contains the inverse mapping of the sorted array
// for i, it will  give the position of the in the sorted array


// lcp constains the longest comman prefix of the adjacent sorted sufficx strings



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
	p = p_new;
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
		c=c_new;
		k++;;
	}
	/*
	rep(i,0,n){
		cout << p[i] << " ";
	}
	*/
	k = 0;
	vector<int> lcp(n);
	rep(i,0,(n-1)){
		int pos = c[i];
		int before = p[pos-1];
		while(s[i+k] == s[before+k])k++;
		lcp[pos]=k;
		k=max(0,k-1);

	}
	//next_line;
	/*
	rep(i,1,n){
		cout << lcp[i] << " ";
	}
	*/
	ll  num_of_string = 0;

	rep(i,1,n){
		num_of_string += (n-i)-lcp[i];
	}

	cout << num_of_string << "\n";




	return 0;
}