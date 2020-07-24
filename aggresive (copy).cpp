#include <bits/stdc++.h>
using namespace std;


bool isRight(long long int k,long long int *a,long long int c,long long int n){
	long long int count=1;
	long long int z=a[0];
	for(int i=1; i<n ; i++){
		if(z+k <= a[i]){
			count++;
			z=a[i];
		}

	}
	if(count>=c)return true;
	else return false;

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int t; cin >> t;
    while(t--)  {
    	long long int n,c,ans;
    	cin >>n >> c;
    	long long int a[n+5];
    	for(int i=0;i<n;i++)cin>>a[i];
    		sort(a,a+n);
    	long long int low=0,mid;
    	long long int high=a[n-1]-a[0];
    	while(low<=high){
    		mid=(low+high)/2;
    		if(isRight(mid,a,c,n))
    			{low=mid+1;ans=mid;}
    		else
    			high=mid-1;

    	}
    	cout<<ans<<endl;

    }
    return 0;
}
