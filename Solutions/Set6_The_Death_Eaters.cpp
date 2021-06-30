#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define pb push_back
#define ff first
#define ss second
typedef pair<int,int> pp;

const int N=2e5+7;
void solve(){
    int n;
    cin>>n;
    int a[n];
    queue<int> q;
    for(int i=0;i<n;i++){
        cin>>a[i];
        q.push(a[i]);
    }
    queue<int> pq;
    int ans=0;
    while(n>1){
        bool flag=0;
        int last=-1;
        while(q.size()){
            if(q.front()<last){
                flag=1;
            }
            else pq.push(q.front());
            last=q.front();
            q.pop();
        }
        while(pq.size()) q.push(pq.front()),pq.pop();
        if(!flag) break;
        ans++;
    }
    cout<<ans<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0); 
	int t=1;
	while(t--) 
	    solve();
	return 0; 
}
