class Solution {
public:
    
    
    int dp[14][10005];
    int rec(vector<int>& c,int n,int amt){
        if(amt==0){
            dp[n][amt]=0;
            return 0;
        }    
        if(n==0 || amt<0){
            return 1e8;
        }
        if(dp[n][amt]!=-1){
            return dp[n][amt];
        }
        if(c[n-1]>amt){
            return dp[n][amt]=rec(c,n-1,amt);
        }
        return dp[n][amt]=min(rec(c,n-1,amt),1+rec(c,n,amt-c[n-1]));
    }
    
    int coinChange(vector<int>& c, int amt) {
        int n=c.size();
        memset(dp,-1,sizeof(dp));
        int p= rec(c,n,amt);
        
        if(p>=1e8){
            return -1;
        }
        return p;
    }
};
