#include<bits/stdc++.h>
using namespace std;

//FINALLY DJIKTRA'S DONE

int main(){

    cout<<"Enter num_verti,num_edge,source_verti"<<endl;
    int n,edg,src;
    cin>>n>>edg>>src;
    vector<pair<int,int>>a[n+1];
    for(int i=0;i<edg;i++){
        cout<<"Enter u,v,wt "<<i<<endl;
        int u,v,wt;
        cin>>u>>v>>wt;
        a[u].push_back(make_pair(v,wt));
        a[v].push_back(make_pair(u,wt));
    }
    priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int>>>pq;
    vector<int>dis(n+1,INT_MAX);

    pq.push({0,src});
    dis[src]=0;

    while(!pq.empty()){
        int parent=pq.top().second;
        int dis_till_now=pq.top().first;
        pq.pop();

        for(int i=0;i<a[parent].size();i++){
            int child=a[parent][i].first;
            int child_dis=a[parent][i].second;
            if(dis[child]>dis_till_now+child_dis){
                dis[child] = dis_till_now + child_dis;
                pq.push({dis[child],child});
            }
        }
    }

    for(int i=0;i<=n;i++){
        if(dis[i]==INT_MAX)
            cout<<-1<<" ";
        else
            cout<<dis[i]<<" ";
    }
    cout<<endl;


}
