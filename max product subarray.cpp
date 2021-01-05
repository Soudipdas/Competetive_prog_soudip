#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define mp make_pair

void solve(){

    ll n;
    cin>>n;
    vector<int>a(n);
    for(ll i=0;i<n;i++)
        cin>>a[i];

    int cmax=a[0];
    int cmin=a[0];
    int ans=a[0];
    int pmax=a[0];
    int pmin=a[0];

    for(int i=1;i<n;i++){
        cmax=max(max(pmax*a[i],pmin*a[i]),a[i]);
        cmin=min(min(pmax*a[i],pmin*a[i]),a[i]);
        ans=max(ans,cmax);
        pmax=cmax;
        pmin=cmin;
    }
    cout<<ans<<endl;

}

int main(){


    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    //t=1;
    cin>>t;
    while(t--){
        solve();
    }
}

