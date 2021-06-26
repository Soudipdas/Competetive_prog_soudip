#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define mp make_pair


// Memoization DP
// A bit different from subset sum
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    
    int dp[1003][1003];
    
    int rec(int wt[],int n,int W,int val[]){
        
        if(n==0 || W==0){
            dp[n][W]=0;
            return 0;
        }
        if(dp[n][W]!=-1){
            return dp[n][W];
        }
        if(wt[n-1]>W){
            dp[n][W]=rec(wt,n-1,W,val);
            return dp[n][W];
        }
        dp[n][W]=max ( val[n-1]+ rec(wt,n-1,W-wt[n-1],val) , rec( wt,n-1,W,val));
        return dp[n][W]; 
        
    }
    
    int knapSack(int W, int wt[], int val[], int n) { 
       
       int sum=0;
       memset(dp,-1,sizeof(dp));
       return rec(wt,n,W,val);
    }
};


//Iterative DP
void solve() {
    ll n,tot;
    cin>>n>>tot;
    ll val[n];
    ll w[n];
    for(ll i=0;i<n;i++){
        cin>>w[i];
        cin>>val[i];
    }
    ll dp[n+1][tot+1];

    for(ll i=0;i<=n;i++){
        for(ll j=0;j<=tot;j++){
            if(i==0 || j==0){ 
                dp[i][j]=0;
            }
            else if(w[i-1]<=j){
                dp[i][j]=max ( max ( dp[i-1][j] , dp[i][j-1] ) ,  val[i-1] + dp[i-1][j- w[i-1] ]);
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }

    cout<<dp[n][tot]<<endl;
}



int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    t=1;
    //cin>>t;
    while(t--){
        solve();
    }
}

