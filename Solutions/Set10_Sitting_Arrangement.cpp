#include<bits/stdc++.h>
#define ll long long int

using namespace std  ;
bool flag ;
bool dfs( vector<vector<int>> &edge, vector<int> &C, vector<bool> &vis, int n, int c, int x, int p)
{
    if( flag ){ return false ; }

    C[x] = c ;

    vis[x] = true ;

    for( auto y: edge[x] )
    {
        if( y == p ){ continue ; }
        if( vis[y] == false )
        {
            dfs(edge, C, vis, n, 1-c, y, x) ;
        }
        else if( C[y] == C[x] ){
            flag = false ;
            return false ;
        }
    }
    return true ;
}
  
int main()
{
    ios_base::sync_with_stdio(false) ; cin.tie(NULL) ; cout.tie(NULL) ;
    
    int n, m ; cin >> n >> m ; 

    vector<vector<int>> edge(n+1) ;

    while( m-- )
    {
        int x, y; cin >> x >> y ;

        edge[x].push_back(y) ; edge[y].push_back(x) ;
    }
    vector <int> C(n+1,0) ;

    vector<bool> vis(n+1, false) ;

    if(dfs(edge, C, vis,  n, 0, 0, -1))
    {
        cout <<"YES" ;
    }    
    else{cout << "NO" ; }
}