class Solution {
public:
    int dp[1001][1001];
    int help(string& s,int l,int r){
        if(l>r){
            return 0;
        }
        if(l==r){
            return 1;
        }
        if(dp[l+1][r+1]!=-1){
            return dp[l+1][r+1];
        }
        if(s[l]==s[r]){
            return dp[l+1][r+1]=2+help(s,l+1,r-1);
        }
        return dp[l+1][r+1]=max(help(s,l,r-1),help(s,l+1,r));
    }
    int longestPalindromeSubseq(string s) {
        memset(dp,-1,sizeof(dp));
        return help(s,0,s.size()-1);
    }
};
