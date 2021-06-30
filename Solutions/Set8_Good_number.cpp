#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define pb push_back
#define ff first
#define ss second
typedef pair<int,int> pp;
bool com(pp x,pp y){
    if(x.ff==y.ff) return x.ss<y.ss;
    return x.ff<y.ff;
}
void input_(){
    freopen("in09.txt", "r", stdin);
    freopen("out09.txt", "w", stdout);
}
ll power(ll x,ll y){
    ll prod=1;
    while(y){
        if(y&1) prod=(prod*x)%mod;
        x=(x*x)%mod;
        y/=2;
    }
    return prod;
}
const int N=1e7+7;
int dp[N];
void pre(){
    dp[0]=0;
    dp[1]=1;
    for(int i=2;i<N;i++) dp[i]=i;
    for(int i=2;i<N;i++){
        if(dp[i]==i){
            for(int j=i;j<N;j+=i){
                dp[j]-=(dp[j]/i);
            }
        }
    }
}
void solve(){
    int a,b;
    cin>>a>>b;
    b/=__gcd(a,b);
    cout<<dp[b]<<"\n";
}
int main(){
    pre();
    input_();
    ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0); 
	int t=1;
	cin>>t;
	while(t--) 
	    solve();
	return 0; 
}
/*
3 6 9 12 15
5 10
*/