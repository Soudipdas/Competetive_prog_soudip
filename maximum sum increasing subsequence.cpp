#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define mp make_pair


//Variation of Longest Common Subsequence
//Criteria is to change longest possible subsequence to greatest sum generated

void solve() {
	ll n;
	cin>>n;
	ll a[n];
	for(ll i=0;i<n;i++)
        cin>>a[i];

    ll copyarr[n];

    for(ll i=0;i<n;i++)
        copyarr[i]=a[i];

    for(ll i=0;i<n;i++){
        for(ll j=0;j<i;j++){
            if(a[i]>a[j] && copyarr[i]<copyarr[j]+a[i]){
                copyarr[i]=copyarr[j]+a[i];
            }
        }
    }

    cout<<*max_element(copyarr,copyarr+n)<<endl;
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

