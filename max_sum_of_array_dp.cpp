#include <bits\stdc++.h>
#define int long long
using namespace std;

void solve(){
    int n;
    cin>>n;
    int a[n+1];
    a[0]=0;
    vector<int> dyn1(n+1), dyn2(n+1);
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];  
        dyn2[i]=dyn2[i-1]+a[i];
        dyn1[i]=max(dyn1[i-1]+a[i],abs(dyn2[i-1]+a[i]));
    }
    cout<<dyn1[n]<<endl;
}
int32_t main(){
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}
