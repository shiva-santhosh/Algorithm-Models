#include <bits/stdc++.h>
using namespace std;

#define ll long long int 
bitset<100009> b;
ll a[10005];
ll prefix[100008];
ll n;
void compute(){
			b[0]=1;
			for(int i=1;i<=n;i++){
				b=b| b<<a[i];
			}
			for(int i=1;i<=100008;i++){
				prefix[i]=b[i]+prefix[i-1];
			}
}




int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n; ll q ; cin >> q;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
    }
    compute();
    int l,r;
    while(q--){
    	cin >> l >> r;
    	cout<<prefix[r]-prefix[l-1];
    	cout<<"\n";
    }
    return 0;
}
