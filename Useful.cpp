
#include<bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long int ll;

const ll lg=22;
const ll N=1e5+5;
const ll INF=1e18;
const ll mod=1e9+7;
const double PI = 3.14159265358979323846;

#define is(n) scanf("%d",&n)
#define io(n) printf("%d\n",n)
#define ls(n) scanf("%lld",&n)
#define lo(n) printf("%lld\n",n)

#define f first
#define s second
#define pb(x) push_back(x)
#define pf(x) push_front(x)
#define mp(x,y) make_pair(x,y)
#define GCD(a,b) __gcd((a),(b))
#define all(v) v.begin(),v.end()
#define bits(x) __builtin_popcount(x)
#define LCM(a,b) ((a)*(b))/GCD((a),(b))
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
template<typename T> T power(T x,T y,ll m){T ans=1;while(y>0){if(y&1LL) ans=(ans*x)%m;y>>=1LL;x=(x*x)%m;}return ans%m;}

inline ll mul(ll a, ll b, ll p){ return (a * 1ll * b) % p; }
inline ll sub(ll a, ll b, ll p){ ll c = a - b; if(c < 0) c += p; return c; }
inline ll add(ll a, ll b, ll p){ ll c = a + b; if(c > p) c -= p; return c; }

#define trace1(x)                cerr<<#x<<": "<<x<<endl
#define trace2(x, y)             cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define trace3(x, y, z)          cerr<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
#define trace4(a, b, c, d)       cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl
#define trace5(a, b, c, d, e)    cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<endl
#define trace6(a, b, c, d, e, f) cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<" | "<<#f<<": "<<f<<endl

priority_queue<ll,vector<ll>,greater<ll> > pq;

// FAST I/O -------------------------------

inline int fastscan () {
	bool minus = false;
	int result = 0;
	char ch;
	ch = getchar();
	while (true) {
		if (ch == '-') break;
		if (ch >= '0' && ch <= '9') break;
		ch = getchar();
	}
	if (ch == '-') minus = true; else result = ch-'0';
	while (true) {
		ch = getchar();
		if (ch < '0' || ch > '9') break;
		result = result*10 + (ch - '0');
	}
	if (minus)
		return -result;
	else
		return result;
}

// MOVES IN A GRID ---------------------------------------- //

// normal 4 moves
ll dx[]={0,1,0,-1};
ll dy[]={1,0,-1,0};
// all 8 moves
ll dx[]={-1,-1,-1,0,1,1,1,0};
ll dy[]={-1,0,1,1,1,0,-1,-1};
// knight's moves
ll dx[]={-2,-2,2,2,-1,-1,1,1};
ll dy[]={-1,1,1,-1,-2,2,-2,2};

// Orientation ------------------------------------------------ //

ll direction(point p, point q, point r)
{
  ll val=((q.y-p.y)*(r.x-q.x))-((q.x-p.x)*(r.y-q.y));
  if(val==0){return 0;}  // colinear
  return (val>0)?1:2; // clock or counterclock wise
}

// Submatrix Sum --------------------------------------------------

void Table()
{
  for(ll i=1;i<=n;i++)
  {
    for(ll j=1;j<=m;j++){ans[i][j]=a[i][j]+ans[i-1][j]+ans[i][j-1]-ans[i-1][j-1];}
  }
}

ll Find(ll r1,ll c1,ll r2,ll c2){return (ans[r2][c2]-ans[r1-1][c2]-ans[r2][c1-1]+ans[r1-1][c1-1]==0);}

// nCr ----------------------------------------------------------

ll nCr(ll n,ll r)
{
	if(r==0||r==n){return 1;}
	if(dp[n][r]!=-1){return dp[n][r];}
	return dp[n][r]=nCr(n-1,r-1)+nCr(n-1,r);
}

// MODULAR EXPO ----------------------------------------------- //

ll power(ll x, ll y, ll p)
{
  ll res=1;
  x=x%p;
  while(y>0)
  {
    if(y&1)
    res=(res*x)%p;
    y=y>>1;
    x=(x*x)%p;
  }
  return res;
}

// DSU -------------------------------------------- //

ll root(ll x)
{
  while(x!=a[x]){a[x]=a[a[x]];x=a[x];}
  return x;
}

void unionx(ll x,ll y)
{
  ll rx=root(x);
  ll ry=root(y);
  if(rx==ry){return;}
  else
  {
    if(siz[rx]<siz[ry]){a[rx]=ry;siz[ry]+=siz[rx];siz[rx]=0;}
    else{a[ry]=rx;siz[rx]+=siz[ry];siz[ry]=0;}
  }
}

// SEGMENT TREE -------------------------------------------- //

void build(ll low,ll high,ll pos)
{
  if(low==high)
  {
    seg[pos]=a[low];
    return;
  }
  ll mid=(low+high)/2;
  build(low,mid,2*pos+1);
  build(mid+1,high,2*pos+2);
  seg[pos]=max(seg[2*pos+1],seg[2*pos+2]);
}

void update(ll low,ll high,ll qpos,ll pos)
{
  if(low==high)
  {
    seg[pos]=a[low];
    return;
  }
  else
  {
    ll mid=(low+high)/2;
    if(low<=qpos&&qpos<=mid) update(low,mid,qpos,2*pos+1);
    else update(mid+1,high,qpos,2*pos+2);
    seg[pos]=max(seg[2*pos+1],seg[2*pos+2]);
  }
}

ll query(ll low,ll high,ll qlow,ll qhigh,ll pos)
{
  if(qlow>high||qhigh<low) return 0;
  if(qlow<=low&&qhigh>=high) return seg[pos];
  ll mid=(low+high)/2;
  return max(query(low,mid,qlow,qhigh,2*pos+1),query(mid+1,high,qlow,qhigh,2*pos+2));
}

// LAZY SEGMENT TREE ---------------------------------------------------- //

void update(ll low,ll high,ll qlow,ll qhigh,ll pos,ll val)
{
  if(low>high){return;}
  if(lazy[pos]!=0)
  {
    seg[pos]+=((high-low+1)*lazy[pos]);
    if(low!=high)
    {
      lazy[2*pos+1]+=lazy[pos];
      lazy[2*pos+2]+=lazy[pos];
    }
    lazy[pos]=0;
  }
  if(qlow>high||qhigh<low){return;}
  if(qlow<=low&&qhigh>=high)
  {
    seg[pos]+=((high-low+1)*val);
    if(low!=high)
    {
      lazy[2*pos+1]+=val;
      lazy[2*pos+2]+=val;
    }
    return;
  }
  ll mid=(low+high)/2;
  update(low,mid,qlow,qhigh,2*pos+1,val);
  update(mid+1,high,qlow,qhigh,2*pos+2,val);
  seg[pos]=seg[2*pos+1]+seg[2*pos+2];
}

ll query(ll low,ll high,ll qlow,ll qhigh,ll pos)
{
  if(low>high){return 0;}
  if(lazy[pos]!=0)
  {
    seg[pos]+=((high-low+1)*lazy[pos]);
    if(low!=high)
    {
      lazy[2*pos+1]+=lazy[pos];
      lazy[2*pos+2]+=lazy[pos];
    }
    lazy[pos]=0;
  }
  if(qhigh<low||qlow>high||low>high){return 0;}
  if(qlow<=low&&qhigh>=high){return seg[pos];}
  ll mid=(low+high)/2;
  ll a=query(low,mid,qlow,qhigh,2*pos+1);
  ll b=query(mid+1,high,qlow,qhigh,2*pos+2);
  return a+b;
}

// Extended Euclid Algo --------------------------------------------

ll gcd(ll a,ll b,ll &x,ll & y)
{
  if(a==0)
  {
    x=0;
    y=1;
    return b;
  }
  ll x1,y1;
  ll d=gcd(b%a,a,x1,y1);
  x=y1-(b/a)*x1;
  y=x1;
  return d;
}


// DFS && BFS ---------------------------------------------------- //

void DFS(ll cur,ll par)
{
  vis[cur]=1;
  for(ll i=0;i<g[cur].size();i++)
  {
    if(!vis[g[cur][i]]) DFS(g[cur][i],cur);
  }
}

void BFS(ll cur)
{
  queue<ll> q;
  q.push(cur);
  vis[cur]=1;
  while(q.size())
  {
    cur=q.front();
    q.pop();
    for(ll i=0;i<g[cur].size();i++)
    {
      if(!vis[g[cur][i]])
      {
        vis[g[cur][i]]=1;
        q.push(g[cur][i]);
      }
    }
  }
}

// DIVISORS of N --------------------------------------------------- //

void DIV(ll n)
{
  for(ll i=1;i<=sqrt(n);i++)
  {
    if(n%i==0)
    {
      if(n/i==i){fac.pb(i);}
      else{fac.pb(i);fac.pb(n/i);}
    }
  }
}

// MANIPULATED SIEVE --------------------------------------------------- //

void F(ll N)
{
  vector<ll> prime;
  vector<bool> isprime;
  ll SPF[N];
  for(ll i=0;i<N;i++) isprime[i]=true;
  isprime[0]=isprime[1]=false ;
  for(ll i=2;i<N;i++)
  {
    if(isprime[i])
    {
      prime.push_back(i);
      SPF[i] = i;
    }
    for(ll j=0;j<(ll)prime.size()&&i*prime[j]<N&&prime[j]<=SPF[i];j++)
    {
      isprime[i*prime[j]]=false;
      SPF[i*prime[j]] = prime[j] ;
    }
  }
}

void PrimeFac(ll m)
{
  ll cur=m;
  while(m!=1)
  {
    fac[cur].pb(SPF[m]);
    m/=SPF[m];
  }
}

// DISTINCT PRIME FACTORS -------------------------------------------------------------------- //

void Count(ll nn)
{
	int count=0;
	while(!(nn % 2))
  {
		nn>>=1;
		count++;
	}
	if(count){v.pb(mp(2,count));}
	for(ll i=3;i<=sqrt(nn);i+=2)
  {
		count=0;
		while(nn%i==0)
    {
			count++;
			nn=nn/i;
		}
		if(count){v.pb(mp(i,count));}
	}
	if(nn>2){v.pb(mp(nn,1));}
}

// HEAP SORT -------------------------------------------------------------- //

void max_heapify(ll a[],ll i,ll n)
{
  ll cur=i;
  ll left=2*i;
  ll right=2*i+1;
  if(left<=n&&a[cur]<a[left]) cur=left;
  if(right<=n&&a[cur]<a[right]) cur=right;
  if(cur!=i) swap(a[i],a[cur]),max_heapify(a,cur,n);
}

void heap_sort(ll a[],ll n)
{
  swap(a[1],a[n]);
  max_heapify(a,1,n-1);
}

// DIJAKSTRAS SHORTEST PATH --------------------------------------------------------------- //

Dijkstra with Path:

int arrival[N], departure[N], vis[N], parent[N];
vector<pair<int, int> > g[N];

void DIJKSTRAS(ll source, ll destination)
{
	for(ll i=1;i<=n;i++)
	{
		arrival[i]=1e18;
		departure[i]=1e18;
		vis[i]=0;
	}
	arrival[source]=0;
	set<pair<ll, ll> > s;
	s.insert({0, source});
	while(!s.empty())
	{
		auto x = *(s.begin());
		s.erase(x);
		vis[x.second]=1;
		departure[x.second]=arrival[x.second];
		for(auto it:g[x.second])
		{
			if(arrival[it.first] > departure[x.second] + it.second)
			{
				s.erase({arrival[it.first], it.first});
				arrival[it.first]=departure[x.second] + it.second;
				s.insert({arrival[it.first], it.first});
				parent[it.first]=x.second;
			}
		}
	}
	if(!vis[destination])
	{
		cout<<"-1";
		return;
	}
	ll v=destination;
	vector<ll> ans;
	while(parent[v])
	{
		ans.push_back(v);
		v=parent[v];
	}
	ans.push_back(source);
	reverse(ans.begin(), ans.end());
	for(auto it:ans)
		cout<<it<<" ";
}

// -------------------------------------------------------------------------------------------------------------------------------------
Simple Dijkstra:

ll arrival[N][N], departure[N][N];
vector<pair<ll, ll> > g[N];

void DIJKSTRAS(ll source, ll destination, ll arrival[], ll departure[])
{
	for(ll i=1;i<=n;i++)
	{
		arrival[i]=inf;
		departure[i]=inf;
	}
	arrival[source]=0;
	set<pair<ll, ll> > s;
	s.insert({0, source});
	while(!s.empty())
	{
		auto x = *(s.begin());
		s.erase(x);
		departure[x.second]=arrival[x.second];
		for(auto it:g[x.second])
		{
			if(arrival[it.first] > departure[x.second] + it.second)
			{
				s.erase({arrival[it.first], it.first});
				arrival[it.first]=departure[x.second] + it.second;
				s.insert({arrival[it.first], it.first});
			}
		}
	}
}


// PRIORITY QUEUE --------------------------------------------------------------//

priority_queue<pair<ll,ll>,vector<pair<ll,ll> >,greater<pair<ll,ll> > > pq;

struct node
{
  ll cnt,idx;
  bool operator< (const node & p)const
  {
    if(cnt==p.cnt) return idx>p.idx;
    return cnt>p.cnt;
  }
};

// Convex Hull -----------------------------------------------------------------------------//

ll find(point l,point r){return ((l.x-r.x)*(l.x-r.x))+((l.y-r.y)*(l.y-r.y));}

point prev()
{
  point topx=s.top();
  s.pop();
  point ret=s.top();
  s.push(topx);
  return ret;
}

ll direction(point p, point q, point r)
{
  ll val=((q.y-p.y)*(r.x-q.x))-((q.x-p.x)*(r.y-q.y));
  if(val==0){return 0;}
  return (val>0)?1:2;
}

bool comp(point l,point r)
{
  ll dir=direction(ful[0],l,r);
  if(dir==0)
  {
    ll distx=find(ful[0],l);
    ll disty=find(ful[0],r);
    return distx<=disty;
  }
  else{return dir==2?1:0;}
}

void CONVEX_HULL()
{
	n=ful.size();
  ll mini=INF,pos=0;
  for(ll i=0;i<n;i++)
  {
    if(mini>ful[i].y){mini=ful[i].y;pos=i;}
    else if(mini==ful[i].y&&ful[i].x<ful[pos].x){pos=i;}
  }
  swap(ful[0],ful[pos]);
  sort(ful.begin()+1,ful.end(),comp);
  ll cur=1;
  for(ll i=1;i<n;i++)
  {
    while(i<n-1&&direction(ful[0],ful[i],ful[i+1])==0){i++;}
    ful[cur++]=ful[i];
  }
  n=cur;
  if(n<3){cout<<"NO"<<endl;exit(0);}
  s.push(ful[0]);
  s.push(ful[1]);
  s.push(ful[2]);
  for(ll i=3;i<n;i++)
  {
    point pp=prev();
    while(direction(prev(),s.top(),ful[i])!=2)
    {
      s.pop();
      if(s.size()==1){break;}
      pp=prev();
    }
    s.push(ful[i]);
  }
}

//  Digit-DP--------------------------------------------------------------------------------------

ll cur;
vector<ll> dig[2];

void len(ll n)
{
  //for(ll i=0;i<n.length();i++){dig[cur].pb(n[i]-'0');}
  while(n){dig[cur].pb(n%10);n/=10;}
  reverse(all(dig[cur]));
}

ll F(ll idx,ll f,ll par,ll esum,ll osum,ll num)
{
  ll ans=0;
  if(idx==dig[cur].size()){return esum-osum==1;}
  if(dp[idx][f][par][esum][osum]!=-1){return dp[idx][f][par][esum][osum];}
  if(f)
  {
    for(ll i=0;i<dig[cur][idx];i++)
    {
      if(par){ans+=F(idx+1,0,0,esum,osum+i,num*10+i);}
      else{ans+=F(idx+1,0,1,esum+i,osum,num*10+i);}
    }
    if(par){ans+=F(idx+1,1,0,esum,osum+dig[cur][idx],num*10+dig[cur][idx]);}
    else{ans+=F(idx+1,1,1,esum+dig[cur][idx],osum,num*10+dig[cur][idx]);}
  }
  else
  {
    for(ll i=0;i<=9;i++)
    {
      if(par){ans+=F(idx+1,0,0,esum,osum+i,num*10+i);}
      else{ans+=F(idx+1,0,1,esum+i,osum,num*10+i);}
    }
  }
  return dp[idx][f][par][esum][osum]=ans;
}


int main()
{
  //fast;
  ll t=1;
  cin>>t;
  while(t--)
  {
    ll a,b;
    cin>>a>>b;
    cur=0;
    len(b);
    ll par=0;
    if(dig[cur].size()%2){par=1;}
    memset(dp,-1,sizeof(dp));
    ll x=F(0,1,par,0,0,0);
    cur=1;
    if(a==0){cout<<x<<endl;continue;}
    len(a-1);
    if(dig[cur].size()%2){par=1;}
    else{par=0;}
    memset(dp,-1,sizeof(dp));
    ll y=F(0,1,par,0,0,0);
    cout<<x-y<<endl;
    //cout<<x<<" "<<y<<endl;
    dig[0].clear();
    dig[1].clear();
  }
}

// LCA ----------------------------------------------------------------------

void PreComputation()
{
  for(ll i=1;i<logx;i++)
  {
    for(ll j=1;j<=n;j++)
    {
      if(p[j][i-1]==0){continue;}
      p[j][i]=p[p[j][i-1]][i-1];
    }
  }
}

ll LCA(ll u,ll v)
{
  if(lev[u]>lev[v]){swap(u,v);}
  for(ll i=logx-1;i>=0;i--)
  {
    if(lev[p[v][i]]>=lev[u]){v=p[v][i];}
  }
  if(u==v){return u;}
  for(ll i=logx-1;i>=0;i--)
  {
    if(p[u][i]!=0&&p[u][i]!=p[v][i]){u=p[u][i];v=p[v][i];}
  }
  return p[u][0];
}

// String Hashing -----------------------------------------------------------------------------------------------

string s;
ll q,l,r,n,p=101;
ll powx[N],pre[N],suf[N],rmod[N],dp[N][N];

ll findINV(ll f){return power(f,mod-2,mod)%mod;}

void calcPOW()
{
  powx[0]=1;
  for(ll i=1;i<=n;i++){powx[i]=((powx[i-1])*(p))%mod;}
}

void preHASH()
{
  pre[0]=0;
  pre[1]=s[0];
  for(ll i=2;i<=n;i++)
  {
    ll cur=((s[i-1])*(powx[i-1]))%mod;
    pre[i]=((pre[i-1])+(cur))%mod;
  }
}

void sufHASH()
{
  reverse(all(s));
  suf[0]=0;
  suf[1]=s[0];
  for(ll i=2;i<=n;i++)
  {
    ll cur=((s[i-1])*(powx[i-1]))%mod;
    suf[i]=((suf[i-1])+(cur))%mod;
  }
}

void All()
{
  calcPOW();
  for(ll i=0;i<=n;i++){rmod[i]=findINV(powx[i]);}
  preHASH();
  sufHASH();
}

void findSUB()
{
  for(ll i=0;i<=n;i++){rmod[i]=findINV(powx[i])%mod;}
  for(ll i=1;i<=n;i++)
  {
    for(ll j=i;j<=n;j++)
    {
      ll preval=((pre[j])-(pre[i-1])+mod)%mod;
      if(preval<0){preval+=mod;}
      ll sufval=((suf[n-i+1])-(suf[n-j]+mod))%mod;
      if(sufval<0){sufval+=mod;}
      preval=((preval)*(rmod[i-1]))%mod;
      sufval=((sufval)*(rmod[n-j]))%mod;
      if(preval==sufval){dp[i][j]++;}
    }
  }
  for(ll i=1;i<=n;i++)
  {
    for(ll j=1;j<=n;j++){dp[i][j]+=dp[i][j-1];}
  }
  for(ll i=1;i<=n;i++)
  {
    for(ll j=1;j<=n;j++){dp[j][i]+=dp[j-1][i];}
  }
}

int main()
{
  //fast;
  cin>>s;
  //scanf("%s",s);
  scanf("%lld",&q);
  //cout<<"hi"<<endl;
  n=s.length();
  calcPOW();
  preHASH();
  sufHASH();
  findSUB();
  while(q--)
  {
    //cin>>l>>r;
    scanf("%lld",&l);
    scanf("%lld",&r);
    ll val=dp[r][r]-dp[l-1][r]-dp[r][l-1]+dp[l-1][l-1];
    printf("%lld\n",val);
  }
}

//Strongly Connected Components ------------------------------------------------------------------------------------------------------------------------

void SCC()
{
  ll cnt=0;
  for(ll i=1;i<=2*n;i++)
  {
    if(vis[i]){continue;}
    DFS(i);
  }
  ms(vis,0);
  //printTOPO();
  while(topo.size())
  {
    if(vis[topo.top()]){topo.pop();continue;}
    xDFS(topo.top(),cnt++);
    topo.pop();
    sort(all(comp[cnt-1]));
  }
  //printCOMP(cnt);
  for(ll i=1;i<=n;i++)
  {
    for(ll j=0;j<cnt;j++)
    {
      ll lb=binary_search(all(comp[j]),i);
      ll ub=binary_search(all(comp[j]),i+n);
      if(lb&&ub){f=0;return;}
    }
  }
}

// KMP ------------------------------------------------------------------------------------------------------------

void Build()
{
  ll i=1,j=0;
  while(i<m)
  {
    if(stn[i]==stn[j]){temp[i]=j+1;i++;j++;}
    else
    {
      j=max(0LL,j-1);
      j=temp[j];
      if(j==0)
      {
        if(stn[i]==stn[j]){temp[i]=j+1;i++;j++;}
        else{temp[i]=0;i++;}
      }
      else
      {
        ll ff=0;
        while(j>0)
        {
          if(stn[j]==stn[i]){temp[i]=j+1;ff=2;i++;j++;break;}
          else
          {
            j=max(0LL,j-1);
            j=temp[j];
          }
        }
        if(!ff)
        {
          if(stn[i]==stn[j]){temp[i]=j+1;i++;j++;}
          else{temp[i]=0;i++;}
        }
      }
    }
  }
}

void KMP()
{
  Build();
  ll cnt=0,j=0;
  for(ll i=0;i<n;i++)
  {
    if(check[i]==stn[j]){j++;}
    else
    {
      j=max(0LL,j-1);
      j=temp[j];
      if(j==0)
      {
        if(stn[j]==check[i]){j++;}
      }
      else
      {
        while(j>0)
        {
          if(check[i]==stn[j]){j++;break;}
          else
          {
            j=max(0LL,j-1);
            j=temp[j];
          }
        }
        if(j==0)
        {
          if(stn[j]==check[i]){j++;}
        }
      }
    }
    if(j==m){cnt++;j=temp[j-1];}
  }
  cout<<cnt<<endl;
}

// Z-Algorithm-----------------------------------------------------------------------------------------------------

// A C++ program that implements Z algorithm for pattern searching
#include<iostream>
using namespace std;

void getZarr(string str, int Z[]);

// prints all occurrences of pattern in text using Z algo
void search(string text, string pattern)
{
	// Create concatenated string "P$T"
	string concat = pattern + "$" + text;
	int l = concat.length();

	// Construct Z array
	int Z[l];
	getZarr(concat, Z);

	// now looping through Z array for matching condition
	for (int i = 0; i < l; ++i)
	{
		// if Z[i] (matched region) is equal to pattern
		// length we got the pattern
		if (Z[i] == pattern.length())
			cout << "Pattern found at index "
				<< i - pattern.length() -1 << endl;
	}
}

// Fills Z array for given string str[]
void ZAlgo(string str)
{
  ll L=0,R=0,k,n=str.length();
  for(ll i=1;i<m;++i)
  {
    if(i>R)
    {
      L=R=i;
      while(R<n&&str[R-L]==str[R]){R++;}
      Z[i]=R-L;
      R--;
    }
    else
    {
      k=i-L;
      if(Z[k]<R-i+1){Z[i]=Z[k];}
      else
      {
        L=i;
        while(R<m&&str[R-L]==str[R]){R++;}
        Z[i]=R-L;
        R--;
      }
    }
  }
}


// ----------------------------------------------------------------------------------------------------------------

void Q(){test++;cout<<"Case #"<<test<<": ";}

void RR()
{
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
}
