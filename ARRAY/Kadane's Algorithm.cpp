#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        int cs=0,ms=0;
        for(int i=0;i<n;i++){
            cs=cs+a[i];
            if(cs<0){
                cs=0;
            }
            ms=max(cs,ms);
        }
        if(ms!=0)
        {
        cout<<ms<<" "<<endl;
        }
        else{
            cout<<a[0]<<endl;
        }
    }
}