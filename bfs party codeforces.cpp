#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define mp make_pair
vector<vector<ll> >a;

//s is the start pint of bfs
//v+1 is the limit of vertices
int bfs(ll s,ll v){
    bool vis[v+1];
    ll level[v+1]={0};
    for(ll i=0;i<=v;i++)
        vis[i]=false;
    queue<ll>q;
    q.push(s);
    while(!q.empty()){
        s=q.front();
        q.pop();
        for(ll i=0;i<a[s].size();i++){
            ll b=a[s][i];
            if(!vis[b]){
                q.push(b);
                level[b]=level[s]+1;
                vis[b]=true;
            }
        }
    }
    return *max_element(level,level+v+1);

}

void solve(){
    ll n;
    cin>>n;
    a.resize(n+1);
    for(ll i=1;i<=n;i++){
        ll u;
        cin>>u;
        if(u!=-1){
            a[i].push_back(u);
            a[u].push_back(i);
        }
        else{
            a[0].push_back(i);
        }
    }
    cout<<bfs(0,n+1);


}

int main(){
	solve();
}
