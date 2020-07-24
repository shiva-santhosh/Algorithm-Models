#include <bits/stdc++.h>
using namespace std;

const int N=4e5+9;
bitset<26> seg[N];
void construct(string& str,int l ,int h ,int pos){
	if(l==h){
		seg[pos][str[l]-'a'] = 1 ;
		return;
	}
	int mid=(l+h)/2;
	construct(str,l,mid,2*pos);
	construct(str,mid+1,h,2*pos+1);
	seg[pos] = seg[2*pos] | seg[2*pos + 1] ;
}
bitset<26> query(string& str,int l ,int h ,int ql ,int qh ,int pos ){

	if( ql <=l && qh >= h)return seg[pos];
	if(qh<l || ql> h) {
		bitset<26> m;
		return  m ;
	}
	int mid=(l+h)/2;
	bitset<26> t1 = query(str,l,mid,ql,qh,2*pos) ;
	bitset<26> t2 = query(str,mid+1,h,ql,qh,2*pos+1) ;
	bitset<26> x ;
	x = t1 | t2 ;
	return x ;
}

void update(string& str,int l ,int h ,int u ,int pos){

	if(l==h){
		seg[pos].reset() ;
		seg[pos][str[l]-'a'] = 1 ;
		return;
	}
	int mid=(l+h)/2;
	if(l<= u && u <=mid )update(str,l,mid,u,2*pos);
	else update(str,mid+1,h,u,2*pos+1);
	seg[pos].reset() ;
	seg[pos] = seg[2*pos] | seg[2*pos+1] ;
}

void solve() {
		string str ; str = str + " " ;
		string x1 ;cin >> x1 ;
		int n = x1.size() ; 
		str= str + x1;
		int q ; cin >> q ;
		construct (str , 1 , n , 1) ;
		while( q-- ) {
			int x ; cin >> x ;
			if( x == 1 ) {
				int pos ; char c;
				cin >> pos >> c ;
				str[pos] = c ;
				update(str , 1, n , pos , 1) ;
			}
			else if (x == 2) {
				int l,r ;
				cin >> l >> r ;
				bitset<26> y = query(str, 1 , n , l , r, 1) ;
				cout << y.count() << "\n" ;
			}
		}
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve() ;
    return 0;
}
