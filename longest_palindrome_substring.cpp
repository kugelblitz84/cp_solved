class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        bool dp[n+1][n+1];
        memset(dp,false,sizeof(dp));
        int max_length=0,start=0;
        for(int i=0;i<n;i++){
            dp[i][i]=true;
            if(s[i]==s[min(i+1,n-1)]) dp[i][min(i+1,n-1)]=true;
            if(i and s[i-1]==s[i+1]) dp[i-1][i+1]=true;
        }
        for(int diff=1;diff<n-1;diff++){
            for(start=1;start+diff+1<n;start++){
                if(dp[start][start+diff] and s[start-1]==s[start+diff+1]) dp[start-1][start+diff+1]=true;
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(dp[i][j] and max_length<j-i+1){
                    max_length=j-i+1;
                    start=i;
                }
            }
        }
        return s.substr(start,max_length);
    }

private:
    
};
