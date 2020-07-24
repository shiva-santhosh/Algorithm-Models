#include <bits/stdc++.h>
using namespace std;
/******************************************
* AUTHOR : PANDRAVISAM SHIVA SANTHOSH *
* Handle : santhosh_80 *
* INSTITUTION : IIT Palakkad *
******************************************/
#define ll long long int 
#define rep(i,a,b) for(int i=a;i<b;i++)
#define pii pair<int,int>
#define all(v) (v).begin(),(v).end()
#define pb push_back
#define f first
#define s second

const ll mod = 1000000007;
const ll N = 1e6;

/*** using this way to maintain ordering in the set ****/

struct cmp{
	bool operator()(const pair<int,int> &a,const pair<int,int> &b)const{
		int lena = a.second - a.first + 1;
		int lenb = b.second - b.first + 1;
		if (lena == lenb) return a.first < b.first;
		return lena > lenb;
	}
};


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;cin>>t;
	while(t--){
		int n;cin >> n;
		vector<int> a(n+1,0);
		set<pair<int,int>,cmp>  s1;
		s1.insert({1,n});
		int i = 1;
		while(!s1.empty()){
			auto it = s1.begin();
			pair<int,int> p = *it;
			int len = (p.s-p.f+1);
			s1.erase(it);
			if(p.f > p.s || len <= 0)continue;
			int mid = (p.f+p.s)/2;
			a[mid]=i;
			if(mid-1 >= p.f)
			s1.insert({p.f,mid-1});
			if(mid+1 <= p.s)
			s1.insert({mid+1,p.s});
			i++;
		}	
		rep(i,1,n+1)cout << a[i] << " ";
		cout << "\n";
	}
 	return 0;
}



/******* Using Define poerator<() ************/

/// Some other ways of ordering it is very important to learn them
// for example if we want edge weights to be in decreasing order, then we can create a struct
struct Edge
{
    int from, to, weight;
    friend bool operator<(Edge a, Edge b)
    {
        return a.weight > b.weight;
    }
};

// Now we can use like this and all stl containers which have ordering will follow this 

vector<Edge> v;
sort(v.begin(), v.end());
priority_queue<Edge> pq;// priority will be maintained based on the ordering
set<Edge> s; // set ordering will be based on the mentioned above ordering



/***** Using custom function ****/

bool cmp(int a, int b)
{
    return occurrences[a] < occurrences[b];
}

sort(data.begin(), data.end(), cmp);

// Used several times this 





