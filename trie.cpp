#include <bits/stdc++.h>
using namespace std ;


typedef struct trie {
    bool present;
    trie* next[26];
}trie;

int count1 = 1;

void insert(trie* root,string s)
{
    int n=s.size();
    for(int i=0;i<n;i++)
    {
        if(root->next[s[i]-'a']==NULL)
        {
            root->next[s[i]-'a']=new trie; 
            count1++;
            root->next[s[i]-'a']->present=false;
            for(int j=0;j<26;j++)
            {
                root->next[s[i]-'a']->next[j]=NULL;
            }
        }
        root=root->next[s[i]-'a'];
    }
    root->present=true;
}


bool ispresent(trie * root,string s)
{
   
    int n = s.size();
    for(int i=0;i<n;i++)
    {
        root=root->next[s[i]-'a'];
        if(root==NULL)return false;
        // root=root->next[s[i+1]]
    }
    if(root->present==true)
    return true;
    return false;
}

int main () {
        
        int n ; cin >> n ; string str ;
        trie * root = new trie ;
        root->present = false ;
        for (int i = 0 ; i<26 ; i++ ) {
            root->next[i] = NULL ;
        }
        for( int i = 0 ; i < n ; i++ ){
            cin >> str ;
            insert(root , str ) ;
        }
        cout << count1 ;
        return 0 ;
}
