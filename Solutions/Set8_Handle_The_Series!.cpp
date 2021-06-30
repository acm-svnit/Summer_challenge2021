#include<bits/stdc++.h>
#define ll long long int
#define pb push_back
#define pf push_front
#define vi vector 
#define ff first
#define ss second
#define MX 1000000007
const int p = 1e7 ;
const ll inf = 1e9 ;
const ll mod = 1e9 + 7 ;
#define fastio ios_base::sync_with_stdio(false) ; cin.tie(NULL) ; cout.tie(NULL) ;
using namespace std;
 
void multiply( vi<vi<ll>> &A , vi<vi<ll>> &B, ll k )
{
    vi <vi<ll>> res(k, vi<ll>(k,0)) ;
    
    for( int i = 0 ; i < k ; i ++ )
    {
        for( int j = 0 ; j < k ; j ++ )
        {
            res[i][j] = 0 ;
            
            for( int z = 0 ; z < k ;  z ++ )
            {
                res[i][j] = ( res[i][j] + (A[i][z] * B[z][j]) )%inf ;
            }
        }
    }
    for( int i = 0 ; i < k ; i ++ )
    {
        for( int j = 0 ; j < k ; j ++ ){ A[i][j] = res[i][j] ; }
    }
}
 
void solve(vi<ll> &c, vi <ll> &f, ll k, ll n)
{
    // Tmatrix
    
    vi <vi<ll>> I(k, vi<ll>(k,0)) ;
    
    for( int i = 0 ; i < k ; i ++ )
    {
        for( int j = 0 ; j < k ; j ++ )
        {
            if( i == j ){ I[i][j] = 1; }
        }
    }
    
    vi <vi<ll>> mat(k, vi<ll>(k,0)) ;
    
    for( int i = 0; i < k ; i ++  ){ mat[k-1][i] = c[k-i-1] ; }
    
    for( int i = 1 ; i < k ; i ++ )
    {
        mat[i-1][i] = 1 ;
    }
    
   while( n )
    {
        if( n%2 )
        {
            multiply(I,mat,k) ; n-- ;
        }
        else{
            multiply(mat,mat,k) ; n /= 2 ;
        }
        
    }
    vi <ll> ans(k,0) ;
    for( int i = 0 ; i < k ; i ++ )
    {
        for( int j = 0 ; j < k ; j ++ )
        {
            ans[i] += (I[i][j] * f[j] )%inf ;
        }
    }
    cout << ans[0]%inf ;
}
 
int main() {
    
    fastio
    
    int t; cin >> t ;
    
    while( t-- )
    {
        ll C, n ; cin >> C ; 
        
        vi<ll> f(C) ;
    
    for( int i = 0 ; i < C ; i ++ ){ cin >> f[i] ; f[i] %= inf ; }
    
    vi <ll> c(C) ;
    
    for( int i = 0 ; i < C ; i ++ ){ cin >> c[i] ; }
    
    
    
    cin >> n ; n -- ;
    if( n < C ){ cout << f[n] <<"\n" ; continue ; }
    solve(c,f,C,n) ;
    cout <<"\n" ;
    }
    return 0;
}