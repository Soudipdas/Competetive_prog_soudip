class Solution{
public:
    
    
    int dp[1001][1001];
    
    int rec(int n,int w,int val[],int wt[]){
        
        if(n==0 || w==0){
            //dp[n][w]=0;
            return 0;
        }
        
        if(dp[n][w]!=-1){
            return dp[n][w];
        }
        if(wt[n-1]>w){
            dp[n][w]=rec(n-1,w,val,wt);
            return dp[n][w];
        }
        dp[n][w]= max(val[n-1]+rec(n,w-wt[n-1],val,wt), rec(n-1,w,val,wt)); //Point of change from normal knapsack
        return dp[n][w];
    }
    
    int knapSack(int n, int w, int val[], int wt[]){
        for(int i=0;i<=n;i++){
            for(int j=0;j<=w;j++){
                dp[i][j]=-1;
            }
            
        }
        return rec(n,w,val,wt);
    }
};
