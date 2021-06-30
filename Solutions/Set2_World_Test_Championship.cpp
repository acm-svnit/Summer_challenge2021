#include<bits/stdc++.h>
using namespace std;
int main()
{
        int n;
        cin>>n;
        int m;
        cin>>m;
        int a[n];

        for(auto &i:a) cin>>i;
        int arr[200]={0};
        for(auto it:a)
        arr[it-1]++;
        
        int num;
        for(int i=0;i<200;++i)
        {
                if(m>=arr[i])
                m-=arr[i];
                else
                {
                        num=i;
                        break;
                }
        }
        vector<int>res;
        for(auto it:a)
        {
                int ind=it-1;
                if(ind<num)
                continue;
                else
                {
                        if(ind>num)
                        res.push_back(it);
                        else
                        {
                                if(m>0)
                                m--;
                                else
                                res.push_back(it);
                        }

                }
        }
		if(res.empty())
		{
			cout<<-1<<"\n";
			return 0;
		}
        for(auto it:res)
        {
                
                cout<<it<<" ";
        }
}
