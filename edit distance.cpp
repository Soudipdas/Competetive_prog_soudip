#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define mp make_pair


void solve() {
 	string s1,s2;
	cin>>s1>>s2;
	ll n1=s1.size();
	ll n2=s2.size();

	ll a[n2+1][n1+1];

	for(ll i=0;i<=n2;i++){
		for(ll j=0;j<=n1;j++){
		    if(i==0 && j==0){
			a[i][j]=0;
		    }
		    else if(i==0 && j>0){
			a[i][j]=j;
		    }
		    else if(i>0 && j==0){
			a[i][j]=i;
		    }
		    else if(s2[i-1]==s1[j-1]){
			a[i][j]=a[i-1][j-1];
		    }
		    else{
			a[i][j]=1+min(min(a[i][j-1],a[i-1][j]),a[i-1][j-1]);
		    }
		}
	}

	for(ll i=0;i<=n2;i++){
		for(ll j=0;j<=n1;j++){
		    cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<a[n1+1][n2+1]<<endl;
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

