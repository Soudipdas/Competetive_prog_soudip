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

    ll maxe=0;
    ll maxs=INT_MIN;
    for(ll i=0;i<n;i++){
        maxe+=a[i];
        if(maxs<maxe)
            maxs=maxe;
        if(maxe<0)
            maxe=0;
    }
    cout<<maxs<<endl;

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

