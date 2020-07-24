#include <bits/stdc++.h>
using namespace std;

/******************************************
* AUTHOR : PANDRAVISAM SHIVA SANTHOSH *
* Handle : santhosh_80 *
* INSTITUTION : IIT Palakkad *
******************************************/

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

bool is_palindrome(string &str) {
		for(int i = 0; i < (str.length()/2) ; i++) {
			if(str[i] != str[str.length()-1-i])return false ;
		}
		return true;
}	

int find_prefix_palindrome(string &str) {
		int n = str.length() ;
		string rev = str ;
		reverse(all(rev)) ;
		string automata = str + '#' +  rev ;
		vector<int> prefix(2*n+3,0) ;
		int c = 0  ;

		for(int i = 1; i < automata.length() ; i++) {

			int j = prefix[i-1] ;
			while( j>0 && automata[i] != automata[j]) {
					j = prefix[j-1] ;
			}
			if(automata[i] == automata[j])j++ ;
			prefix[i] = j ;
			c = j ;
		}
		return c ;

}
//Counting the number of occurrences of each prefi/Counting the number of occurrences of each prefi
vector<ll> count_num_of_prefices(){

	vector<int> ans(n + 1);

	// counting number of substrings that are same as prefices
	for (int i = 0; i < n; i++)
	    ans[pi[i]]++;
	
	/*: Given a prefix of length j that is a suffix ending at position i, 
	what is the next smaller prefix <j that is also a suffix ending at position i.
	 Thus at the position i ends the prefix of length π[i], the prefix of 
	length π[π[i]−1], the prefix π[π[π[i]−1]−1], and so on, until the index 
	becomes zero.*/
	for (int i = n-1; i > 0; i--)
	    ans[pi[i-1]] += ans[i];

	// adding original prefices 
	for (int i = 0; i <= n; i++)
	    ans[i]++;

	return ans ;
}	

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t ; cin >> t  ;

	while(t--) {

			string str1 ; cin >> str1 ;
			if(is_palindrome(str1)){
					cout << str1;
					cout << "\n";
					continue ;
			}

			int count = 0 ;
			int n = str1.length() ;

			for(int i = 0 ; i < n/2 ; i++){
				if(str1[i]!=str1[n-1-i])break ;
				count++;
			}

			if( n-2*count > 0 ){

				string sliced = str1.substr(count,n-2*count) ;
				int c = find_prefix_palindrome(sliced) ;

				//cout << sliced << " " << c << "\n";

				reverse(all(sliced)) ;
				int c1 = find_prefix_palindrome(sliced) ;

				//cout << sliced << " " << c1 << "\n";

				if(c >= c1) {
					cout << str1.substr(0,count) ;
					cout << str1.substr(count,c) ;
					cout << str1.substr(n-count,count) ;
				}
				else{
					cout << str1.substr(0,count) ;
					cout << str1.substr(n-count-c1,c1) ;
					cout << str1.substr(n-count,count) ;
				}
				cout << "\n" ;
			}		
	}
 	return 0;
}