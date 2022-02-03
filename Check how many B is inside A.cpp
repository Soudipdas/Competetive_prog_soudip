
vector<vector<int>>dp(105,vector<int>(105,-1));

int help(string a,string b,int n,int m){
    if((n==0 && m==0) || m==0)
        return 1;
    if(n==0){
        return 0;
    }
    if(dp[n][m]!=-1){
        return dp[n][m];
    }
    if(a[n-1]==b[m-1]){
        return dp[n][m]=help(a,b,n-1,m-1)+help(a,b,n-1,m);
    }
    return dp[n][m]=help(a,b,n-1,m);
}
