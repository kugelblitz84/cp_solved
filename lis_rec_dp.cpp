class Solution {
public:
int dp[1000000];
	int lis(int n,vector<int> &a){
	if(dp[n]!=-1) return dp[n];
	int ans=1;//if no other element is smaller than a[n] that comes before n then return length 1;
  // if the sequence ends at n and i comes before n and a[i] < a[n] then a[i] has the chance to be in the final subsequence;
	for(int i=0;i<n;i++){ //iterating through all possible i that can be in the subsequence;
		if(a[i]<a[n]){
			ans=max(ans,lis(i,a)+1);  //taking the max overall possibilities;
		}
	}
	return dp[n]=ans;
}
    int lengthOfLIS(vector<int>& nums) {
			memset(dp,-1,sizeof(dp));
			int ans=1;
			for(int i=nums.size()-1;i>=0;i--){
				ans=max(ans,lis(i,nums)); 
  }
  return ans;
		} 
};
