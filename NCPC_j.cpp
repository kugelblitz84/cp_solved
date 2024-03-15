#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

#define int long long
using namespace std;
int factorial[1000008];
const int MOD=1e9+7;

void fact(){
	factorial[0]=1;
	for(int i=1;i<1000008;i++){
		factorial[i]=(factorial[i-1]*i)%MOD;
	}
}
int binary_expo(int base,int power)
{
	if(power==0) return 1;
	int ret=binary_expo(base,power>>1);
	ret=(ret*ret)%MOD;
	if(power&1) return (ret*ret*base)%MOD;
	else return ret%MOD;
}

void solve(){
	int s,n,m;
	cin>>s>>n>>m;
	int k=s/n;
	int temp=binary_expo(factorial[n],m-k)%MOD;
	int ans=(factorial[s]*temp)%MOD;
	cout<<ans<<endl;
}
int32_t main(){
	int t;
	fact();
	cin>>t;
	while(t--) solve();
return 0;
}
