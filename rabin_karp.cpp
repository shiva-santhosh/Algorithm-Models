#include <bits/stdc++.h>
using namespace std;

#define ll long long int 

const ll mod = 1e9+9 ;

const ll p = 31 ;

void rabin_karp(string s , string t) {

	ll len1 = s.length() ;
	ll len2 = t.length() ;

	vector < ll > p_pow(max(len1,len2)+4) ;
	vector< ll > ans  ;

	p_pow[0] = 1 ;

	for(int i = 1 ; i < max(len1,len2) ; i++) {
		p_pow[i] = (p_pow[i-1] * p ) % mod ;
	}

	ll hash[len1+3] ;
	hash[0] = s[0]-'a' + 1 ;
	for( int i = 1 ; i < len1 ; i++) {
		hash[i] = (hash[i-1] + (s[i] - 'a' + 1)*p_pow[i]) % mod ;
	}
	ll hp = 0 ;
	for( int i = 0 ; i < len2 ; i++) {
		hp = (hp + (t[i] - 'a' + 1)*p_pow[i]) % mod ;
	}

	for( ll i = len2 - 1 ; i < len1 ; i++  ){

		if(i == len2 -1) {
			if(hp == hash[i] )
				ans.push_back(1) ;
			continue ;
		}
		if( (hash[i] - hash[i-(len2-1)-1]+ mod)% mod == hp*p_pow[i-(len2-1)] % mod)
			ans.push_back(i-(len2-1) + 1) ;
	}

	if( ! ans.empty() ){
		cout<<ans.size()<<"\n" ;
		for(auto x : ans) cout<<x<<" " ;
	}
	else cout<<"Not Found" ;
	
	cout<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t ; cin >> t ;
    while(t--) {

    	string s , t ;

    	cin >> s >> t ;

    	rabin_karp(s,t) ;

    }
    return 0;
}
