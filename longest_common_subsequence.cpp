#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define mp make_pair


void solve() {
    string a,b;
    cin>>a>>b;
    ll sizea=a.size();
    ll sizeb=b.size();
    ll mat[sizea+1][sizeb+1];

    for(ll i=0;i<=sizea;i++){
        for(ll j=0;j<=sizeb;j++){
            if(i==0 || j==0){
                mat[i][j]=0;
            }
            else if(a[i-1]==b[j-1]){
                mat[i][j]=1+mat[i-1][j-1];
            }
            else{
                mat[i][j]=max(mat[i-1][j],mat[i][j-1]);
            }
        }
    }

    cout<<mat[sizea][sizeb]<<endl;

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

