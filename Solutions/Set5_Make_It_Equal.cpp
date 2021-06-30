#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main() {
    
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;
    
    int n ; cin >> n ;
    
    ll sum_a = 0, sum_b =0;
    
    int a[n] ; for( int i = 0 ; i < n ; i ++) { cin >> a[i] ; sum_a += a[i] ; } 
    int m ; cin >> m ;
    int b[m] ;
    for( int i = 0 ; i < m ; i ++) { cin >> b[i] ; sum_b += b[i] ; }
    
    if( sum_a != sum_b ){ cout << -1 ; return 0; }
    
    int i = 0, j = 0;
    int ans = 0;
    while( i < n && j < m )
    {
        ans ++ ;
        ll c = a[i++], d = b[j++] ;
        
        while( c != d )
        {
            if( c < d ){ c += a[i++] ; }
            else{ d += b[j++] ; }
        }
    }

    cout << ans ;
    
	return 0;
}