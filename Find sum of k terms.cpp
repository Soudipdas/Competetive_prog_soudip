ll dp[n]={0};

    for(ll i=0;i<k;i++){
        dp[0]+=a[i];
    }
    

    for(ll i=1;i<=n-k;i++){
        dp[i]=dp[i-1]+a[k+i-1]-a[i-1];
    }
