
#include<bits/stdc++.h>
#define ll long long int
#define F first
#define S second

using namespace std;
 
int main()
{
	int t;
	t=1;
	while(t--)
	{
		int n;
		cin>>n;
		int arr[n];
		for(int i=0;i<n;++i)
		cin>>arr[i];
		map<int,ll>mp;
		ll cnt=0;
		for(int i=0;i<n;++i)
		{
			int sz=0;
			int temp=arr[i];
			while(temp)
			{
				sz++;
				temp/=2;
			}
			mp[sz]++;
		}
		
		ll res=0;
		for(auto it:mp)
		{
			res+=((it.S)*(it.S-1)/2);
		}
		cout<<res<<"\n";
	}
        
 
 
 
        
        
}
