#include <bits/stdc++.h>
using namespace std;

#define ll long long int 

int p[500007];
int siz[500007]={0};


// This way of path compressing is more elegant 
// since the nodes in the path will get directly
// linked to representative element
int find_set(int v) {
    if (v == p[v])
        return v;
    return p[v] = find_set(p[v]);
}


// This way will compress path quite good
int find_root(int i){

		while(p[i]!=i){
			p[i]=p[p[i]];
			i=p[i];
		}
		return i;
}
void union1(int x,int y){

	int rx=find_root(x);
	int ry=find_root(y);
	if(rx==ry) return;
	if(siz[rx]<siz[ry]){
		p[rx]=ry;
		siz[ry]+=siz[rx];
		siz[rx]=0;
	}
	else {
		p[ry]=rx;
		siz[rx]+=siz[ry];
		siz[ry]=0;
	}
}



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    return 0;
}
