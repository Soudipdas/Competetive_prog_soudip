class Solution {
public:
    int dp[301][5001];
    int rec(vector<int>& c,int n,int amt){
        if(amt==0){
            
            return 1;
        }
        if((n==0 && amt!=0) || amt<0){
            return 0;
        }
        if(dp[n][amt]!=-1){
            return dp[n][amt];
        }
        if(c[n-1]>amt){
            return dp[n][amt]=rec(c,n-1,amt);
        }
        return dp[n][amt]=rec(c,n-1,amt) + rec(c,n,amt-c[n-1]);
    }
    int change(int amt, vector<int>& c) {
        
        //dp[c.size()+1][amt];
        memset(dp,-1,sizeof(dp));
        int p=rec(c,c.size(),amt);
        
        return p;
    }
};
