Question

C. Basketball Exercise
Level -- 1400
Round 574(Div 2)

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define mp make_pair
#define pb push_back
int mod=1e9+7;

ll dp[3][200005];

ll help(ll n,ll a[], ll b[], ll ch){
    if(n<=0){
        return 0;
    }
    
    
    if(ch==0){
        if (dp[0][n]!=-1)
            return dp[0][n];
        return dp[0][n]=max(help(n-1,a,b,0),max(help(n-1,a,b,1)+a[n-1],help(n-1,a,b,2)+b[n-1]));
    }
    if(ch==1){
        
        if (dp[1][n]!=-1)
            return dp[1][n];
        return dp[1][n]=max(help(n-1,a,b,0),help(n-1,a,b,2)+b[n-1]);
    }
    
    if(ch==2){
        
        if (dp[2][n]!=-1)
            return dp[2][n];
        return dp[2][n]=max(help(n-1,a,b,0),help(n-1,a,b,1)+a[n-1]);
    }
    return 0;
}

void solve(){
    
    ll n;
    cin>>n;
    ll a[n],b[n];
    for(ll i=0;i<n;i++){
        cin>>a[i];
    }
    
    for(ll i=0;i<n;i++){
        cin>>b[i];
    }
    memset(dp,-1,sizeof(dp));
    help(n,a,b,0);

    cout<<dp[0][n]<<endl;
}

int main(){

    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t=1;
    //cin>>t; 
    while (t--){
        solve();
    }
}
