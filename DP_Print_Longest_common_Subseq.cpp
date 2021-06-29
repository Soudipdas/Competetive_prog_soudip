vector<int> longestCommonSubsequence(vector<int> a, vector<int> b) {

    int dp[1001][1002];
    int n=a.size();
    int m=b.size();
    for(int i=0;i<=n;i++){
        dp[i][0]=0;
    }
    
    for(int i=0;i<=m;i++){
        dp[0][i]=0;
    }
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i-1]==b[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    /*
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    */
    
    vector<int>v;
    int i=n;
    int j=m;
    while(i>0 && j>0){
        if(a[i-1]==b[j-1]){
            v.push_back(a[i-1]);
            i--;
            j--;
        }
        else{
            if(dp[i-1][j]>dp[i][j-1]){
                i--;
            }
            else 
                j--;
        }
    }
    reverse(v.begin(),v.end());
    return v;
}
