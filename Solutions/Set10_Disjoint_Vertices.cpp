#include <bits/stdc++.h>
using namespace std;

pair<int,int> getset(vector<int>* g,int u,int p){
    pair<int,int> ans = make_pair(1,0);
    pair<int,int> temp;
    for(auto v:g[u]){
        if(v==p)continue;
        temp = getset(g,v,u);
        ans.first += temp.second;
        ans.second += max(temp.first,temp.second);
    }
    return ans;
}

int main(){
    int n, m, l, r;
    cin>>n;
    vector<int> g[n];
    for(int i=0;i<n-1;i++){
        cin>>l>>r;
        l--;r--;
        g[l].push_back(r);
        g[r].push_back(l);
    }
    pair<int,int> ans = getset(g,0,0);
    cout<<max(ans.first,ans.second)<<"\n";
}