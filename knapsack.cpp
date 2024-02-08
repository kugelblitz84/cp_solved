#include <iostream>
#include <string>
#include <cstring>
using namespace std;

long long int value[100000],weight[100000];
long long int dp[1000][100000];
long long int knap(int index,int rem_weight){
	if(index<0) return 0;
	if(dp[index][rem_weight]!=-1) return dp[index][rem_weight];
	if(rem_weight-weight[index]>=0){
		return dp[index][rem_weight]=max(knap(index-1,rem_weight),knap(index-1,rem_weight-weight[index])+value[index]);
	}else return dp[index][rem_weight]=knap(index-1,rem_weight);
}
void solve(){
	int n,w;
	cin>>n>>w;
	for(int i=0;i<n;i++){
		cin>>weight[i]>>value[i];
	}
	cout<<knap(n-1,w)<<endl;


}
int main() {
	memset(dp,-1,sizeof(dp));
    int t=1;
    //cin>>t;
    while(t--){
    	solve();
    }
    return 0;
}
