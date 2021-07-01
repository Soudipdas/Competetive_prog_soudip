class Solution {
	public:
		int LongestRepeatingSubsequence(string a){
		    // Code here
		    string b=a;
		    int n=a.size();
		    int dp[n+1][n+1];
		    for(int i=0;i<=n;i++)
		        dp[i][0]=0;
		    for(int i=0;i<=n;i++)
		        dp[0][i]=0;
		        
		    for(int i=1;i<=n;i++){
		        for(int j=1;j<=n;j++){
		            if(a[i-1]==b[j-1] && i!=j) // Point of change 
		                dp[i][j]=1+dp[i-1][j-1];
		            else
		                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
		        }
		    }
		    return dp[n][n];
		    
		}
};
