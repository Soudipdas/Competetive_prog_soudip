#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define mp make_pair

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
                dp[i][j]=max(max(dp[i-1][j],dp[i][j-1]),val[i-1]+dp[i-1][j-w[i-1]]);
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

