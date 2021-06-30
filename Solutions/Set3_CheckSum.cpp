#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    long long arr[1000000];
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i=0;i<n;i++)cin>>arr[i];

        sort(arr,arr+n);

        int fp=0,bp=n-1;
        long long pr=n,checksum=0;

        while(fp<=bp){
            checksum += arr[bp--] * pr--;
            if(fp>bp)break;
            checksum -= arr[fp++] * pr--;
        }
        cout<<checksum<<"\n";
    }
}