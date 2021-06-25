class Solution{
public:

    int dp[100][20000];
    int rec(int a[],int n,int sum){
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
            dp[n][sum]=rec(a,n-1,sum);
            return dp[n][sum];
        }
        dp[n][sum]=rec(a,n-1,sum)||rec(a,n-1,sum-a[n-1]);
        return dp[n][sum];
    }
    
    int equalPartition(int n, int a[]){
        
        int sum=0;
        for(int i=0;i<n;i++)
            sum+=a[i];
        if(sum%2!=0){
            return 0;
        }
        memset(dp,-1,sizeof(dp));
        
        for(int i=0;i<=n;i++){
            dp[i][0]=1;
        }
        for(int i=1;i<=sum;i++){
            dp[0][i]=0;
        }
        bool q[sum+1];
        for(int i=1;i<=sum/2;i++)
            q[i]= rec(a,n,i);
        
        
        for(int i=0;i<=n;i++){
            for(int j=0;j<=sum/2;j++){
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }
        return q[(sum/2)+1];
    }
};
