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
    freopen("in08.txt", "r", stdin);
    freopen("out08.txt", "w", stdout);
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
    string s;
    cin>>s;
    int n=s.length()-1;
    int ans=0;
    while(n>0){
        if(s[n]=='0'){
            ans++;
            n--;
        }
        else{
            ans++;
            while(n>=0&&s[n]=='1') ans++,n--;
            if(n>=0) s[n]='1';
        }
    }
    cout<<ans;
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