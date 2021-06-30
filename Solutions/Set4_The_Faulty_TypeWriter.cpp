
#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
        
        int n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        map<char,int>mp;
        for(int i=0;i<k;++i)
        {
                char x;
                cin>>x;
                mp[x]++;
        }

        ll ans=0;
        for(int i=0;i<n;)
        {
                ll cnt=0;
                while(i<n && (mp[s[i]]==0))
                i++,cnt++;
                ans+=(cnt*(cnt+1)/2);

                while(i<n && (mp[s[i]]==1))
                i++;

        }

        cout<<ans<<"\n";

        


        
}
