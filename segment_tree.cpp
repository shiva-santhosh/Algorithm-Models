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
	int mid=(l+h)/2;
	if(l<= u && u <=mid )update(a,l,mid,u,2*pos);
	else update(a,mid+1,h,u,2*pos+1);
	seg[pos]=seg[2*pos]+seg[2*pos+1];
}




int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,q,x,y;cin>> n >> q;
    int a[n+9];
    for(int i=1;i<=n;i++)a[i]=1;
    construct(a,1,n,1);
//	for(int i=1;i<=4*n;i++)cout<<seg[i];
    while(q--){
    	cin >> x >> y;
    	if(x==0){
    		a[y]=0;
    		update(a,1,n,y,1);
    		//for(int i=1;i<=4*n;i++)cout<<seg[i];
    	}
    	else{
    		ll low=1;
    		ll high =n;
    		int ans=-1;
    		//for(int i=1;i<=n;i++)cout<<a[i];
    		while(low<=high){
    			ll mid=(low+high)/2;
    			ll k=query(a,1,n,1,mid,1);
    			//cout<<mid<<endl;
    			//cout<<k<<endl;
    			if(a[mid]==1 && y==k){
    				ans=mid;
    				break;
    			}
    			if(k>=y)high=mid-1;
    			if(k<y) low=mid+1;
    		}
    		cout<<ans<<"\n";
    	}
    }
    return 0;
}
