#include <bits/stdc++.h>
using namespace std;

long long P10[111];
map<pair<int,int>, pair<long long,int>> go(vector<int> a, int isLeft) {
    map<pair<int,int>, pair<long long,int>> res;
    int n = a.size();
    for (int m = 0; m < 1<<a.size(); ++m) {
        long long s1 = 0;
        long long s2 = 0;
        int c1 = 0;
        int c2 = 0;
        for (int i = 0; i < a.size(); ++i) {
        if (m>>i&1) {
            s2 = 10ll*s2+a[i];
            c2++;
        } else {
            s1 = 10ll*s1+a[i];
            ++c1;
        }
        }
        if (isLeft) {
        s1 *= P10[n-c1];
        s2 *= P10[n-c2];
        }
        if (!res.count(make_pair(c1,c2)) || res[make_pair(c1,c2)].first < s1+s2) {
        res[make_pair(c1,c2)] = make_pair(s1+s2, m);
        }
    }
    return res;
};

int main(){
    long long P10[19];
    P10[0]=1;
    for (int i = 1 ; i < 19; ++i) P10[i]=10ll * P10[i-1];
    
    int n;
    cin>>n;
    n/=2;
    string s;
    cin>>s;

    map<pair<int,int>, pair<long long,int>> L,R;
    vector<int> a,b;

    for (int i = 0; i < s.size(); ++i) {
        if (i<n) a.push_back(s[i]-'0');
        else b.push_back(s[i]-'0');
    }
    L = go(a,1);
    R = go(b,0);

    int m1,m2;
    long long best = -1;
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= n; ++j) {
            if (i+j==n) {
                long long v = L[make_pair(i,j)].first + R[make_pair(n-i,n-j)].first;
                if (v>best) {
                best = v;
                m1 = L[make_pair(i,j)].second;
                m2 = R[make_pair(n-i,n-j)].second;
                }
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        if (m1>>i&1) printf("A");
        else printf("B");
    }
    for (int i = 0; i < n; ++i) {
        if (m2>>i&1) printf("A");
        else printf("B");
    }
    printf("\n");
}