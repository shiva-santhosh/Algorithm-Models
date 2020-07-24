#include <bits/stdc++.h>
using namespace std;

#define ll long long int

const int N=4e6+9;

ll seg[N];

void construct(int a[],int l ,int h ,int pos){

	if(l==h){seg[pos]=a[l];return;}
	int mid=(l+h)/2;
	construct(a,l,mid,2*pos);
	construct(a,mid+1,h,2*pos+1);
	seg[pos]=seg[2*pos]+seg[2*pos+1];

}
int query(int a[],int l ,int h ,int ql ,int qh ,int pos ){
	if( ql <=l && qh >= h)return seg[pos];
	if(qh<l || ql> h) return 0;
	int mid=(l+h)/2;
	return query(a,l,mid,ql,qh,2*pos)+query(a,mid+1,h,ql,qh,2*pos+1);

}
void update(int a[],int l ,int h ,int u ,int pos){
	if(l==h){seg[pos]=a[l];return;}
	//cout<<"a";
	int mid=(l+h)/2;
	if(l<= u && u <=mid )update(a,l,mid,u,2*pos);
	else update(a,mid+1,h,u,2*pos+1);
	seg[pos]=min(seg[2*pos],seg[2*pos+1]);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n ; cin >> n ;
    int a[n+5];
    for(int i=1; i<= n ;i++){
    	cin>> a[i];
    }
     construct(a,1,n,1);
    ll k ; cin >> k;
    for(int i=1;i<=n-k+1;i++){
    		cout<<query(a,1,n,i,i+k-1,1)<<" ";
    }
    return 0;
}
