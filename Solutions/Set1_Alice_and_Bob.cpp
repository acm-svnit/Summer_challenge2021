#include <bits/stdc++.h>
using namespace std;

bool check(int A, int B, int C, int D)
{
    if( A%2 + B%2 + C%2 + D%2 > 1 )
    {
        return false ; 
    }
    return true ;
}

int main() {
    
    int t ;
    
    cin >> t ;
    
    int A,B,C,D ;
    
    while( t-- )
    {
            cin >> A >> B >> C >> D ;
            
            if( check(A,B,C,D) )
            {
                cout <<"Bob" ;
            }
            else if(A > 0 and B > 0 and C > 0 and check( A-1,B-1,C-1,D+1))
            {
                cout <<"Bob" ;
            }
            else{
                cout <<"Alice" ;
            }
            cout <<endl ;
    }
    
    return 0;
}