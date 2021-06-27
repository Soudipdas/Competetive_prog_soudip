class Solution {
public:
    int dp[1001][1001];
    int rec(string& a,string& b, int x,int y){
        if(x==0 || y==0){
            dp[x][y]=0;
            return 0;
        }    
        if(dp[x][y]!=-1){
            return dp[x][y];
        }
        if(a[x-1]==b[y-1]){
            return dp[x][y]=1+rec(a,b,x-1,y-1);
        }
        else
            return dp[x][y]=max(rec(a,b,x-1,y),rec(a,b,x,y-1));
    }
    
    
    int longestCommonSubsequence(string a, string b) {
        
        for(int i=0;i<=a.size();i++){
            for(int j=0;j<=b.size();j++){
                dp[i][j]=-1;
            }
        }
        return rec(a,b,a.size(),b.size());
    }
    
    
};
