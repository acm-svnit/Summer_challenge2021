#include <iostream>
using namespace std;

int main(){
    int t;
    long long n,m,k,l,ans;
    cin>>t;
    while(t--){
        cin>>n>>m>>k;
        if(m==1)l = n+1;
        else{
            l = k*m/(m-1);
        }
        ans=0;
        while(n>=l){
            ans++;
            n/=m;
        }
        ans+=n/k + ((n%k==0)?0:1);
        cout<<ans<<"\n";
    }
    return 0;
}