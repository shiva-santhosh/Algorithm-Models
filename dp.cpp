#include <bits/stdc++.h>
using namespace std;


const int N=200009;
long long int dp[N];
long long int sum=0;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
   long long int a[n+7];
    for(int i=1 ; i<=n ; i++){
    	cin >> a[i] ;
    	s///um=a[i];

    }
    dp[1]=a[1];
    dp[2]=a[2];
    dp[3]=max(dp[2],max(a[1]+a[3],a[2]+a[3]));
    for(int i=4;i<=n;i++){

    		dp[i]=max(dp[i-1],max(dp[i-2]+a[i],dp[i-3]+a[i-1]+a[i]));


    }
    cout<<dp[n];
    return 0;
}

