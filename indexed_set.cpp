#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
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

typedef tree<int,null_type,less<int>,rb_tree_tag,
tree_order_statistics_node_update> indexed_set;

const ll mod = 1000000007;
const ll N = 1e6;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	indexed_set s1;
	int q;cin >> q;
	rep(i,0,q){
		char c;int x;
		cin >> c >> x;
		if(c == 'I'){
			s1.insert(x);
		}
		else if(c == 'D'){
			auto it = s1.find(x);
			if( it != s1.end() ){
				s1.erase(it);
			}
		}
		else if(c == 'K'){
			if(x > s1.size()){
				cout << "invalid\n";
				continue;
			}
			auto it = s1.find_by_order(x-1);// given the position like array index
			cout << *it << "\n";			// it will give out the value
		}
		else{
			int index1 = s1.order_of_key(x);// it will be give the index of the position
			cout << index1 << "\n";			// if not there. it will give the index of the position
		}									// if it was there
	}
 	return 0;
}