#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
int main() {
 
     ll n,b;
     cin>>n>>b;
     ll maxi=-1;
     vector<ll>p;
     unordered_map<ll,int>ma;
     if(b%2==0)
     p.push_back(2);
     ll temp=b;
     while(b%2==0)
     b/=2,ma[2]+=1;
     for(ll i=3;i<=sqrt(b);++i)
     {
         if(b%i==0)
         p.push_back(i);
         while(b%i==0)
         b/=i,ma[i]+=1;
     }
     if(b>2)
     p.push_back(b),ma[b]+=1;
     
     ll mini=2000000000000000000;
     for(auto it:p)
     {
         ll c=1;
         ll ans=0;
         while(n/(pow(it,c)))
         ans+=(n/pow(it,c)),c++;
 
         mini=min(mini,ans/ma[it]);
     }
 
     cout<<mini<<"\n";
    
}
