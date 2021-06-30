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
    freopen("sample.txt", "r", stdin);
    freopen("sampleo.txt", "w", stdout);
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
const int N=2e5+7;
void solve(){
    int n;
    cin>>n;
    map<ll,ll> mp;
    ll a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vector<ll> pre(n+1,0);
    sort(a,a+n);
    for(int i=0;i<n;i++){
        pre[i+1]=pre[i]+a[i];
        mp[a[i]]=max(mp[a[i]],pre[i+1]);
    }
    ll ans=1;
    for(auto v:mp){
        if(ans>=v.ff&&ans<=v.ss){
            ans=v.ss+1;
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
    cin>>t;
    while(t--) 
        solve();
    return 0; 
}