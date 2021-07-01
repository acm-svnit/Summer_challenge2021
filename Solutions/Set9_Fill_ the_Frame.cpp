#include<bits/stdc++.h>
#define ll long long int
#define pb push_back
#define pf push_front
#define vi vector 
#define ff first
#define ss second
#define fastio ios_base::sync_with_stdio(false) ; cin.tie(NULL) ; cout.tie(NULL) ;
#define MX 1000000007
const int p = 2e5+2 ;
const int inf = 1e9 ;
const ll mod = 1e9 + 7 ;
using namespace std  ;
 
int mem[1<<10][10][10] ;
int rec(int i, int j, int bm, const vector <string> &r, int N, int M){
    if ( i==N ) return 0;
    if (mem[bm][j][i] > -1) return mem[bm][j][i];
 
    // If the current cell is blocked, just keep recursing
    if (r[i][j] == '1') return rec( i+(j+1)/M, (j+1)%M, bm&~(1<<j), r, N, M );
 
    // Try adding a vertical clay in the current cell
    int vertical = rec( i+(j+1)/M, (j+1)%M, bm | (1<<j), r, N, M );
    // If the cell above is not also vertical, this is a new clay
    if ( (bm & 1<<j) == 0 )
      vertical++;
    
    // Try adding a horizontal clay
    int horizontal = rec( i+(j+1)/M, (j+1)%M, bm&~(1<<j),  r, N, M );
    // If the previous cell is not also horizontal, this is a new clay
    if ( j==0 || r[i][j-1]=='1' || (bm & 1<<(j-1))!=0 )
      horizontal++;
      
    return mem[bm][j][i] = min(vertical, horizontal);        
}
int Frame(vector <string> frame){
    
    memset(mem,-1,sizeof(mem));
    int ret = rec(0, 0, 0, frame, frame.size(), frame[0].size());
    return ret;
}
  
int main()
{
    ios_base::sync_with_stdio(false) ; cin.tie(NULL) ; cout.tie(NULL) ;
    
    memset(mem, -1, sizeof(mem)) ;
    
    int n, m ; cin >> n >> m ;
    
    vector<string> frame ;
    
    while( n-- )
    {
        string s; cin >> s ; frame.push_back(s) ;
    }
    cout << Frame(room) ;
}