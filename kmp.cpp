#include<bits/stdc++.h>
using namespace std;

int lps[100009];

void preprocess(string p,int N){
    
        int i=1,len=0;
        lps[0]=0;
        while(i<N){
            
            if(p[len]==p[i]){
                len++;
                lps[i]=len;
                i++;
            }
            else{
                
                if(len!=0)
                len=lps[len-1];
                else{
                    lps[i]=0;
                    i++;
                }
            }
        }
}

int kmp(string p,string t){
    
    int l1=p.length();
    int l2=t.length();;
    int count=0;
    int j=0,i=0;
    while(i<l2){
        
        if(p[j]==t[i]){
            i++;
            j++;
        }
        if(j==l1){
            count++;
            j=lps[j-1];
        }
        else if(p[j]!=t[i] && i<l2){
            
            if(j>0){
                j=lps[j-1];
            }
            else i++;
        }
        
    }
    
        return count;
    
}


int main (){
            
            string p ,t ;
            cin >> p ;
            cin >> t;
            int l1=p.length();
            int l2=t.length();;
            preprocess(p,l1);
            cout<<kmp(p,t);
    
            return 0;
}
