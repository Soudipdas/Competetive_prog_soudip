class Solution{
    public:
    
    int dp[1001][1001];
    int maxm=0;
    int fin=0;
    
    int longestCommonSubstr (string s1, string s2, int n, int m)
    {
        
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                dp[i][j]=0;
            }
        }
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1]!=s2[j-1]){
                    dp[i][j]=0;
                }
                else{
                    dp[i][j]=dp[i-1][j-1]+1;
                    maxm=max(maxm,dp[i][j]);
                }
            }
        }
          
        return maxm;
    }
};
