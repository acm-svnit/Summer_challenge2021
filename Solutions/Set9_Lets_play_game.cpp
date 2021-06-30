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
    freopen("in00.txt", "r", stdin);
    freopen("out00.txt", "w", stdout);
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
const int N=1e5+7;
bool dp[N];
void solve(){
    int n,q;
    cin>>n>>q;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=1;i<N;i++){
        for(int j=0;j<n;j++){
            if(i-a[j]<0) continue;
            if(dp[i-a[j]]==0){
                dp[i]=1;
                break;
            }
        }
    }
    while(q--){
        int k;
        cin>>k;
        if(dp[k]) puts("Harsh");
        else puts("Manish");
    }
}
int main(){
    input_();
    ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0); 
	int t=1;
	//cin>>t;
	while(t--) 
	    solve();
	return 0; 
}
/*
*/