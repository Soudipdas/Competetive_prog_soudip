  public:
  
    int rec(int a[],int n,int sum,vector<vector<int>>& dp){
        if(sum==0){
            dp[n][sum]=1;
            return 1;
        }    
        if(n==0 && sum!=0){
            dp[n][sum]=0;
            return 0;
        }
        if(dp[n][sum]!=-1){
            return dp[n][sum];
        }
        if(a[n-1]>sum){
            dp[n][sum]=rec(a,n-1,sum,dp);
            return dp[n][sum];
        }
        dp[n][sum]=rec(a,n-1,sum,dp)||rec(a,n-1,sum-a[n-1],dp);
        return dp[n][sum];
    }
    
    
    
	int minDifference(int a[], int n)  { 
	    
	    int sum=0;
        for(int i=0;i<n;i++)
            sum+=a[i];
            
        if(n==1){
            return sum;
        }
        
        vector<vector<int> >dp(n+1,vector<int>((sum)+1,-1));
        
        for(int i=0;i<=n;i++){
            dp[i][0]=1;
        }
        for(int i=1;i<=sum;i++){
            dp[0][i]=0;
        }
        bool q[sum+1];
        for(int i=1;i<=sum/2;i++)
            q[i]= rec(a,n,i,dp);
        /*
        for(int i=0;i<=n;i++){
            for(int j=0;j<=sum/2;j++){
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }
        */
	    int i;
	    for( i=sum/2; i>=0; i-- )
        {
            if(q[i]){
                break;
            }
        }
        return sum-(2*i) ;
	} 
};
