#include <bits/stdc++.h>
using namespace std;
/******************************************
* AUTHOR : PANDRAVISAM SHIVA SANTHOSH *
* Handle : santhosh_80 *
* INSTITUTION : IIT Palakkad *
******************************************/
#define ll long long int 
#define rep(i,a,b) for(int i=a;i<b;i++)
#define pii pair<int,int>
#define all(v) (v).begin(),(v).end()
#define pb push_back
#define f first
#define s second

const ll mod = 1000000007;
const ll N = 1e6;
ll sum = 0;
int n,m,q;
vector<int> a;
vector<pair<pair<int,int>,pair<int,int>> >v;

// full search model generating subsequences 
// which are incresing order

void full_search(int pos,int past){

	if(a.size() == n){
		
		ll temp= 0;
		for(int i = 0; i < q; i++){

			// remember it is zero based index
			if( (a[v[i].f.s-1] - a[v[i].f.f-1]) == v[i].s.f){
				temp+=v[i].s.s;
			}
		}
		sum = max(temp,sum);
		return;
	}
	for(int i = past;  i <= m ;i++){
		a.pb(i);
		full_search(pos+1,i);
		a.pop_back();
	}

}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m >> q;
	//vector<int> a(n+1,0);
	for(int i = 0; i < q; i++){
		int a,b,c,d;
		cin >> a >>b >> c >> d;
		v.pb({{a,b},{c,d}});
	}
	full_search(0,1);
	cout << sum << "\n";
 	return 0;
}