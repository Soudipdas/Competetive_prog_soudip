#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define mp make_pair


void solve() {
	ll n;
	cin>>n;
	ll a[n];
	for(ll i=0;i<n;i++)
      	cin>>a[i];

	ll copyarr[n];
    	copyarr[0]=1;

   	for(ll i=0;i<n;i++){
		copyarr[i]=1;
		for(ll j=0;j<i;j++){
		    if(a[i]>a[j] && copyarr[i]<copyarr[j]+1){
			copyarr[i]=copyarr[j]+1;
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

