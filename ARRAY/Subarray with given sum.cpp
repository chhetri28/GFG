#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{   int t;
    cin>>t;
    while(t--){
    ll n,s;
    cin>>n>>s;
    vector<int>v;
    ll val;
    for(int i = 0;i<n;i++)
    {
        cin>>val;
        v.push_back(val);
    }
    map<int,int>m;
    vector<int>v2;
    v2.push_back(0);
    ll temp = 0;
    for(int i = 0;i<n;i++)
    {
        temp+=v[i];
        v2.push_back(temp);
        m[temp] = i;
    }
    ll f=0;
    for(int i = 1;i<n+1;i++)
    {
        if(m.find(v2[i-1]+s)!=m.end())
        {
            cout<<i<<" "<<m[v2[i-1]+s]+1<<endl;
            f=1;
            break;
        }
    }
    if(f==0){
        cout<<"-1"<<endl;
    }
    }
}