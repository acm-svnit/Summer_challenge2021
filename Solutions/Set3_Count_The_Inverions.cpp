#include<bits/stdc++.h>
    #define pb push_back
    using namespace std;
   
        int main()
        {
                int n,q;
                scanf("%d %d",&n,&q);
                
                        int arr[n];
                        for(int i=0;i<n;++i) scanf("%d",&arr[i]);
     
                        
                        int co=0;
                       
                        int dpmax[n][n];
                        for(int i=0;i<n;++i)
                        {
                            for(int j=0;j<n;++j)
                            {
                                if(arr[j]>arr[i])
                                {
                                    dpmax[i][j]=1;
                                    if(j<i)
                                    co++;
                                }
                                else
                                dpmax[i][j]=0;
 
                                if(j!=0)
                                dpmax[i][j]+=dpmax[i][j-1];
                            }
                        }

                       

                        while(q--)
                        {
                            int l,r;
                            cin>>l>>r;

                            if(l>r)
                            swap(l,r);

                            
                            --l,--r;
                            int temp=co;
                            temp+=2*(dpmax[l][r]-dpmax[l][l]);
                            temp-=2*(dpmax[r][r]-dpmax[r][l]);


                            if(l!=r)           
                            temp--;
                                       
                            cout<<temp<<"\n";
                        }
                      
         
                      
                        
                        
                        
                
                
                
                
        }
