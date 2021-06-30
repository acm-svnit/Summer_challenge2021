#include <iostream>
using namespace std;

long long a[100005] ;
int main() {
    
    int n, p ;
    
    cin >> n >> p;
    
    long long minimum = 1e18 ;
    
    for( int i = 1; i <= n ; i ++ )
    {
        cin >> a[i] ;
        minimum = min(minimum,a[i]) ;
    }
    
    for(int i = 1 ; i <= n ; i ++)
    {
        a[i] -= minimum ;
    }
    
    int count = 0 ;
    int i ;
    for( i = p ; a[i] != 0 ; i -- )
    {
        a[i] -- ;
        
        count ++; 
        
        if(i == 1){ i = n+1 ; }
    }
    a[i] = (minimum*n) + count ;
    
    for( int i =1 ; i <= n ; i ++ )
    {
        cout << a[i] <<" " ;
    }
    
    return 0;
}