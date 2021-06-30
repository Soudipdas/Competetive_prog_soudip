class Solution{

	public:
	int minOperations(string s1, string s2) 
	{ 
	    // Your code goes here
	    int n=s1.size();
	    int m=s2.size();
	    int dp[n+1][m+1];
	    
	    for(int i=0;i<=n;i++)
	        dp[i][0]=0;
	    for(int j=0;j<=m;j++)
	        dp[0][j]=0;
	    
	    for(int i=1;i<=n;i++){
	        for(int j=1;j<=m;j++){
	            if(s1[i-1]==s2[j-1]){
	                dp[i][j]=1+dp[i-1][j-1];
	            }
	            else{
	                dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
	            }
	        }
	    }
	    return ((n-dp[n][m])+(m-dp[n][m]));
	} 
};
