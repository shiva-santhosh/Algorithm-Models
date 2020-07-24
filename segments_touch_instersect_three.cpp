#include<bits/stdc++.h>
using namespace std;
bool intersect(pair<int,int>p1,pair<int,int>p2,pair<int,int>p3){
    if(max(p1.first,p2.first)>min(p1.second,p2.second))return false;
    if(max(p1.first,p3.first)>min(p1.second,p3.second))return false;
    if(max(p3.first,p2.first)>min(p3.second,p2.second))return false;
    return true;
}
bool solve(vector<pair<int,int>>&a){
    sort(a.begin(),a.end());
    int n=a.size();
    for(int i=0;i<(n-2);i++){
        for(int j=i+1;j<(n-1);j++){
            if(intersect(a[i],a[j],a[j+1]))return false;
            if(max(a[i].first,a[j].first)>min(a[i].second,a[j].second)){
                break;
            }
        }
    }
    return true;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int count=0;
        vector<pair<int,int> >a[1001];
        unordered_map<int,int>m;
           
        while(n--){
           
            int l,r,v;
            cin>>l>>r>>v;
            if(m.find(v)!=m.end()){
                a[m[v]].push_back(make_pair(l,r));
            }
            else{
                m[v]=count;
                count++;
                a[m[v]].push_back(make_pair(l,r));
            }

        }
        int flag=0;
        for(int i=0;i<count;i++){
            //cout<<a[i].size()<<endl;
            if(!solve(a[i])){
                cout<<"NO"<<endl;
                flag=1;
                break;
            }
        }
        if(flag==0){
            cout<<"YES"<<endl;
        }
    }

    return 0;

}