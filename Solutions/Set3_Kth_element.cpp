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
    freopen("in02.txt", "r", stdin);
    freopen("out02.txt", "w", stdout);
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
const int N=2e5+1;
ll countofnumber(int n,ll *a,int k){
    ll cnt=0;
    for(int i=0;i<n;i++){
        ll rem=k-a[i];
        int j=upper_bound(a,a+n,rem)-a;
        j--;
        if(j>=i) cnt+=(j-i+1);
    }
    return cnt;
}
void solve(){
    int n;
    ll k;
    cin>>n>>k;
    ll a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a,a+n);
    ll l=2*a[0],r=2*a[n-1],ans=2*a[n-1]+1;
    while(l<=r){
        ll mid=(l+r)/2;
        ll cnt=countofnumber(n,a,mid);
        if(cnt<k) l=mid+1;
        else{
            r=mid-1;
            ans=min(ans,mid);
        }
    }
    cout<<ans<<"\n";
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