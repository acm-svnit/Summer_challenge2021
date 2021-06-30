#include<bits/stdc++.h>
#define ll long long int
#define pb push_back
#define pf push_front
#define vi vector 
#define ff first
#define ss second
#define MX 1000000007
const int p = 1e6 + 2 ;
const int inf = 1e9 ;
const ll mod = 1000000007 ;
using namespace std  ;
 
int main() {
    
    ios_base::sync_with_stdio(false) ; cin.tie(NULL) ; cout.tie(NULL) ;
    
    string s ; cin >> s ;
    
    int n = s.length() ;
    
    vi <int> a(26,0) ; 
    
    for( int i = 0 ; i < n ; i ++ )
    {
        a[s[i]-'a'] ++ ;
    }
    
    string ans = "" , mid = "" ;
    
    string temp = "" ;
    
    for( int i = 0 ; i < 26 ; i ++)
    {
        if( a[i]&1 ){ temp += (char)(i+'a') ; } 
    }
    
    int i = 0 , j = temp.length() - 1 ;
    
    while( i < j )
    {
        a[temp[i]-'a'] ++ ;
        
        a[temp[j]-'a'] -- ;
        
        i ++ ; j -- ;
    }
    
    for( int i = 0 ; i < 26 ; i ++ )
    {
        while( a[i] >= 2 )
        {
            ans += (char)(i+'a') ;
            
            a[i] -= 2 ;
        }
        
        if( a[i]&1 )
        {
            mid += (char)('a'+i) ;
        }
    }
    
    string final = "" ;
    
    final += ans ;
    
    final += mid ;
    
    reverse(ans.begin(),ans.end()) ;
    
    final += ans ;
    
    cout << final ;
    
    return 0;
}