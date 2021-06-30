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
int BobandTower(vector<int>& nums) {
        stack<long long> s; 
        
        long long n = nums.size() ;
        
        vector<long> right(n), left(n);
        
        s.push(0) ;
        
        for( long long i = 1 ; i < n ; i ++ )
        {
            while( !s.empty() && nums[s.top()] > nums[i] )
            {
                right[s.top()] = i ;
                s.pop() ;
            }
            
            s.push(i) ;
        }
        
        while( !s.empty() ){ right[s.top()] = n ; s.pop() ; }
        
        s.push(n-1) ;
        
        for( long long i = n-2 ; i >= 0 ; i -- )
        {
            while( !s.empty() && nums[s.top()] > nums[i] )
            {
                left[s.top()] = i ;
                s.pop() ;
            }
            s.push(i) ;
        }
        
        while( !s.empty() ){ left[s.top()] = -1 ; s.pop() ; }
        
        vector<long long> pre(n) ;
        
        pre[0] = nums[0] ;
        
        for( int i = 1 ; i < n ; i ++ ){  pre[i] = pre[i-1] + nums[i] ; }
        
        long long ma = -1 ;
        
        for( int i = 0 ; i < n ; i ++ )
        {
            long long p = nums[i] ;
            
            long long r , s ;
            
            r = right[i] ; s = left[i] ;
            
            r = pre[r-1] ;
            
            if( s == -1 ){ s = 0 ; } else{ s = pre[s] ; }
            
            
            long long temp = ( r - s )*p ;
            
            ma = max(ma, temp) ;
        }
        
        return ma%1000000007 ;
    }
int main() {
    
    ios_base::sync_with_stdio(false) ; cin.tie(NULL) ; cout.tie(NULL) ;
    
    int n ; cin >> n ; 

    vi <int> a(n) ; for( int i = 0 ; i < n ; i ++ ){ cin >> a[i] ; } 

    cout << BobandTower(a) ;
    return 0;
}