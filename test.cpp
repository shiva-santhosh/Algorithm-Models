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

/*
	freopen("input.txt","r",stdin) ;
	freopen("output.txt","w",stdout) ;
*/

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int a,b;cin >> a>> b ;
	indexed_set s ;
	s.insert(2) ;s.insert(3) ;s.insert(a) ;s.insert(b) ;
	auto it = s.find_by_order(3) ;
	cout << *it << log2(17) ;
	cout << a+b ;
 	return 0;
}





