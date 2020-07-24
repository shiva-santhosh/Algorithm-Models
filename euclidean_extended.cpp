#include <bits/stdc++.h>
using namespace std;


int gcd(int a , int b , int & x ,int & y) {

	if(a == 0){
		x = 0;
		y = 1;
		return b ;
	}
	int x1 , x2 ;
	int g = gcd( b%a , a , x1 , x2) ;
	x = x2 - (b/a) * x1 ;
	y = x1;
	return g ;
}



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while(1) {

    	int n , m , k ,a ;
    	cin >> n >> m >> a >> k ;
    	if(n == 0 && m == 0 && k == 0 && a == 0)
    		break;
    	int x0;
    	int y0;
    	int &x1 = x0 ;
    	int &y1 = y0 ;
    	int g = gcd( m , a , x1 , y1 ) ;

    	cout << x0 << " " << y0 << "\n" ;
    	if( (k - n) % g) {
    		cout << "Impossible\n" ;
    		continue ;
    	}
    	int ans1 =((k-n)/g)*x0;

    	cout << n + m*ans1 << "\n";

    }
    return 0;
}
