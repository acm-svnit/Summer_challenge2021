#include <iostream>
using namespace std;

const int N = 3e5;
int a[N];

void solve(){
    int n;
    long long ans = 0;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<31;i++){
        int v = 1<<i;
        long long k=0;
        for(int j=0;j<n;j++)
            if(v&a[j])
                k++;
        ans += k*(k-1)/2;
    }
    cout<<ans<<"\n";
}

int main(){
    int t=1;
    cin>>t;
    while(t--)
        solve();
    return 0;
}