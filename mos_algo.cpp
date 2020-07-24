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

const int N = 3*(1e4) + 4; 
const int N1 = 1e6+7 ;
const int Block = 180;
int counter[N1] ;
vector<int> num(N+1,0);
int distinct = 0;

void fastscan(int &number) 
{ 
    bool negative = false; 
    register int c; 
    number = 0; 
    c = getchar(); 
    if (c=='-') 
    {  
        negative = true; 
        c = getchar(); 
    } 
    for (; (c>47 && c<58); c=getchar()) 
        number = number *10 + c - 48; 

    if (negative) 
        number *= -1; 
} 

inline bool cmp(pair<pair<int,int>,int>& a,pair<pair<int,int>,int>& b){
    if(((a.f).f)/Block != ((b.f).f)/Block ){
        return ((a.f).f) <  ((b.f).f) ;
    }
    return ( (a.f).f/(Block) & 1 ) ? ((a.f).s< (b.f).s) : ((a.f).s > (b.f).s);
}


inline void incr(int pos){
	counter[num[pos]]++;
	if(counter[num[pos]] == 1)distinct++;
}

inline void desc(int pos){
	counter[num[pos]]--;
	if(counter[num[pos]] == 0)distinct--;
}

int main() {

	int n,m;
	fastscan(n);

	for(int i = 0; i < n ; i++)fastscan(num[i]) ;

	int q; fastscan(q);

	vector<pair<pair<int,int>,int>> m1;

	for(int i = 0 ; i < q ; i++){
		int l,r;
		fastscan(l); fastscan(r);
		m1.pb({{l,r},i});
	}

	sort(m1.begin(),m1.end(),cmp);
	
	int currentl=0,currentr=-1;

	int ans[q+2];
	int t = 0 ;

	while(t < q){
		int l = (m1[t].f).f, r = (m1[t].f).s ;
		l--;r--;
		while(currentl < l){
			desc(currentl);
			currentl++;
		}
		while(currentl > l){
			currentl--;
			incr(currentl);
		}
		while(currentr < r){
			currentr++;
			incr(currentr);
		}
		while(currentr > r ){
			desc(currentr);
			currentr--;
		}
		ans[m1[t].s] = distinct;
		t++;
	}
	
	for(int i = 0; i < q ; i++){
		printf("%d\n",ans[i]);
	}

 	return 0;
}
