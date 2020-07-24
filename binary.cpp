#include <bits/stdc++.h>
using namespace std;

void binary_search(){
    ll low=min_value;
    ll high=max_value;
    while(low<=high){

        mid=(min_value+max_value)/2;

        if(mid.isok){
            low=mid+1;
            ans=mid;

        }
        else
            high=mid-1;

    }

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
